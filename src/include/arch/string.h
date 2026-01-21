#ifndef __arch_string__
#define __arch_string__

#include <arch/types.h>

int strlen(char *str);
char *strcpy(char *dst, char *src);
int strcmp(char *str1, char *str2);

void memcpyb(void *doff, word_t dseg, void *soff, word_t sseg, size_t count);
void memcpyw(void *doff, word_t dseg, void *soff, word_t sseg, size_t count);
void memsetb(void *off, word_t seg, byte_t value, size_t count);
void memsetw(void *off, word_t seg, word_t value, size_t count);
void memcmpb(void *doff, word_t dseg, void *soff, word_t sseg, size_t count);
void memcmpw(void *doff, word_t dseg, void *soff, word_t sseg, size_t count);

#endif
