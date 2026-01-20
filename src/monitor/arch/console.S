
.arch i8086, nojumps

.code16

.text

.globl con_setup
.globl con_putc


######################################################################
# code
######################################################################

#ifdef ARCH_IBMPC
#include <arch/ibmpc/ports.h>

con_setup:
#    push %ax
#    push %bx
#
#    mov $0x03,%al           # 80x50 text mode
#    xor %ah,%ah
#    int $0x10
#
#    xor %al,%al             # active page = 0
#    mov $0x05,%ah
#    int $0x10
#
#    mov $0x1112,%ax         # 8x8 font
#    mov $0x00,%bl
#    int $0x10
#
#    pop %bx
#    pop %ax
    ret

con_putc:
    push %bp                # save BP; some bioses are not careful
    mov %sp,%bx

    mov 4(%bx),%ax          # offset is 4 because we also save BP

    cmp $0x0A,%al           # LF?
    jne 1f

    push %ax
    mov $0x0D,%al           # CR
    mov $0x0E,%ah
    mov $0x0007,%bx
    int $0x10
    pop %ax

1:
    mov $0x0E,%ah
    mov $0x0007,%bx
    int $0x10

    pop %bp                 # restore BP
    ret
#endif

#ifdef ARCH_SOLO86
#include <arch/solo86/ports.h>

con_setup:
    ret

con_putc:
    mov %sp,%bx
    mov 2(%bx),%ax
    outb %al,$COM_DATA
    ret
#endif

