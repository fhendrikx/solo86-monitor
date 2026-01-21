#ifndef __arch_mem__
#define __arch_mem__

#include <arch/types.h>

byte_t peekb (word_t off, seg_t seg);
word_t peekw (word_t off, seg_t seg);
long_t peekl (word_t off, seg_t seg);

void pokeb (word_t off, seg_t seg, byte_t val);
void pokew (word_t off, seg_t seg, word_t val);
void pokel (word_t off, seg_t seg, long_t val);

#endif
