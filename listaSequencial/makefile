CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: lista

lista: lista.o
	$(CC) $(CFLAGS) -o lista lista.o

lista.o: lista.c
	$(CC) $(CFLAGS) -c lista.c

clean:
	rm -f lista lista.o
