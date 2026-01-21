include $(TOPDIR)/Makefile.conf

NAME = libarch.a
OBJS = int.o vectors.o x86lib.o

ifeq ($(ARCH), ibmpc)
	OBJS += con-ibmpc.o com-ibmpc.o exp-ibmpc.o irq-ibmpc.o pit-ibmpc.o
endif

ifeq ($(ARCH), solo86)
	OBJS += con-solo86.o com-solo86.o exp-solo86.o irq-solo86.o pit-solo86.o
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

