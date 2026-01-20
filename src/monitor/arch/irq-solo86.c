#include <arch/cpu.h>
#include <arch/int.h>
#include <arch/pio.h>
#include <arch/types.h>
#include <arch/solo86/ports.h>


void irq_enable(word_t irq)
{
    if (irq > 3)
        return;

    unsigned char mask = 1 << irq;
    unsigned char state = inb(PIC_CMD);

    state |= mask;

    outb(state, PIC_CMD);
}

void irq_disable(word_t irq)
{
    if (irq > 3)
        return;

    unsigned char mask = 1 << irq;
    unsigned char state = inb(PIC_CMD);

    state &= mask;

    outb(state, PIC_CMD);
}

void irq_setup()
{
    // disable all IRQs

    outb(0x00, PIC_DATA);
}

