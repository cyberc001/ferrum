#ifndef FE_COMMAND_H
#define FE_COMMAND_H

// Header purpose:
// Handling of textual commands

#include <stdlib.h>

#include "json.h"


// Command preprocessor called from message create callback:
void fe_command_preprocess(struct ld_context* context, struct ld_json_message* msg);

// Command message callback functions:
void fe_command_help(char**, size_t, struct ld_context*, struct ld_json_message*);
void fe_command_ping(char**, size_t, struct ld_context*, struct ld_json_message*);
void fe_command_man(char**, size_t, struct ld_context*, struct ld_json_message*);
void fe_command_decide(char**, size_t, struct ld_context*, struct ld_json_message*);

struct fe_command
{
	const char* comm;
	const char* help;
	void (*cb)(char** args, size_t args_sz, struct ld_context* context, struct ld_json_message* msg);
};
extern struct fe_command fe_command_defs[4];

#endif
