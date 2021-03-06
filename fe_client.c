#include "fe_client.h"
#include "fe_config.h"
#include "fe_chatter.h"

struct fe_chatter_info chatterinfo;

int fe_cb_init()
{
        int err = fe_chatter_init(&chatterinfo);
        if(err == 1)      return 1;
        else if(err == 2) return 2;

	return 0;

}

int fe_cb_general(struct ld_context* context, enum ld_callback_reason reason, void* data, int len)
{
	switch(reason)
	{
		case LD_CALLBACK_MESSAGE_CREATE:
		{
			struct ld_json_message msg;
			ld_json_message_init(&msg);
			ld_json_pack_message(&msg, (json_t*) data);
			return fe_cb_msg_create(context, &msg);
		}
		default: return 0;
	}
}


// Specfic callbacks

int fe_cb_msg_create(struct ld_context* context, struct ld_json_message* msg)
{
	if(msg->id != context->current_user->id){
		fe_chatter_tick(&chatterinfo, context);
	}
}
