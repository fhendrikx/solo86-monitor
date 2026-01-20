#ifndef __arch_irq__
#define __arch_irq__

#include <arch/types.h>

void irq_setup(void);
void irq_enable(word_t irq);
void irq_disable(word_t irq);

#endif
