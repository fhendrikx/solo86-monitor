include $(TOPDIR)/Makefile.conf
include $(TOPDIR)/Makefile.rules

ifeq ($(ARCH), ibmpc)
	SUBDIRS = src
endif

ifeq ($(ARCH), solo86)
	SUBDIRS = src
endif

ifeq ($(ARCH), ibmpc)
test:
	qemu-system-i386 -machine isapc -cpu 486 -serial stdio -m 1 -drive file=boot/boot16.img,format=raw
endif

ifeq ($(ARCH), solo86)
test:
endif
