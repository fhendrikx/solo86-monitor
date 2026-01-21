#include <arch/cpu.h>
#include <arch/pio.h>
#include <arch/types.h>

#include <libc/stdio.h>
#include <monitor/exp.h>
#include <monitor/irq.h>
#include <monitor/monitor.h>
#include <monitor/printk.h>
#include <monitor/system.h>
#include <monitor/version.h>


/**********************************************************************
 * data
 **********************************************************************/

char banner[6][40] = {
    " _____       _          _______   ____ ",
    "/  ___|     | |        / /  _  | / ___|",
    "\\ `--.  ___ | | ___   / / \\ V / / /___ ",
    " `--. \\/ _ \\| |/ _ \\ / /  / _ \\ | ___ \\",
    "/\\__/ / (_) | | (_) / /  | |_| || \\_/ |",
    "\\____/ \\___/|_|\\___/_/   \\_____/\\_____/"
};


/**********************************************************************
 * functions
 **********************************************************************/

void mon_banner()
{
    printk("%s\n%s\n%s\n%s\n%s\n%s\n\n",
            banner[0], banner[1], banner[2],
            banner[3], banner[4], banner[5]);

    printk("[ (c) 2026 Dylan Hall & Ferry Hendrikx ]\n\n");

    printk("%s Release %s; %s\n", SYS_NAME, SYS_RELEASE, SYS_VERSION);
    printk("Built with GCC %s @ %s\n", __VERSION__, SYS_BUILD);
}


/**********************************************************************
 * main
 **********************************************************************/

void monitor(void)
{
    char buffer[64];

    irq_init();
    exp_init();

    mon_banner();

    while (1)
    {
        gets(buffer);

        printk("you typed [%s]\n", buffer);
    }
}

