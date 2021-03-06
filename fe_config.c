#include "fe_config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int fe_load_config(const char* fpath)
{
        FILE* confd = fopen(fpath, "r");
        if(!confd)
                return 1;

	// Reading line by line
	char linebuf[256];
	while(fgets(linebuf, sizeof(linebuf)/sizeof(linebuf[0]), confd))
	{
		char* linebuf_endl = strchr(linebuf, '\n');
		if(linebuf_endl) *linebuf_endl = '\0';

		char* assig_sign = strchr(linebuf, '=');
		if(!assig_sign)
			continue;
		size_t prop_ln = assig_sign - linebuf; // length of property string

		// Set list of properties
		if(!strncmp(linebuf, "token", prop_ln)){
			strncpy(fe_config.token, assig_sign+1,
					MIN(sizeof(fe_config.token), linebuf - assig_sign));
		}
		else if(!strncmp(linebuf, "main_channel", prop_ln)){
			fe_config.main_channel = strtoll(assig_sign+1, NULL, 10);
		}
		else if(!strncmp(linebuf, "chatter_interval_min", prop_ln)){
			fe_config.chatter_itvl_min = strtoll(assig_sign+1, NULL, 10);
		}
		else if(!strncmp(linebuf, "chatter_interval_max", prop_ln)){
			fe_config.chatter_itvl_max = strtoll(assig_sign+1, NULL, 10);
		}
	}

	// Finishing
        fclose(confd);
        return 0;
}

