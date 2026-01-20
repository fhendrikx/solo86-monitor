#ifndef __arch_cpu__
#define __arch_cpu__

#define nop()       __asm__ __volatile__ ("nop":::"memory")
#define cli()       __asm__ __volatile__ ("cli":::"memory")
#define sti()       __asm__ __volatile__ ("sti":::"memory")
#define hlt()       __asm__ __volatile__ ("hlt":::"memory")

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
