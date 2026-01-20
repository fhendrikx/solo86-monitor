#include <arch/cpu.h>
#include <arch/int.h>
#include <arch/pio.h>
#include <arch/types.h>
#include <arch/ibmpc/ports.h>


void irq_enable(word_t irq)
{
    word_t flags = flags_get();

    cli();

    if (irq < 8)
    {
        byte_t mask = inb(PIC0_DATA) & ~(1 << irq);

        outb(mask, PIC0_DATA);
    }
    else
    {
        irq -= 8;

        byte_t mask = inb(PIC1_DATA) & ~(1 << irq);

        outb(mask, PIC1_DATA);
    }

    flags_set(flags);
}

void irq_disable(word_t irq)
{
    word_t flags = flags_get();

    cli();

    if(irq < 8)
    {
        byte_t mask = inb(PIC0_DATA) | (1 << irq);

        outb(mask, PIC0_DATA);
    }
    else
    {
        irq -= 8;

        byte_t mask = inb(PIC1_DATA) | (1 << irq);

        outb(mask, PIC1_DATA);
    }

    flags_set(flags);
}

void irq_setup()
{
    // disable all IRQs

    outb(0xFF, PIC0_DATA);
    outb(0xFF, PIC1_DATA);


    // enable IRQ 2 (cascades to slave PIC)

    irq_enable(2);
}

