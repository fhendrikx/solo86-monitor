#ifndef __limits__
#define __limits__

// Number of bits in a `char'
#define CHAR_BIT            8

// Minimum and maximum values a `signed char' can hold.
#define SCHAR_MIN           (-128)
#define SCHAR_MAX           127

// Maximum value an `unsigned char' can hold. (Minimum is 0.)
#define UCHAR_MAX           255

// Minimum and maximum values a `char' can hold.
#ifdef __CHAR_UNSIGNED__
#define CHAR_MIN            0
#define CHAR_MAX            UCHAR_MAX
#else
#define CHAR_MIN            SCHAR_MIN
#define CHAR_MAX            SCHAR_MAX
#endif

// Minimum and maximum values a `signed int' can hold.
#define INT_MIN             (-32768)
#define INT_MAX             32767

// Maximum value an `unsigned int' can hold. (Minimum is 0.)
#define UINT_MAX            65535

#endif
