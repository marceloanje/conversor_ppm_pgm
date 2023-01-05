#---------------------------------------------------------------------
# Arquivo	    : main.c
# Conteudo	    : programa de avaliacao do TAD IMG
# Autor	    : Marcelo Andrade
# Historico	: 2022-09-10
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make mem - gera arquivos de registro de acesso
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/img.o
HDRS = $(INC)/img.h
CFLAGS = -pg -Wall -c -I$(INC)

EXE = $(BIN)/main

all:  mem

mem: $(EXE)
	
$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/img.o: $(HDRS) $(SRC)/img.c
	$(CC) $(CFLAGS) -o $(OBJ)/img.o $(SRC)/img.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out