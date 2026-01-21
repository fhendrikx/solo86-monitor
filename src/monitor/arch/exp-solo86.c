#include <arch/exp.h>
#include <arch/pio.h>
#include <arch/solo86/ports.h>
#include <arch/string.h>


/**********************************************************************
 * functions
 **********************************************************************/

int exp_setup(expansion_t *devices, setting_t *settings)
{
    int i = 0;
    int j = 0;

    if (exp_detect(PIT_DETECT))
    {
        devices[i].type = EXP_TYPE_SYSTEM;
        devices[i].port = PIT_DETECT;

        strcpy(devices[i].name, (char *) "PIT");

        i++;
    }

    if (exp_detect(CON_DETECT))
    {
        devices[i].type = EXP_TYPE_CONSOLE;
        devices[i].port = CON_DETECT;

        strcpy(devices[i].name, (char *) "CON");

        i++;
    }

    if (exp_detect(PNL_DETECT))
    {
        devices[i].type = EXP_TYPE_SETTING;
        devices[i].port = PNL_DETECT;

        strcpy(devices[i].name, (char *) "PNL");

        i++;

        // settings

        unsigned char a = inb(PNL_DATA);

        if (a & EXP_SET_SND_EN)
        {
            settings[j].type = EXP_SET_SND_EN;
            settings[j].value = (a & EXP_SET_SND_EN);

            strcpy(settings[j].name, (char *) "SND_EN");
        }

        if (a & EXP_SET_APP_SELECT)
        {
            settings[j].type = EXP_SET_APP_SELECT;
            settings[j].value = (a & EXP_SET_APP_SELECT) >> 1;

            strcpy(settings[j].name, (char *) "APP_SELECT");
        }

        if (a & EXP_SET_APP_EN)
        {
            settings[j].type = EXP_SET_APP_EN;
            settings[j].value = (a & EXP_SET_APP_EN) >> 4;

            strcpy(settings[j].name, (char *) "APP_EN");
        }

        if (a & EXP_SET_COM_SELECT)
        {
            settings[j].type = EXP_SET_COM_SELECT;

            int x = (a & EXP_SET_COM_SELECT) >> 5;

            if      (x == 0)
            {
                settings[j].value = 115200;
            }
            else if (x == 1)
            {
                settings[j].value = 38400;
            }
            else if (x == 2)
            {
                settings[j].value = 9600;
            }
            else if (x == 3)
            {
                settings[j].value = 1200;
            }

            strcpy(settings[j].name, (char *) "COM_SELECT");
        }

        if (a & EXP_SET_COM_EN)
        {
            settings[j].type = EXP_SET_COM_EN;
            settings[j].value = (a & EXP_SET_COM_EN) >> 7;

            strcpy(settings[j].name, (char *) "COM_EN");
        }
    }

    if (exp_detect(ATA_DETECT))
    {
        devices[i].type = EXP_TYPE_DISK;
        devices[i].port = ATA_DETECT;

        strcpy(devices[i].name, (char *) "ATA");

        i++;
    }

    if (exp_detect(COM_DETECT))
    {
        devices[i].type = EXP_TYPE_CONSOLE;
        devices[i].port = COM_DETECT;

        strcpy(devices[i].name, (char *) "COM");

        i++;
    }

    return 0;
}

int exp_detect(word_t port)
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

