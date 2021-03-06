#ifndef FE_CHATTER_H
#define FE_CHATTER_H

// Header purpose:
// Handling of random phrases sent in chat

#include "libdiscord.h"
#include <time.h>

struct fe_chatter_info
{
	struct timespec tick;
	clock_t itvl;

	char** phrases;
	size_t phrases_sz;
};

extern const char phrase_fpath[];


// Description:
// Called before main loop to initialize chatter info structure.
// Arguments:
//	info - pointer to info structure.
// Return values:
// 	0 - OK, info structure was initialized.
//	1 - couldn't read phrases file.
//	2 - not enough memory to store all the phrases.
int fe_chatter_init(struct fe_chatter_info* info);


// Description:
// Sends a random phrase to specified channel.
// Arguments:
//	info - pointer to info structure.
//	context - pointer to discord context structure.
//	channel_id - id of channel to send message in.
void fe_chatter_chatrandom(struct fe_chatter_info* info, struct ld_context* context,
				uint64_t channel_id);

// Description:
// Called within main callback (in fe_client.c) to roll a random phrase to be written in chat.
// Uses clock_t info and pseudo-RNG to determine intervals.
// Arguments:
//	info - pointer to info structure.
//	context - pointer to discord context structure.
//	channel_id - id of channel last message was sent in.
void fe_chatter_tick(struct fe_chatter_info* info, struct ld_context* context,
			uint64_t channel_id);

#endif
