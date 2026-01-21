#ifndef __arch_ports__
#define __arch_ports__

#define PIT_DETECT          0x01
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

#define PIC_CTRL            0x18
#define PIC_DATA            0x1A

#define CON_DETECT          0x21
#define CON_CTRL            0x20
#define CON_DATA            0x22

#define PNL_DETECT          0x31
#define PNL_CTRL            0x30
#define PNL_DATA            0x30

#define ATA_DETECT          0x41
#define ATA_DATA            0x40
#define ATA_ERROR           0x42
#define ATA_FEAT            0x42
#define ATA_COUNT           0x44
#define ATA_LBA_LO          0x46
#define ATA_LBA_MD          0x48
#define ATA_LBA_HI          0x4A
#define ATA_DRVH            0x4C
#define ATA_CMND            0x4E
#define ATA_STATUS          0x4E
#define ATA_CTRL            0x5C

#define COM_DETECT          0x61
#define COM_DATA            0x60
#define COM_IER             0x62
#define COM_IIR             0x64
#define COM_FCR             0x64
#define COM_LCR             0x66
#define COM_MCR             0x68
#define COM_LSR             0x6A
#define COM_MSR             0x6C
#define COM_SCR             0x6E

#endif
