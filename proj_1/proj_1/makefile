CC=gcc
CFLAGS=-I.
DEPS = list.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

list: list.o list_test.o
	$(CC) -o list list.o list_test.o
