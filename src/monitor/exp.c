#include <arch/exp.h>
#include <errno.h>


/**********************************************************************
 * data
 **********************************************************************/

// expansion devices list
expansion_t devices[16];

// settings list
setting_t   settings[16];


/**********************************************************************
 * functions
 **********************************************************************/

void exp_init()
{
    // detect expansion hardware

    exp_setup(devices, settings);
}
