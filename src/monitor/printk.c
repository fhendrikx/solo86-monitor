#include <stdarg.h>
#include <arch/cpu.h>
#include <arch/mem.h>
#include <libc/stdio.h>
#include <monitor/printk.h>
#include <monitor/segment.h>


/**********************************************************************
 * data
 **********************************************************************/

static char hex_string[] = "0123456789ABCDEF 0123456789abcdef ";


/**********************************************************************
 * functions
 **********************************************************************/

static void numout(__u32 v, int width, int base, int useSign, int Lower, int Zero, int alt)
{
    __u32 dvr;
    int c, vch, i;

    i = 10;
    dvr = 1000000000L;

    if (base > 10) {
        i = 8;
        dvr = 0x10000000L;
    }

    if (base < 10) {
        i = 11;
        dvr = 0x40000000L;
    }

    if (useSign && ((long)v < 0L))
        v = (-(long)v);
    else
        useSign = 0;

    if (Lower)
        Lower = 17;

    vch = 0;

    if (alt && base == 16) {
        putc('0');
        putc('x');
    }

    do {
        c = (int)(v / dvr);
        v %= dvr;
        dvr /= (unsigned int)base;

        if (c || (i <= width) || (i < 2))
        {
            if (i > width)
                width = (int)i;

            if (!Zero && !c && (i > 1))
                c = 16;
            else
            {
                Zero = 1;

                if (useSign)
                {
                    useSign = 0;
                    vch = '-';
                }
            }

            if (vch)
                putc(vch);

            vch = *(hex_string + Lower + c);
        }
    } while (--i);

    putc(vch);
}

static void vprintk(const char *fmt, va_list p)
{
    int c, n, width, zero, alt, ptrfmt;
    unsigned long v;
    char *str;

    while ((c = *fmt++))
    {
        if (c != '%')
            putc(c);
        else {
            c = *fmt++;

            if (c == '%') {
                putc(c);
                continue;
            }

            ptrfmt = alt = width = 0;
            if (c == '#') {
                alt = 1;
                c = *fmt++;
            }
            zero = (c == '0');
            while ((n = (c - '0')) <= 9) {
                width = width*10 + n;
                c = *fmt++;
            }

            if ((c == 'h') || (c == 'l'))
                c = *fmt++;

            n = 16;

            switch (c) {
            case 'i':
            case 'd':
                c = 'd';
                n = 18;
            case 'o':
                n -= 2;
            case 'u':
                n -= 6;
            case 'X':
            case 'x':
            hex:
                if (*(fmt-2) == 'l') {
                    if (ptrfmt) width = 8;
                    v = va_arg(p, unsigned long);
                } else {
                    if (c == 'd')
                        v = (long)(va_arg(p, int));
                    else
                        v = (unsigned long)(va_arg(p, unsigned int));
                }
            //out:
                numout(v, width, n, (c == 'd'), (c != 'X'), zero, alt);
                break;
            case 'D':
                c += 'X' - 'D';
            case 'p':
                c += 'X' - 'P';
                ptrfmt = 1;
                zero = 1;
                width = 4;
                goto hex;
            //case 'T':
            //    n = va_arg(p, unsigned int);
            //    goto str;
            //case 't':
            //    n = current->t_regs.ds;
            //    goto str;
            case 's':
                n = monitor_ds;
            //str:
                str = va_arg(p, char *);
                while ((zero = peekb((word_t)str++, n))) {
                    putc(zero);
                    width--;
                }
            case 'c':
                while (--width >= 0)
                    putc(' ');
                if (c == 'c')
                    putc(va_arg(p, int));
                break;
            default:
                putc('?');
            }
        }
    }
}

void printk(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vprintk(fmt, args);
    va_end(args);
}

void panic(const char *fmt, ...)
{
    va_list args;

    puts("PANIC: ");

    va_start(args, fmt);
    vprintk(fmt, args);
    va_end(args);

    cli();
    hlt();
}
