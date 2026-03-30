
.arch i8086, nojumps

.code16

.globl start

.globl monitor_cs
.globl monitor_ds


######################################################################
# code
######################################################################

#include "macro.S"

start:
    # the start

    cli


    # kernel segments (tiny model; CS=DS=ES=SS)

    mov %cs,%ax
    mov %ax,%ds
    mov %ax,%es
    mov %ax,%ss
    mov $0xFFFF,%sp

    mov %ax,monitor_cs
    mov %ax,monitor_ds


    # clear BSS

    mov $bss_start,%di
    mov $bss_end,%cx
    sub %di,%cx
    xor %al,%al
    cld
    rep stosb


#ifdef ARCH_IBMPC
    # turn off disk drives

    xor %al,%al
    movw $0x3f2,%dx         # primary adapter
    outb %al,%dx

    movw $0x372,%dx         # secondary adapter
    outb %al,%dx
#endif

    # start monitor

    jmp monitor

    cli
    hlt


######################################################################
# data
######################################################################

    .align 4

monitor_cs:
    .word 0x00

monitor_ds:
    .word 0x00

