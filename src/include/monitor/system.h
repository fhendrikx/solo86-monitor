#ifndef __monitor_system__
#define __monitor_system__

#define SYS_NAME                "Solo/86 Monitor"
#define SYS_RELEASE             "1.0.0"

#ifdef ARCH_SOLO86
#define SYS_ARCH                "Solo86"
#endif

#ifdef ARCH_IBMPC
#define SYS_ARCH                "IBM_PC"
#endif

#endif
