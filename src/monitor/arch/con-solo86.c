#include <arch/console.h>
#include <arch/pio.h>
#include <arch/solo86/ports.h>


/**********************************************************************
 * functions
 **********************************************************************/

void con_setup()
{
    // no-op
}

void con_putc(char c)
{
    outb(c, CON_DATA);
}

char con_getc()
{
    if (inb(CON_CTRL) & 0x01)
        return (inb(CON_DATA));

    return (0);
}

