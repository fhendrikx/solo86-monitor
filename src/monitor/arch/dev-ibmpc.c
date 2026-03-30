#include <arch/device.h>
#include <arch/pio.h>
#include <arch/solo86/ports.h>


/**********************************************************************
 * functions
 **********************************************************************/

int dev_setup(device_t *devices, setting_t *settings)
{
    int i = 0;
    int j = 0;

    // device defaults

    devices[i].type = DEV_TYPE_SYSTEM;
    devices[i].port = 0;

    strcpy(devices[i].name, (char *) "SYS");

    i++;

    // device detection

    if (dev_detect(PIT_DETECT))
    {
        devices[i].type = DEV_TYPE_SYSTEM;
        devices[i].port = PIT_DETECT;

        strcpy(devices[i].name, (char *) "PIT");

        i++;
    }

    return 0;
}

int dev_detect(word_t port)
{
    return 1;
}

