CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Grafo.o $(OBJ)/ListaAdjascencia.o $(OBJ)/main.o $(OBJ)/verificaGuloso.o $(OBJ)/TipoNo.o $(OBJ)/MetodosOrdenacao.o $(OBJ)/TipoVertice.o $(OBJ)/memlog.o
HDRS = $(INC)/Grafo.hpp $(INC)/ListaAdjascencia.hpp $(INC)/TipoNo.hpp $(INC)/verificaGuloso.hpp $(INC)/MetodosOrdenacao.hpp $(INC)/TipoVertice.hpp $(INC)/memlog.hpp $(INC)/msgassert.hpp
CFLAGS = -Wall -g -c -I$(INC)
DEBUG_FLAGS = -g

EXE = $(BIN)/tp2.out

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
	$(CC) $(CFLAGS) -o $(OBJ)/verificaGuloso.o $(SRC)/verificaGuloso.cpp

$(OBJ)/TipoNo.o: $(HDRS) $(SRC)/TipoNo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TipoNo.o $(SRC)/TipoNo.cpp

$(OBJ)/MetodosOrdenacao.o: $(HDRS) $(SRC)/MetodosOrdenacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/MetodosOrdenacao.o $(SRC)/MetodosOrdenacao.cpp	

$(OBJ)/TipoVertice.o: $(HDRS) $(SRC)/TipoVertice.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TipoVertice.o $(SRC)/TipoVertice.cpp	

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp	

cachegrind: $(EXE)
	valgrind --tool=cachegrind ./$(EXE)

debug: $(EXE)
	gdb $(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*