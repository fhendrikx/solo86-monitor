
#
# register macros
#

.macro regs_save
    push %ax                # save registers
    push %cx
    push %dx
    push %bx
    push %bp
    push %si
    push %di
    push %ds
    push %es
.endm

.macro regs_restore
    pop %es                 # restore registers
    pop %ds
    pop %di
    pop %si
    pop %bp
    pop %bx
    pop %dx
    pop %cx
    pop %ax
.endm


#
# interrupt macros
#

.macro int_fault name, val
.global \name
\name:
    regs_save
    mov $\val,%ax           # interrupt
    push %ax
    call fault_handler
    add $2,%sp
    regs_restore
    iret
.endm

.macro int_timer name
.global \name
\name:
    regs_save
    call irq_timer
#ifdef ARCH_IBMPC
    mov $0x20,%al
    outb %al,$0x20
#endif
#ifdef ARCH_SOLO86
    mov $0x01,%al
    outb %al,$0x1A
#endif
    regs_restore
    iret
.endm

.macro int_irqlo name, val
.global \name
\name:
    regs_save
    mov $\val,%ax           # interrupt
    push %ax
    call irq_handler
    add $2,%sp
#ifdef ARCH_IBMPC
    mov $0x20,%al
    outb %al,$0x20
#endif
#ifdef ARCH_SOLO86
    mov $0x01,%al
    outb %al,$0x1A
#endif
    regs_restore
    iret
.endm

.macro int_irqhi name, val
.global \name
\name:
    regs_save
    mov $\val,%ax           # interrupt
    push %ax
    call irq_handler
    add $2,%sp
#ifdef ARCH_IBMPC
    mov $0x20,%al
    outb %al,$0xA0
    mov $0x20,%al
    outb %al,$0x20
#endif
#ifdef ARCH_SOLO86
    mov $0x01,%al
    outb %al,$0x1A
#endif
    regs_restore
    iret
.endm

