#ifndef __arch_frame__
#define __arch_frame__

#include <arch/types.h>

struct frame
{
    word_t es;
    word_t ds;
    word_t di;
    word_t si;
    word_t bp;
    word_t bx;
    word_t dx;
    word_t cx;
    word_t ax;
    word_t ip;
    word_t cs;
    word_t flags;
};

#endif
