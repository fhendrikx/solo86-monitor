#ifndef __arch_device__
#define __arch_device__

#include <arch/types.h>

#define DEV_TYPE_NONE           0x00
#define DEV_TYPE_SYSTEM         0x01
#define DEV_TYPE_SETTING        0x02
#define DEV_TYPE_CONSOLE        0x10
#define DEV_TYPE_DISK           0x40
#define DEV_TYPE_OTHER          0x80

#define DEV_SET_SND_EN          0x10
#define DEV_SET_APP_EN          0x20
#define DEV_SET_APP_SELECT      0x22
#define DEV_SET_COM_EN          0x40
#define DEV_SET_COM_SELECT      0x42

#define DEV_SET_COM_1200        0x03
#define DEV_SET_COM_9600        0x02
#define DEV_SET_COM_38400       0x01
#define DEV_SET_COM_115200      0x00

typedef struct {
    int type;
    word_t port;
    char name[16];
} device_t;

typedef struct {
    int type;
    long_t value;
    char name[16];
} setting_t;

int dev_setup(device_t *devices, setting_t *settings);
int dev_detect(word_t port);

#endif
