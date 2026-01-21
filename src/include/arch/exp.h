#ifndef __arch_exp__
#define __arch_exp__

#include <arch/types.h>

#define EXP_TYPE_NONE           0x00
#define EXP_TYPE_SYSTEM         0x01
#define EXP_TYPE_SETTING        0x02
#define EXP_TYPE_CONSOLE        0x10
#define EXP_TYPE_DISK           0x40
#define EXP_TYPE_OTHER          0x80

#define EXP_SET_SND_EN          0x01    // 0=OFF, 1=beep
#define EXP_SET_APP_SELECT      0x0E    // 000..111=application
#define EXP_SET_APP_EN          0x10    // 0=OFF, 1=boot to application
#define EXP_SET_COM_SELECT      0x30    // 00=115200, 01=38400, 10=9600, 11=1200
#define EXP_SET_COM_EN          0x80    // 0=OFF, 1=COM

typedef struct {
    int type;
    word_t port;
    char name[16];
} expansion_t;

typedef struct {
    int type;
    long_t value;
    char name[16];
} setting_t;

int exp_setup(expansion_t *devices, setting_t *settings);
int exp_detect(word_t port);

#endif
