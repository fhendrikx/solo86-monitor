#include <arch/irq.h>
#include <arch/pio.h>
#include <arch/solo86/ports.h>
#include <arch/solo86/pit.h>


/**********************************************************************
 * functions
 **********************************************************************/

void pit_setup()
{
    // set pit frequency

    outb(PIT_MODE2, PIT_CMD);
    outb(PIT_LATCH & 0xff, PIT_PORT0);
    outb(PIT_LATCH >> 8,   PIT_PORT0);
    outb(PIT_ENABLE, PIT_PORT0_EN);

    // enable irq

    irq_enable(0);
}

