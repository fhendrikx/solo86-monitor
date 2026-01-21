#include <arch/console.h>


/**********************************************************************
 * functions
 **********************************************************************/

int putc(char c)
{
    con_putc(c);

    return 0;
}

int puts(const char *str)
{
    while (*str)
    {
        con_putc(*str++);
    }

    return 0;
}

char getc()
{
    return con_getc();
}

void gets(char *str)
{
    int i = 0;
    char c;

    do
    {
        c = con_getc();

        if      (c == 0x7F)
        {
            // DEL?

            if (i > 0)
            {
                con_putc(0x08);
                con_putc(0x20);
                con_putc(0x08);

                i--;
            }
        }
        else if (c != 0x00)
        {
            if (c == 0x0D)
            {
                // translate CR to LF

                c = 0x0A;
            }

            str[i++] = c;

            con_putc(c);
        }
    } while (c != 0x0A);

    str[i] = 0x00;
}

void con_init()
{
    con_setup();
}
