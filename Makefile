CC := gcc
CFLAGS := -Wall -Werror
DEBUG := -g
OBJS := main.o play.o bitBoard.o protocol.o check.o
main: $(OBJS)
	$(CC) $(DEBUG) $(CFLAGS)  $(OBJS) -o main.out
	rm *.o

main.o: main.c
	$(CC) -c $(DEBUG) $(CFLAGS) $<

%.o: %.c %.h
	$(CC) -c $(DEBUG) $(CFLAGS) $<

clean:
	rm *.out
