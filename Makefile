CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -g

cfiles=$(wildcard *.c)
ofiles=$(patsubst %.c, %.o, $(cfiles))

all: lishp

lishp: $(ofiles)

clean:
	rm -f $(ofiles) lishp
