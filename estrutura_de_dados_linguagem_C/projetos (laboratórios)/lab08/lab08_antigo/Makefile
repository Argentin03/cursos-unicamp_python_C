CC=gcc
CFLAGS=-ansi -Wall -pedantic-errors -g -lm

all: lab08

arvore_quarternaria.o: arvore_quaternaria.c arvore_quaternaria.h
	$(CC) -c arvore_quaternaria.c $(CFLAGS)

lab08.o: lab08.c
	$(CC) -c lab08.c $(CFLAGS)

lab08: lab08.o arvore_quaternaria.o  
	$(CC) lab08.o arvore_quaternaria.o -o lab08 $(CFLAGS)

clean:
	rm -f *.o lab08
