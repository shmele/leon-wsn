
LIB	= misc.a
COBJS	= audio.o VS1003x.o

all:	$(LIB)

$(LIB):	$(COBJS)
	#$(LD) $(LDFLAGS) -r -o $@ $(COBJS)
	$(AR) crv $@ $(COBJS)
	$(RANLIB) $@
clean:
	@rm -f *.o
	@rm -f *.a
	@rm -f .depend
	
.depend:	Makefile $(COBJS:.o=.c)
		$(CC) -M $(CFLAGS) $(COBJS:.o=.c) > $@
sinclude .depend
