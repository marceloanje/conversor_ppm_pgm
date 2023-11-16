#---------------------------------------------------------------------
# Arquivo	: Makefile
# Autor	    : Marcelo Andrade
# Historico	: 2022-09-10
#---------------------------------------------------------------------
# Opções	: make - compila tudo
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c img.c
OBJS = $(SRCS:.c=.o)
HEADERS = img.h msgassert.h

programa: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o programa

main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c -o main.o

img.o: img.c img.h
	$(CC) $(CFLAGS) -c img.c -o img.o

clean:
	rm -f $(OBJS) programa