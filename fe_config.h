#ifndef FE_CONFIG_H
#define FE_CONFIG_H

// Header purpose:
// Collection of functions/structures used to get information from configuration file and store it.

#include <stdint.h>
#include <time.h>

struct
{
	char token[128];

	uint64_t main_channel;

	clock_t chatter_itvl_min; // in milliseconds
	clock_t chatter_itvl_max;

} fe_config;


// Description:
// Tries to load specified configuration file into the global configuration structure.
// Arguments:
//	fpath - path to configuration file.
//	conf - pointer to configuration structure.
// Return values:
//	0 - OK, configuration was opened and loaded.
//	1 - unable to open configuration file (doesn't exist, insufficient rights).
int fe_load_config(const char* fpath);

#endif
