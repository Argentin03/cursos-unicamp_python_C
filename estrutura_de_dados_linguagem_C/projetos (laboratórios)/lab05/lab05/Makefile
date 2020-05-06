CC=gcc
CFLAGS=-ansi -Wall -pedantic-errors -g -lm

all: lab05

pilha_string.o: pilha_string.c pilha_string.h
	$(CC) -c pilha_string.c $(CFLAGS)

pilha_float.o: pilha_float.c pilha_float.h
	$(CC) -c pilha_float.c $(CFLAGS)

lab05.o: lab05.c
	$(CC) -c lab05.c $(CFLAGS)

lab05: lab05.o pilha_string.o pilha_float.o
	$(CC) lab05.o pilha_string.o pilha_float.o -o lab05 $(CFLAGS)

clean:
	rm -f *.o lab05
