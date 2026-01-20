#ifndef __arch_ports__
#define __arch_ports__

#define PIT_PORT0           0x00
#define PIT_PORT0_EN        0x01
#define PIT_PORT1           0x02
#define PIT_PORT1_EN        0x03
#define PIT_PORT2           0x04
#define PIT_PORT2_EN        0x05
#define PIT_CMD             0x06

#define RTC_ADDR            0x0C
#define RTC_DATA            0x0E

#define BNK_ROW0            0x10
#define BNK_ROW1            0x12
#define BNK_ROW2            0x14
#define BNK_ROW3            0x16

#define PIC_CMD             0x18
#define PIC_DATA            0x1A

#define COM_CMD             0x20
#define COM_DATA            0x22

#endif
