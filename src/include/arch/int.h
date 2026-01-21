#ifndef __arch_int__
#define __arch_int__

#include <arch/types.h>

void int_setup(void);
void int_set(word_t, word_t, seg_t);

#endif
