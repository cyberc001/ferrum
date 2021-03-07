#include <stdio.h>

#include "libdiscord.h"

#include "fe_client.h"
#include "fe_config.h"
#include "fe_chatter.h"

const char conf_fpath[] = "config";

int main()
{
	srand(time(NULL));

	// Loading configuration file
	int err = fe_load_config(conf_fpath);
	if(err == 1){
		fprintf(stderr, "Unable to open configuration file \"%s\"\n", conf_fpath);
		return 1;
	}

	// Initliazing library
	ld_set_logging_level(0);

	// Creaing context and connecting
	struct ld_context context;
	memset(&context, 0, sizeof(context));
	struct ld_context_info *info = malloc(sizeof(struct ld_context_info));
	ld_init_context_info(info);
		info->bot_token = fe_config.token;
		info->user_callback = &fe_cb_general;
		info->gateway_ringbuffer_size = 8;
		info->init_presence = NULL;
	CURL* hndl;
	if(ld_init_context(info, &context) != LDS_OK){
		fprintf(stderr, "Unable to create context, exiting.\n");
		return 2;
	}

	hndl = curl_easy_init();

	// Main loop
	err = fe_cb_init();
	if(err == 1){
		fprintf(stderr, "Couldn't read chatter phrases file \"%s\"\n", phrase_fpath);
		return 3;
	}
	else if(err == 2){
		fprintf(stderr, "Not enough memory to store chatter phrases.\n");
		return 4;
	}

	while(1)
	{
		err = ld_service(&context, 20);
		if(err != LDS_OK){
			fprintf(stderr, "Error %d\n", err);
		}
	}

	return 0;
}

