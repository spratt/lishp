CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -g
VALGRIND=valgrind

runfile=lishp
cfiles=$(wildcard *.c)
ofiles=$(patsubst %.c, %.o, $(cfiles))

.PHONY: all run clean valgrind

all: $(runfile)

run: $(runfile)
	./$(runfile)

valgrind: $(runfile)
	$(VALGRIND) ./$(runfile)

$(runfile): $(ofiles)

clean:
	rm -f $(ofiles) $(runfile)
