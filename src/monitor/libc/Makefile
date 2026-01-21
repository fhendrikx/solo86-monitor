include $(TOPDIR)/Makefile.conf

NAME = libc.a
OBJS = divmodsi3.o ldivmod.o mem.o stdio.o string.o

.c.o:
	$(CC) $(CCFLAGS) -I.. -o $*.o $<

.S.o:
	$(AS) $(ASFLAGS) -I.. -o $*.o $<

all: $(NAME)

$(NAME): $(OBJS)
	rm -f $(NAME)
	$(AR) r $(NAME) $(OBJS)

clean:
	rm -f *.o *.a *.map *~

