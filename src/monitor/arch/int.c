#include <arch/cpu.h>
#include <arch/int.h>
#include <arch/pio.h>
#include <arch/types.h>
#include <monitor/segment.h>


/**********************************************************************
 * data
 **********************************************************************/

#ifdef ARCH_IBMPC
extern word_t _int_00;
extern word_t _int_01;
extern word_t _int_02;
extern word_t _int_03;
extern word_t _int_04;
extern word_t _int_05;
extern word_t _int_06;
extern word_t _int_07;
extern word_t _int_08;
extern word_t _int_09;
extern word_t _int_0A;
extern word_t _int_0B;
extern word_t _int_0C;
extern word_t _int_0D;
extern word_t _int_0E;
extern word_t _int_0F;
#endif

#ifdef ARCH_SOLO86
extern word_t _int_00;
extern word_t _int_01;
extern word_t _int_02;
extern word_t _int_03;
extern word_t _int_04;
extern word_t _int_05;
extern word_t _int_06;
extern word_t _int_07;
extern word_t _int_08;
extern word_t _int_09;
extern word_t _int_0A;
extern word_t _int_0B;
extern word_t _int_0C;
extern word_t _int_0D;
extern word_t _int_0E;
extern word_t _int_0F;

extern word_t _int_10;
extern word_t _int_11;
extern word_t _int_12;
extern word_t _int_13;
extern word_t _int_14;
extern word_t _int_15;
extern word_t _int_16;
extern word_t _int_17;
extern word_t _int_18;
extern word_t _int_19;
extern word_t _int_1A;
extern word_t _int_1B;
extern word_t _int_1C;
extern word_t _int_1D;
extern word_t _int_1E;
extern word_t _int_1F;

extern word_t _int_20;
extern word_t _int_21;
extern word_t _int_22;
extern word_t _int_23;
extern word_t _int_24;
extern word_t _int_25;
extern word_t _int_26;
extern word_t _int_27;
#endif


/**********************************************************************
 * functions
 **********************************************************************/

void int_setup()
{
#ifdef ARCH_IBMPC
    int_set(0x00, (word_t) &_int_00, monitor_cs);
    int_set(0x01, (word_t) &_int_01, monitor_cs);
    int_set(0x02, (word_t) &_int_02, monitor_cs);
    int_set(0x03, (word_t) &_int_03, monitor_cs);
    int_set(0x04, (word_t) &_int_04, monitor_cs);
    int_set(0x05, (word_t) &_int_05, monitor_cs);
    int_set(0x06, (word_t) &_int_06, monitor_cs);
    int_set(0x07, (word_t) &_int_07, monitor_cs);

    int_set(0x08, (word_t) &_int_08, monitor_cs);
    int_set(0x09, (word_t) &_int_09, monitor_cs);
    int_set(0x0A, (word_t) &_int_0A, monitor_cs);
    int_set(0x0B, (word_t) &_int_0B, monitor_cs);
    int_set(0x0C, (word_t) &_int_0C, monitor_cs);
    int_set(0x0D, (word_t) &_int_0D, monitor_cs);
    int_set(0x0E, (word_t) &_int_0E, monitor_cs);
    int_set(0x0F, (word_t) &_int_0F, monitor_cs);
#endif

#ifdef ARCH_SOLO86
    int_set(0x00, (word_t) &_int_00, monitor_cs);
    int_set(0x01, (word_t) &_int_01, monitor_cs);
    int_set(0x02, (word_t) &_int_02, monitor_cs);
    int_set(0x03, (word_t) &_int_03, monitor_cs);
    int_set(0x04, (word_t) &_int_04, monitor_cs);
    int_set(0x05, (word_t) &_int_05, monitor_cs);
    int_set(0x06, (word_t) &_int_06, monitor_cs);
    int_set(0x07, (word_t) &_int_07, monitor_cs);
    int_set(0x08, (word_t) &_int_08, monitor_cs);
    int_set(0x09, (word_t) &_int_09, monitor_cs);
    int_set(0x0A, (word_t) &_int_0A, monitor_cs);
    int_set(0x0B, (word_t) &_int_0B, monitor_cs);
    int_set(0x0C, (word_t) &_int_0C, monitor_cs);
    int_set(0x0D, (word_t) &_int_0D, monitor_cs);
    int_set(0x0E, (word_t) &_int_0E, monitor_cs);
    int_set(0x0F, (word_t) &_int_0F, monitor_cs);

    int_set(0x10, (word_t) &_int_10, monitor_cs);
    int_set(0x11, (word_t) &_int_11, monitor_cs);
    int_set(0x12, (word_t) &_int_12, monitor_cs);
    int_set(0x13, (word_t) &_int_13, monitor_cs);
    int_set(0x14, (word_t) &_int_14, monitor_cs);
    int_set(0x15, (word_t) &_int_15, monitor_cs);
    int_set(0x16, (word_t) &_int_16, monitor_cs);
    int_set(0x17, (word_t) &_int_17, monitor_cs);
    int_set(0x18, (word_t) &_int_18, monitor_cs);
    int_set(0x19, (word_t) &_int_19, monitor_cs);
    int_set(0x1A, (word_t) &_int_1A, monitor_cs);
    int_set(0x1B, (word_t) &_int_1B, monitor_cs);
    int_set(0x1C, (word_t) &_int_1C, monitor_cs);
    int_set(0x1D, (word_t) &_int_1D, monitor_cs);
    int_set(0x1E, (word_t) &_int_1E, monitor_cs);
    int_set(0x1F, (word_t) &_int_1F, monitor_cs);

    int_set(0x20, (word_t) &_int_20, monitor_cs);
    int_set(0x21, (word_t) &_int_21, monitor_cs);
    int_set(0x22, (word_t) &_int_22, monitor_cs);
    int_set(0x23, (word_t) &_int_23, monitor_cs);
    int_set(0x24, (word_t) &_int_24, monitor_cs);
    int_set(0x25, (word_t) &_int_25, monitor_cs);
    int_set(0x26, (word_t) &_int_26, monitor_cs);
    int_set(0x27, (word_t) &_int_27, monitor_cs);
#endif
}

