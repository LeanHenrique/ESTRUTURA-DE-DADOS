#ifndef LISTAADJACENCIAH
#define LISTAADJACENCIAH
#include "TipoNo.hpp"
#include <iostream>

class ListaAdjascencia{
public:
ListaAdjascencia();
~ListaAdjascencia();
 
void InsereVertice();
void InsereAresta(int v, int w);
int GetTotalVertices();
int GetTotalArestas();
TipoNo* EncontraVertice(int valor);
int contador;

private:
TipoNo* primeiro;
TipoNo* ultimo;

int TotalVertices;
int TotalArestas;

};

#endif