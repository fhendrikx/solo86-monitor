#include <arch/device.h>
#include <errno.h>


/**********************************************************************
 * data
 **********************************************************************/

// expansion devices list
device_t    devices[16];

// settings list
setting_t   settings[16];


/**********************************************************************
 * functions
 **********************************************************************/

void dev_init()
{
    // detect devices and settings

    dev_setup(devices, settings);
}

