#ifndef GRAFOH
#define GRAFOH
#include <iostream>
#include <climits> 
#include "ListaAdjascencia.hpp"

class Grafo{
    public:
        Grafo();
        ~Grafo();
        void InsereVertice();
        void InsereAresta(int v, int w);
        void InsereCor(int c);
        ListaAdjascencia GetVertices();
        int QuantidadeVertices();
        int QuantidadeArestas();
        int GrauMinimo();
        int GrauMaximo();
        void ImprimeVizinhos(int v);
    private:
        ListaAdjascencia vertices;
};

#endif