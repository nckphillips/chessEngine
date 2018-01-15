CC = gcc
CFLAGS = -Wall -Werror
DEBUG = -g
DEPS = bitBoard.h

main: main.c $(DEPS)
	$(CC) $(DEBUG) $(CFLAGS) -o $@ $<
