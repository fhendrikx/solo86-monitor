#ifndef __arch_console__
#define __arch_console__

#include <arch/types.h>

void con_setup(void);
void con_putc(char);
char con_getc();

#endif
