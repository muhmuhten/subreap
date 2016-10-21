it:	all

PROGS	:=	subreap
CFLAGS	+=	-Wall -pedantic -s

all:	$(PROGS)
clean:
	rm -f $(PROGS)
