CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Grafo.o $(OBJ)/ListaAdjascencia.o $(OBJ)/main.o $(OBJ)/verificaGuloso.o $(OBJ)/TipoNo.o
HDRS = $(INC)/Grafo.hpp $(INC)/ListaAdjascencia.hpp $(INC)/TipoNo.hpp $(INC)/verificaGuloso.hpp
CFLAGS = -Wall -g -c -I$(INC)
DEBUG_FLAGS = -g

EXE = $(BIN)/tp1.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/ListaAdjascencia.o: $(HDRS) $(SRC)/ListaAdjascencia.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ListaAdjascencia.o $(SRC)/ListaAdjascencia.cpp

$(OBJ)/Grafo.o: $(HDRS) $(SRC)/Grafo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Grafo.o $(SRC)/Grafo.cpp

$(OBJ)/verificaGuloso.o: $(HDRS) $(SRC)/verificaGuloso.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Arvore.o $(SRC)/Arvore.cpp

$(OBJ)/verificaGuloso.o: $(HDRS) $(SRC)/verificaGuloso.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/verificaGuloso.o $(SRC)/verificaGuloso.cpp

$(OBJ)/TipoNo.o: $(HDRS) $(SRC)/TipoNo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TipoNo.o $(SRC)/TipoNo.cpp

debug: $(EXE)
	gdb $(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*