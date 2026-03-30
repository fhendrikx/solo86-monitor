#include <arch/device.h>
#include <arch/pio.h>
#include <arch/solo86/ports.h>
#include <arch/string.h>


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

    devices[i].type = DEV_TYPE_SYSTEM;
    devices[i].port = 0;

    strcpy(devices[i].name, (char *) "BNK");

    i++;

    if (dev_detect(PIT_DETECT))
    {
        devices[i].type = DEV_TYPE_SYSTEM;
        devices[i].port = PIT_DETECT;

        strcpy(devices[i].name, (char *) "PIT");

        i++;

        devices[i].type = DEV_TYPE_SYSTEM;
        devices[i].port = 0;

        strcpy(devices[i].name, (char *) "RTC");

        i++;
    }

    if (dev_detect(CON_DETECT))
    {
        devices[i].type = DEV_TYPE_CONSOLE;
        devices[i].port = CON_DETECT;

        strcpy(devices[i].name, (char *) "CON");

        i++;
    }

    if (dev_detect(PNL_DETECT))
    {
        devices[i].type = DEV_TYPE_SETTING;
        devices[i].port = PNL_DETECT;

        strcpy(devices[i].name, (char *) "PNL");

        i++;

        // settings

        unsigned char a = inb(PNL_DATA);

        if (a & 0x01)
        {
            settings[j].type = DEV_SET_SND_EN;
            settings[j].value = (a & 0x01);

            strcpy(settings[j].name, (char *) "SND_EN");
        }

        if (a & 0x0E)
        {
            settings[j].type = DEV_SET_APP_SELECT;
            settings[j].value = (a & 0x0E) >> 1;

            strcpy(settings[j].name, (char *) "APP_SELECT");
        }

        if (a & 0x10)
        {
            settings[j].type = DEV_SET_APP_EN;
            settings[j].value = (a & 0x10) >> 4;

            strcpy(settings[j].name, (char *) "APP_EN");
        }

        if (a & 0x30)
        {
            settings[j].type = DEV_SET_COM_SELECT;
            settings[j].value = (a & 0x30) >> 5;

            strcpy(settings[j].name, (char *) "COM_SELECT");
        }

        if (a & 0x80)
        {
            settings[j].type = DEV_SET_COM_EN;
            settings[j].value = (a & 0x80) >> 7;

            strcpy(settings[j].name, (char *) "COM_EN");
        }
    }

    if (dev_detect(ATA_DETECT))
    {
        devices[i].type = DEV_TYPE_DISK;
        devices[i].port = ATA_DETECT;

        strcpy(devices[i].name, (char *) "ATA");

        i++;
    }

    if (dev_detect(COM_DETECT))
    {
        devices[i].type = DEV_TYPE_CONSOLE;
        devices[i].port = COM_DETECT;

        strcpy(devices[i].name, (char *) "COM");

        i++;
    }

    return 0;
}

int dev_detect(word_t port)
{
    unsigned char status = inb(port);

    // try the standard AA pattern

    if (status == 0xAA)
    {
        return 1;
    }

    // some expansion boards don't have the full 8-bits

    status &= 0xF8;

    return (status == 0xA8);
}

