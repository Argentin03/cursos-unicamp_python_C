CC=gcc
CFLAGS=-ansi -Wall -pedantic-errors -g -lm

all: lab07

arvore_binaria.o: arvore_binaria.c arvore_binaria.h
	$(CC) -c arvore_binaria.c $(CFLAGS)

fp.o: fp.c fp.h
	$(CC) -c fp.c $(CFLAGS)

lab07.o: lab07.c
	$(CC) -c lab07.c $(CFLAGS)

lab07: lab07.o arvore_binaria.o fp.o 
	$(CC) lab07.o arvore_binaria.o fp.o -o lab07 $(CFLAGS)

clean:
	rm -f *.o lab07
