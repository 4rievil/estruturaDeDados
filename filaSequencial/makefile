CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = programa

all: $(TARGET)

$(TARGET): main.o fila.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o fila.o

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c fila.c

main.o: main.c fila.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(TARGET)