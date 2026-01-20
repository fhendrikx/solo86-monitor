include $(TOPDIR)/Makefile.conf

NAME = libarch.a
OBJS = console.o divmodsi3.o int.o ldivmod.o vectors.o x86lib.o

ifeq ($(ARCH), ibmpc)
	OBJS += irq-ibmpc.o pit-ibmpc.o
endif

ifeq ($(ARCH), solo86)
	OBJS += irq-solo86.o pit-solo86.o
endif

.c.o:
	$(CC) $(CCFLAGS) -I.. -o $*.o $<

.S.o:
	$(AS) $(ASFLAGS) -I.. -o $*.o $<

all: $(NAME) entry.o

$(NAME): $(OBJS)
	rm -f $(NAME)
	$(AR) r $(NAME) $(OBJS)

clean:
	rm -f *.o *.a *.map *~

