#
# a very simple Makefile for zlib
#

PROGRAM = testzlib
SOURCES = testzlib.c

CFLAGS = -Wall
LDFLAGS = -lz
#
# gcc (generic)
#

gcc:
	gcc $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM)
	rm -f *.err *.o *.obj

all: gcc

.PHONY: clean gcc
