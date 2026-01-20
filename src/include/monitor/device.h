#ifndef __monitor_device__
#define __monitor_device__

#include <arch/types.h>

struct dev_ops {
    int         (*init) ();
    size_t      (*read) ();
    size_t      (*write)();
};

#endif
