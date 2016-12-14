# $Id$

targets= generator twosum
TOCLEAN += $(targets)

generator_objs= generator.o
TOCLEAN += $(generator_objs)
SOURCES += $(generator_objs:.o=.c)

twosum_objs= twosum.o
TOCLEAN += $(twosum_objs)
SOURCES += $(twosum_objs:.o=.c)

all: $(targets)
clean: 
	$(RM) $(TOCLEAN)

generator: $(generator_objs)
	$(CC) $(LDFLAGS) -o $@ $(generator_objs)

twosum: $(twosum_objs)
	$(CC) $(LDFLAGS) -o $@ $(twosum_objs)

.depend:
	$(CC) -MM $(SOURCES) >$@
TOCLEAN += .depend

-include .depend
