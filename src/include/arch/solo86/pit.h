#ifndef __arch_pit__
#define __arch_pit__

#include <monitor/config.h>

#define PIT_SPEED           1000000
#define PIT_LATCH           (PIT_SPEED / SYS_SPEED)

#define PIT_MODE0           0x30    // timer 0, binary count, mode 0, lsb/msb
#define PIT_MODE2           0x34    // timer 0, binary count, mode 2, lsb/msb

#define PIT_DISABLE         0x00
#define PIT_ENABLE          0x01

#endif
