CC := gcc
CFLAGS := -Wall
DEBUG := -g
OBJS := main.o bitBoard.o protocol.o
main: $(OBJS)
	$(CC) $(DEBUG) $(CFLAGS)  $(OBJS) -o main.out
	rm *.o

main.o: main.c
	$(CC) -c $(DEBUG) $(CFLAGS) $<

%.o: %.c %.h
	$(CC) -c $(DEBUG) $(CFLAGS) $<

clean:
	rm *.o
