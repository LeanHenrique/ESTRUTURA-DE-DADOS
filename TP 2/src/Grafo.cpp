#include "../include/Grafo.hpp"

Grafo::Grafo() {
}

Grafo::~Grafo() {
}

void Grafo::InsereVertice() {
    vertices.InsereVertice();
}

void Grafo::InsereAresta(int v, int w) {
   vertices.InsereAresta(v,w);
}

void Grafo::InsereCor(int c){
    vertices.InsereCor(c);
}

ListaAdjascencia Grafo::GetVertices(){
    return vertices;
}

int Grafo::QuantidadeVertices() {
    return vertices.GetTotalVertices();
}

int Grafo::QuantidadeArestas() {
    return vertices.GetTotalArestas();
}



