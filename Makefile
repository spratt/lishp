CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -g

runfile=lishp
cfiles=$(wildcard *.c)
ofiles=$(patsubst %.c, %.o, $(cfiles))

.PHONY: all run clean

all: $(runfile)

run: $(runfile)
	./$(runfile)

$(runfile): $(ofiles)

clean:
	rm -f $(ofiles) $(runfile)
