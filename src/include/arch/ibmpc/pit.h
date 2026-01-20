#ifndef __arch_pit__
#define __arch_pit__

#include <monitor/config.h>

#define PIT_SPEED           1193182
#define PIT_LATCH           (PIT_SPEED / SYS_SPEED)

#define PIT_MODE0           0x30    // timer 0, binary count, mode 0, lsb/msb
#define PIT_MODE2           0x34    // timer 0, binary count, mode 2, lsb/msb

#endif
