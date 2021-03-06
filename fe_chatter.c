#include "fe_chatter.h"
#include "fe_config.h"
#include "fe_client.h"

const char phrase_fpath[] = "phrases";

int fe_chatter_init(struct fe_chatter_info* info)
{
	clock_gettime(CLOCK_REALTIME, &info->tick);
	info->itvl = rand() % (fe_config.chatter_itvl_max - fe_config.chatter_itvl_min + 1)
			     + fe_config.chatter_itvl_min;

	FILE* phrasefd = fopen(phrase_fpath, "r");
	if(!phrasefd)
		return 1;

	info->phrases = NULL;
	info->phrases_sz = 0;
	char* phr = NULL;
	size_t phr_sz = 0;
	while(getline(&phr, &phr_sz, phrasefd) != EOF)
	{
		info->phrases_sz++;
		char** tmp = realloc(info->phrases, info->phrases_sz * sizeof(char*));
		if(!tmp){
			if(info->phrases)
				free(info->phrases);
			fclose(phrasefd);
			return 2;
		}
		info->phrases = tmp;
		info->phrases[info->phrases_sz-1] = strdup(phr);
	}

	fclose(phrasefd);
}

void fe_chatter_tick(struct fe_chatter_info* info, struct ld_context* context)
{
	struct timespec spec;
	clock_gettime(CLOCK_REALTIME, &spec);

	if(spec.tv_sec * 1000 + spec.tv_nsec / 1000000
		>= info->tick.tv_sec * 1000 + info->tick.tv_nsec / 1000000 + info->itvl)
	{ // interval is passed, time to drop a phrase
		ld_send_basic_message(context, fe_config.main_channel,
					info->phrases[rand() % info->phrases_sz]);


		clock_gettime(CLOCK_REALTIME, &info->tick);
		info->itvl = rand() % (fe_config.chatter_itvl_max - fe_config.chatter_itvl_min + 1)
				     + fe_config.chatter_itvl_min;
	}
	else
		printf("Chatter cooldown: %lu\n",
			info->tick.tv_sec * 1000 + info->tick.tv_nsec / 1000000 + info->itvl - spec.tv_sec * 1000 + spec.tv_nsec / 1000000);
}
