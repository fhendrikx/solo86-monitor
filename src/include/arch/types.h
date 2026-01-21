#ifndef __arch_types__
#define __arch_types__

typedef unsigned char       __u8;
typedef signed char         __s8;
typedef unsigned short int  __u16;
typedef signed short int    __s16;
typedef unsigned long int   __u32;
typedef signed long int     __s32;

typedef __u8                byte_t;
typedef __u16               word_t;
typedef __u32               long_t;

typedef __u16               seg_t;
typedef __u16               flag_t;
typedef __u16               size_t;

#ifndef NULL
#define NULL                ((void *) 0)
#endif

#endif
