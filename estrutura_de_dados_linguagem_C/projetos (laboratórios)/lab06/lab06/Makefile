CC=gcc
CFLAGS=-ansi -Wall -pedantic-errors -g -lm

all: lab06

heap.o: heap.c heap.h
	$(CC) -c heap.c $(CFLAGS)

lab06.o: lab06.c
	$(CC) -c lab06.c $(CFLAGS)

lab06: lab06.o heap.o 
	$(CC) lab06.o heap.o -o lab06 $(CFLAGS)

clean:
	rm -f *.o lab06
