CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/calculadora.o $(OBJ)/arvore.o $(OBJ)/matriz.o $(OBJ)/TipoNo.o $(OBJ)/maintree.o
HDRS = $(INC)/arvore.h $(INC)/matriz.h $(INC)/TipoNo.h $(INC)/calculadora.h 
CFLAGS = -Wall -g -c -I$(INC)
DEBUG_FLAGS = -g

EXE = $(BIN)/tp3.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/maintree.o: $(HDRS) $(SRC)/maintree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/maintree.o $(SRC)/maintree.cpp

$(OBJ)/calculadora.o: $(HDRS) $(SRC)/calculadora.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/calculadora.o $(SRC)/calculadora.cpp

$(OBJ)/arvore.o: $(HDRS) $(SRC)/arvore.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/arvore.o $(SRC)/arvore.cpp

$(OBJ)/matriz.o: $(HDRS) $(SRC)/matriz.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matriz.o $(SRC)/matriz.cpp

$(OBJ)/TipoNo.o: $(HDRS) $(SRC)/TipoNo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TipoNo.o $(SRC)/TipoNo.cpp

debug: $(EXE)
	gdb $(EXE)

clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*
