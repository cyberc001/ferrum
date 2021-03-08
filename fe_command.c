#include "fe_command.h"

#include <ctype.h>
#include "fe_client.h"
#include "fe_chatter.h"

struct fe_command fe_command_defs[4] = {
					{"$help", "- отобразить список команд", &fe_command_help},
					{"$ping", "- случайная фраза от Великого и Ужасного", &fe_command_ping},
					{"$man", "<страница> <название> - справка по функции\\команде (утилита man)", &fe_command_man},
					{"$decide", "[варианты ответа] - доверить свою судьбу Железняку и выбрать между несколькими вариантами ответа. Если не указывать варианты ответа, то будут выбор между \"да\" и \"нет\".", &fe_command_decide}
				       };

void fe_command_preprocess(struct ld_context* context, struct ld_json_message* msg)
{
	char** args = NULL;
	size_t args_sz = 0;

	int pflag = 0;
	int isquotes = 0;

	char comm_name[64];
	size_t comm_name_ind = 0;
	char arg_buf[128];
	size_t arg_buf_ind = 0;

	for(char* c = msg->content; *c && pflag >= 0; ++c)
	{
		switch(pflag)
		{
			case 0: // reading command name
			{
				while(isspace(*c) && *c) ++c;
				if(!*c) break;
				while(!isspace(*c) && *c){
					comm_name[comm_name_ind++] = *c;
					if(comm_name_ind >= sizeof(comm_name)/sizeof(comm_name[0]) - 1)
						{pflag = -1; goto scanend;}
					++c;
				}
				comm_name[comm_name_ind] = '\0';
				pflag = 1;
			} break;
			case 1: // reading an argument
			{
				while(isspace(*c) && *c) ++c;
				while( (isquotes || !isspace(*c)) && *c){
					if(*c == '\"')
						{isquotes = !isquotes; ++c; continue;}

					arg_buf[arg_buf_ind++] = *c;
					if(arg_buf_ind >= sizeof(arg_buf)/sizeof(arg_buf[0]) - 1)
						{pflag = -2; goto scanend;}
					++c;
				}
				arg_buf[arg_buf_ind] = '\0';

				++args_sz;
				char** tmp_pt = realloc(args, args_sz * sizeof(char*));
				if(!tmp_pt){
					pflag = -3;
					goto scanend;
				}
				args = tmp_pt;
				args[args_sz-1] = strdup(arg_buf);
				if(!args[args_sz-1]){
					--args_sz;
					pflag = -4;
					goto scanend;
				}

				arg_buf_ind = 0;
			}
		}
		scanend:
		if(!*c) break;
	}
	if(pflag == 0  // empty message
	|| pflag == -1 // exceeded message name buffer capacity
	|| pflag == -2 // exceeded argument buffer capacity
	|| pflag == -3 // cannot allocate dynamic memory for arguments array
	|| pflag == -4) // cannot allocate dynamic memory for an argument string
		goto return_cleanup;

	printf("%lu\n", args_sz);
	// NULL-terminating args array for easier usage with exec function family
	if(args)
	{
		char** tmp_pt = realloc(args, (args_sz+1)*sizeof(char*));
		if(!tmp_pt)
			goto return_cleanup;
		args = tmp_pt;
		args[args_sz] = NULL;
	}

	for(size_t i = 0; i < sizeof(fe_command_defs)/sizeof(fe_command_defs[0]); ++i)
	{
		if(!strcmp(fe_command_defs[i].comm, comm_name))
		{
			fe_command_defs[i].cb(args, args_sz, context, msg);
			break;
		}
	}

	return_cleanup:
	if(args){
		for(size_t i = 0; i < args_sz; ++i)
			free(args[i]);
		free(args);
	}
}


// Command message callback functions:

// $help
void fe_command_help(char** args, size_t args_sz, struct ld_context* context, struct ld_json_message* msg)
{
	char helpstr[1950];
	strcpy(helpstr, "```\n");
	for(size_t i = 0; i < sizeof(fe_command_defs)/sizeof(fe_command_defs[0]); ++i)
	{
		strncat(helpstr, fe_command_defs[i].comm, sizeof(helpstr)/sizeof(helpstr[0])-3);
		strcat(helpstr, " ");
		strncat(helpstr, fe_command_defs[i].help, sizeof(helpstr)/sizeof(helpstr[0])-3);
		strcat(helpstr, "\n");
	}
	strcat(helpstr, "```");
	ld_send_basic_message(context, msg->channel_id, helpstr);
}

// $ping
void fe_command_ping(char** args, size_t args_sz, struct ld_context* context, struct ld_json_message* msg)
{
	fe_chatter_chatrandom(&fe_client_chatterinfo, context, msg->channel_id);
}

// $man
void fe_command_man(char** args, size_t args_sz, struct ld_context* context, struct ld_json_message* msg)
{
	// Forming command string for shell
	size_t msgskip = 0; // discord message portions of input to skip
	char comm[2048];
	strcpy(comm, "man");
	if(args_sz >= 1){
		msgskip = strtol(args[0], NULL, 10);
	}
	for(size_t i = 1; i < args_sz; ++i){
		strcat(comm, " ");
		strncat(comm, args[i], sizeof(comm)/sizeof(comm[0]));
	}

	// Opening man process
	FILE* manpipe = popen(comm, "r");
	if(!manpipe){
		fprintf(stderr, "Can't open pipe for man command\n");
		return;
	}

	// Reading output from man
	char pipebuf[1950];
	size_t datacnt = 0;
	size_t msg_i = 0;
	while( (datacnt = fread(pipebuf + 5, sizeof(pipebuf[0]),
			sizeof(pipebuf)/sizeof(pipebuf[0])-1-8, manpipe)) != 0)
	{
		if(msg_i >= msgskip)
		{
			memcpy(pipebuf, "```c\n", 5);
			memcpy(pipebuf + 5 + datacnt, "```", 3);
			pipebuf[datacnt+3+5] = '\0';
			ld_send_basic_message(context, msg->channel_id, pipebuf);
			++msg_i; break; // to avoid displaying "no such page" message
		}
		++msg_i;
	}
	if(msg_i <= msgskip){
		ld_send_basic_message(context, msg->channel_id, "Таки-нет такой страницы.");
	}

	pclose(manpipe);
}

void fe_command_decide(char** args, size_t args_sz, struct ld_context* context, struct ld_json_message* msg)
{
	printf("%lu\n", args_sz);
	const char* result;
	if(args_sz == 0){
		result = rand() % 2 == 0 ? "Таки-да." : "Таки-нет.";
	}
	else{
		int r = rand() % args_sz;
		result = args[r];
	}

	ld_send_basic_message(context, msg->channel_id, result);
}
