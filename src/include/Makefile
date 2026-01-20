include $(TOPDIR)/Makefile.conf

all:
	rm -f monitor/version.h

	printf >> monitor/version.h \
		'#ifndef __monitor_version__\n'

	printf >> monitor/version.h \
		'#define __monitor_version__\n'

	printf >> monitor/version.h \
		'#define SYS_VERSION\t"$(shell git log --abbrev-commit | head -1)"\n'
	printf >> monitor/version.h \
		'#define SYS_BUILD\t"$(shell date '+%T %a %d %b %Y %z')"\n'

	printf >> monitor/version.h \
		'#endif\n\n'

clean:

