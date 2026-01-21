#ifndef __arch_cpu__
#define __arch_cpu__

#define nop() \
        asm volatile ("nop":::"memory")
#define cli() \
        asm volatile ("cli":::"memory")
#define sti() \
        asm volatile ("sti":::"memory")
#define hlt() \
        asm volatile ("hlt":::"memory")

#define flags_get() \
    ({ \
        register unsigned int _temp__; \
        asm volatile("pushf; pop %0" : "=r" (_temp__)); \
        _temp__; \
    })

#define flags_set(value) \
    ({ \
        register unsigned int _temp__ = (value); \
        asm volatile("push %0; popf" : : "r" (_temp__)); \
    })

#endif
