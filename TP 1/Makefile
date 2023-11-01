CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Calculadora.o $(OBJ)/Arvore.o $(OBJ)/Pilha.o $(OBJ)/Tipoitem.o $(OBJ)/TipoNo.o $(OBJ)/satisfabilidade.o $(OBJ)/main.o
HDRS = $(INC)/Arvore.h $(INC)/Pilha.h $(INC)/TipoItem.h $(INC)/TipoNo.h $(INC)/Calculadora.h
CFLAGS = -Wall -g -c -I$(INC)
DEBUG_FLAGS = -g

EXE = $(BIN)/tp1.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/satisfabilidade.o: $(HDRS) $(SRC)/satisfabilidade.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/satisfabilidade.o $(SRC)/satisfabilidade.cpp

$(OBJ)/Calculadora.o: $(HDRS) $(SRC)/Calculadora.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Calculadora.o $(SRC)/Calculadora.cpp

$(OBJ)/Arvore.o: $(HDRS) $(SRC)/Arvore.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Arvore.o $(SRC)/Arvore.cpp

$(OBJ)/Pilha.o: $(HDRS) $(SRC)/Pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Pilha.o $(SRC)/Pilha.cpp

$(OBJ)/Tipoitem.o: $(HDRS) $(SRC)/Tipoitem.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Tipoitem.o $(SRC)/Tipoitem.cpp

$(OBJ)/TipoNo.o: $(HDRS) $(SRC)/TipoNo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TipoNo.o $(SRC)/TipoNo.cpp

debug: $(EXE)
	gdb $(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*
