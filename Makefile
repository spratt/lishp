CFLAGS=-std=c11 -Wall -Wextra -Werror -pedantic -g
VALGRIND=valgrind

SRCDIR=src
BUILD=build
RUNFILES=runfiles

cbins=$(wildcard $(RUNFILES)/*.c)
bins=$(patsubst $(RUNFILES)/%.c, $(BUILD)/%, $(cbins))
cfiles=$(wildcard $(SRCDIR)/*.c)
ofiles=$(patsubst $(SRCDIR)/%.c, $(BUILD)/%.o, $(cfiles))

TESTDIR=tests
TESTBUILD=$(BUILD)/tests
ctests=$(wildcard $(TESTDIR)/*.c)
tests=$(patsubst $(TESTDIR)/%.c, $(TESTBUILD)/%, $(ctests))

.PHONY: all test run clean valgrind

all: $(tests) $(bins)

test: $(tests)
	@$(foreach test,$(tests), ./$(test))

run: $(bins)
	$(foreach bin,$(bins), ./$(bin))

valgrind: $(bins) $(tests)
	$(foreach bin,$(bins), $(VALGRIND) ./$(bin))
	@$(foreach test,$(tests), $(VALGRIND) ./$(test))

$(BUILD)/% : $(ofiles) $(RUNFILES)/%.c
	$(CC) $(CFLAGS) $(CFLAGS) $^ -o $@

$(BUILD)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(BUILD)
	$(CC) -c $(CFLAGS) $(CFLAGS) $< -o $@

$(TESTBUILD)/% : $(ofiles) $(TESTDIR)/%.c
	@mkdir -p $(TESTBUILD)
	$(CC) $(CFLAGS) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.dSYM $(BUILD)
