#ifndef FE_CLIENT_H
#define FE_CLIENT_H

// Header purpose:
// Collection of callbacks and constants used by bot client.

#include "libdiscord.h"


// Description: does some initialization for certain callback functions.
// Return values:
// 0 - OK, no errors.
// 1 - couldn't read phrases file
// 2 - not enough memory to store chatter phrases
int fe_cb_init();

// Description: general callback used by libdiscord.
int fe_cb_general(struct ld_context* context, enum ld_callback_reason reason, void* data, int len);

// Specific callbacks:
int fe_cb_msg_create(struct ld_context* context, struct ld_json_message* msg);

#endif
