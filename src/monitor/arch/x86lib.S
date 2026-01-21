
.arch i8086, nojumps

.code16

.text

.global int_set


######################################################################
# code
######################################################################

# the following code borrowed from elks

#define ARG0    2
#define ARG1    4
#define ARG2    6
#define ARG3    8
#define ARG4    10

# segment parameter after offset to allow LDS/LES from the stack
# assume DS=SS, save ES, for GCC-IA16

# void int_set (word_t num, word_t off, seg_t seg)

int_set:
    mov %sp,%bx
    mov ARG2(%bx),%dx
    mov ARG1(%bx),%cx
    mov ARG0(%bx),%bx

    shl $1,%bx
    shl $1,%bx

    push %ds
    xor %ax,%ax
    mov %ax,%ds

    mov %cx,0(%bx)
    mov %dx,2(%bx)

    pop %ds
    ret

