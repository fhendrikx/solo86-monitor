include $(TOPDIR)/Makefile.conf

NAME = monitor
LIBS = -Larch -L$(TOPDIR)/lib -larch
OBJS = console.o fault.o irq.o monitor.o printk.o

.c.o:
	$(CC) $(CCFLAGS) -o $*.o $<

.S.o:
	$(AS) $(ASFLAGS) -o $*.o $<

all: arch $(NAME)

arch::
	rm -f $(NAME)
	$(MAKE) -C arch

$(NAME): $(OBJS)
	$(LD) arch/entry.o $(OBJS) $(LIBS) -T monitor.ld --oformat=binary -m i386elks -Map monitor.map -o $(NAME)
	$(PD) --file=$(NAME)
	$(CP) $(NAME) $(TOPDIR)/out

clean:
	rm -f $(NAME)
	rm -f *.o *.a *.map *~
	$(MAKE) -C arch clean
