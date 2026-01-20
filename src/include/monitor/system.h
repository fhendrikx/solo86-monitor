#ifndef __monitor_system__
#define __monitor_system__

#define SYS_NAME                "Monitor"
#define SYS_RELEASE             "1.0.0"

#ifdef ARCH_IBMPC
#include <arch/ibmpc/arch.h>
#endif

#ifdef ARCH_SOLO86
#include <arch/solo86/arch.h>
#endif

#endif
