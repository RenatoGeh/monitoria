CC = gcc
CFLAGS = -ansi -pedantic -Wall

all: utils.o main.o
	$(CC) $? $(CFLAGS) -o lista_3

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) utils.c -c -o utils.o

main.o: main.c utils.h
	$(CC) $(CFLAGS) main.c -c -o main.o

clean:
	rm *.o lista_3
