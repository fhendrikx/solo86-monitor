#include <arch/console.h>


/**********************************************************************
 * functions
 **********************************************************************/

int con_fputc(char c)
{
    con_putc(c);

    return 0;
}

int con_fputs(const char *str)
{
    while (*str)
    {
        con_putc(*str++);
    }

    return 0;
}

void con_init()
{
    con_setup();
}
