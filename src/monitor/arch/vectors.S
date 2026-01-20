
.arch i8086, nojumps

.code16

.text


######################################################################
# data
######################################################################

#include "macro.S"

    .align 8

#ifdef ARCH_IBMPC
    # 0x00-0x07 faults
    int_fault _int_00, 0x00
    int_fault _int_01, 0x01
    int_fault _int_02, 0x02
    int_fault _int_03, 0x03
    int_fault _int_04, 0x04
    int_fault _int_05, 0x05
    int_fault _int_06, 0x06
    int_fault _int_07, 0x07

    # 0x08-0x0F IRQs 0-7
    int_timer _int_08
    int_irqlo _int_09, 0x01
    int_irqlo _int_0A, 0x02
    int_irqlo _int_0B, 0x03
    int_irqlo _int_0C, 0x04
    int_irqlo _int_0D, 0x05
    int_irqlo _int_0E, 0x06
    int_irqlo _int_0F, 0x07

    # 0x10-0x1F BIOS

    # 0x20-0x2F reserved

    # 0x30-0x3F reserved
#endif

#ifdef ARCH_SOLO86
    # 0x00-0x0F faults
    int_fault _int_00, 0x00
    int_fault _int_01, 0x01
    int_fault _int_02, 0x02
    int_fault _int_03, 0x03
    int_fault _int_04, 0x04
    int_fault _int_05, 0x05
    int_fault _int_06, 0x06
    int_fault _int_07, 0x07
    int_fault _int_08, 0x08
    int_fault _int_09, 0x09
    int_fault _int_0A, 0x0A
    int_fault _int_0B, 0x0B
    int_fault _int_0C, 0x0C
    int_fault _int_0D, 0x0D
    int_fault _int_0E, 0x0E
    int_fault _int_0F, 0x0F

    # 0x10-0x1F faults
    int_fault _int_10, 0x10
    int_fault _int_11, 0x11
    int_fault _int_12, 0x12
    int_fault _int_13, 0x13
    int_fault _int_14, 0x14
    int_fault _int_15, 0x15
    int_fault _int_16, 0x16
    int_fault _int_17, 0x17
    int_fault _int_18, 0x18
    int_fault _int_19, 0x19
    int_fault _int_1A, 0x1A
    int_fault _int_1B, 0x1B
    int_fault _int_1C, 0x1C
    int_fault _int_1D, 0x1D
    int_fault _int_1E, 0x1E
    int_fault _int_1F, 0x1F

    # 0x20-0x27 IRQs
    int_timer _int_20
    int_irqlo _int_21, 0x01
    int_irqlo _int_22, 0x02
    int_irqlo _int_23, 0x03
    int_irqlo _int_24, 0x04
    int_irqlo _int_25, 0x05
    int_irqlo _int_26, 0x06
    int_irqlo _int_27, 0x07

    # 0x28-0x2F reserved

    # 0x30-0x3F reserved
#endif

