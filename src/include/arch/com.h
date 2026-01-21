#ifndef __arch_com__
#define __arch_com__

#include <arch/types.h>

void com_setup(void);
void com_putc(char);
char com_getc();

#endif
