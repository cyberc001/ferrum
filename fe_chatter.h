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
// Called within main loop (in main.c) to roll a random phrase to be written in chat.
// Uses clock_t info and pseudo-RNG to determine intervals.
// Arguments:
//	info - pointer to info structure.
//	context - pointer to discord context structure.
void fe_chatter_tick(struct fe_chatter_info* info, struct ld_context* context);

#endif
