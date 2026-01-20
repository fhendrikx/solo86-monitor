
.arch i8086, nojumps

.code16

.text

.global peekb
.global peekw
.global peekl
.global pokeb
.global pokew
.global pokel

.global strlen
.global strcpy
.global strcmp

.global memcpyb
.global memcpyw
.global memsetb
.global memsetw
.global memcmpb
.global memcmpw

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

# byte_t peekb (word_t off, seg_t seg)
# returns the byte at the far pointer segment:offset

peekb:
    mov %ds,%dx
    mov %sp,%bx
    lds ARG0(%bx),%bx       # far pointer
    mov (%bx),%al           # DS by default
    xor %ah,%ah
    mov %dx,%ds
    ret


# word_t peekw (word_t off, seg_t seg)
# returns the word at the far pointer segment:offset

peekw:
    mov %ds,%dx
    mov %sp,%bx
    lds ARG0(%bx),%bx       # far pointer
    mov (%bx),%ax           # DS by default
    mov %dx,%ds
    ret


# long_t peekl (word_t off, seg_t seg)
# returns the word at the far pointer segment:offset

peekl:
    mov %ds,%cx
    mov %sp,%bx
    lds ARG0(%bx),%bx       # far pointer
    mov (%bx),%ax           # DS by default
    mov 2(%bx),%dx
    mov %cx,%ds
    ret


# void pokeb (word_t off, seg_t seg, byte__t val)
# compiler pushes byte_t as word_t
# writes the byte at the far pointer segment:offset

pokeb:
    mov %ds,%dx
    mov %sp,%bx
    mov ARG2(%bx),%ax       # value
    lds ARG0(%bx),%bx       # far pointer
    mov %al,(%bx)           # DS by default
    mov %dx,%ds
    ret


# void pokew (word_t off, seg_t seg, word_t val)
# writes the word at the far pointer segment:offset

pokew:
    mov %ds,%dx
    mov %sp,%bx
    mov ARG2(%bx),%ax       # value
    lds ARG0(%bx),%bx       # far pointer
    mov %ax,(%bx)           # DS by default
    mov %dx,%ds
    ret


# void pokel (word_t off, seg_t seg, long_t val)
# writes the long at the far pointer segment:offset

pokel:
    mov %ds,%cx
    mov %sp,%bx
    mov ARG2(%bx),%ax       # low word value
    mov ARG2+2(%bx),%dx     # high word value
    lds ARG0(%bx),%bx       # far pointer
    mov %ax,(%bx)           # DS by default
    mov %dx,2(%bx)
    mov %cx,%ds
    ret


# int strlen(char *str)
# returns the length of string

strlen:
    mov %es,%dx
    mov %ss,%ax
    mov %ax,%es
    mov %sp,%bx
    push %di
    mov ARG0(%bx),%di       # str
    xor %al,%al
    cld
    mov $-1,%cx             # maximum loop count
    repne                   # while (cx) {
    scasb                   # { cx--; if (al - [es:di++] == 0) break; }
    mov %di,%ax
    sub ARG0(%bx),%ax
    dec %ax
    pop %di
    mov %dx,%es
    ret


# char *strcpy(char *dest, char *source)
# copies the zero terminated string source to dest

strcpy:
    mov %es,%dx
    mov %ss,%ax
    mov %ax,%es
    mov %sp,%bx
    push %di
    push %si
    mov ARG0(%bx),%di       # dest
    mov ARG1(%bx),%si       # source
    cld

cpyon:
    lodsb                   # al = [ds:si++]
    stosb                   # [es:di++] = al
    test %al,%al
    jnz cpyon
    mov ARG0(%bx),%ax       # return a pointer to the destination string
    pop %si
    pop %di
    mov %dx,%es
    ret


# int strcmp(char *str1, char *str2)
# compares to zero terminated strings

strcmp:
    mov %es,%dx
    mov %ss,%ax
    mov %ax,%es
    mov %sp,%bx
    push %di
    push %si
    mov ARG0(%bx),%si       # str1
    mov ARG1(%bx),%di       # str2
    cld

cmpon:
    lodsb                   # al = [ds:si++]
    scasb                   # al - [es:di++]
    jne cmpend
    test %al,%al
    jnz cmpon
    xor %ax,%ax             # both strings are the same
    jmp cmpret

cmpend:
    sbb %ax,%ax             # strings differ
    or $1,%ax

cmpret:
    pop %si
    pop %di
    mov %dx,%es
    ret


# void memcpyb (void * dst_off, seg_t dst_seg, void * src_off, seg_t src_seg,
# size_t count)

memcpyb:
    mov %si,%ax
    mov %di,%dx
    mov %sp,%si
    mov %es,%bx
    mov ARG4(%si),%cx       # byte count
    les ARG0(%si),%di       # far destination pointer
    lds ARG2(%si),%si       # far source pointer
    cld
    shr $1,%cx              # copy words
    rep
    movsw
    rcl $1,%cx              # then possibly final byte
    rep
    movsb
    mov %bx,%es
    mov %ax,%si
    mov %dx,%di
    mov %ss,%ax
    mov %ax,%ds
    ret


# void memcpyw (void * dst_off, seg_t dst_seg, void * src_off, seg_t src_seg,
# size_t count)

memcpyw:
    mov %es,%bx
    mov %si,%ax
    mov %di,%dx
    mov %sp,%si
    mov ARG4(%si),%cx       # word count
    les ARG0(%si),%di       # far destination pointer
    lds ARG2(%si),%si       # far source pointer
    cld
    rep
    movsw
    mov %ax,%si
    mov %dx,%di
    mov %ss,%ax
    mov %ax,%ds
    mov %bx,%es
    ret


# void memsetb (void * off, seg_t seg, byte_t val, size_t count)
# compiler pushes byte_t as word_t

memsetb:
    mov %di,%dx
    mov %sp,%di
    mov %es,%bx
    mov ARG2(%di),%ax       # value
    mov ARG3(%di),%cx       # byte count
    les ARG0(%di),%di       # far pointer
    cld
    shr $1,%cx              # store words
    mov %al,%ah
    rep
    stosw
    rcl $1,%cx              # then possibly final byte
    rep
    stosb
    mov %bx,%es
    mov %dx,%di
    ret


# void memsetw (void * off, seg_t seg, word_t val, size_t count)

memsetw:
    mov %es,%bx
    mov %di,%dx
    mov %sp,%di
    mov ARG2(%di),%ax       # value
    mov ARG3(%di),%cx       # byte count
    les ARG0(%di),%di       # far pointer
    cld
    rep
    stosw
    mov %dx,%di
    mov %bx,%es
    ret


# int memcmpb (void * dst_off, seg_t dst_seg, void * src_off, seg_t src_seg,
# size_t count)

memcmpb:
    mov %es,%bx
    mov %si,%ax
    mov %di,%dx
    mov %sp,%si
    mov ARG4(%si),%cx       # byte count
    les ARG0(%si),%di       # far destination pointer
    lds ARG2(%si),%si       # far source pointer
    cld
    repz
    cmpsb
    mov %ax,%si
    mov %dx,%di
    jz  memcmpb_same
    mov $1,%ax
    jmp memcmpb_exit

memcmpb_same:
    xor %ax,%ax
memcmpb_exit:
    mov %ss,%dx
    mov %dx,%ds
    mov %bx,%es
    ret


# int memcmpw (void * dst_off, seg_t dst_seg, void * src_off, seg_t src_seg,
# size_t count)

memcmpw:
    mov %es,%bx
    mov %si,%ax
    mov %di,%dx
    mov %sp,%si
    mov ARG4(%si),%cx       # byte count
    les ARG0(%si),%di       # far destination pointer
    lds ARG2(%si),%si       # far source pointer
    cld
    repz
    cmpsw
    mov %ax,%si
    mov %dx,%di
    jz  memcmpw_same
    mov $1,%ax
    jmp memcmpw_exit

memcmpw_same:
    xor %ax,%ax
memcmpw_exit:
    mov %ss,%dx
    mov %dx,%ds
    mov %bx,%es
    ret


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

