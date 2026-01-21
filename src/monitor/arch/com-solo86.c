#include <arch/console.h>
#include <arch/pio.h>
#include <arch/solo86/ports.h>


/**********************************************************************
 * functions
 **********************************************************************/

void com_setup()
{
    // FIXME
}

void com_putc(char c)
{
    unsigned char a;

    // wait for transmit buffer to be empty

    do
    {
        a = inb(COM_LSR) & 0x20;
    } while (a == 0);

    outb(c, COM_DATA);
}

char com_getc()
{
    if (inb(COM_LSR) & 0x01)
    {
        return (inb(COM_DATA));
    }

    return (0);
}

