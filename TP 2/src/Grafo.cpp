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

int Grafo::QuantidadeVertices() {
    return vertices.GetTotalVertices();
}

int Grafo::QuantidadeArestas() {
    return vertices.GetTotalArestas();
}

int Grafo::GrauMinimo() {
    int grauMinimo = INT_MAX; // Inicializa com um valor muito alto

    for (int i = 0; i < vertices.GetTotalVertices(); ++i) {
        TipoNo* atual = vertices.EncontraVertice(i);
        int grauAtual = atual->TotalConexao();

        if (grauAtual < grauMinimo) {
            grauMinimo = grauAtual;
        }
    }

    return grauMinimo;
}

int Grafo::GrauMaximo() {
   int grauMaximo = INT_MIN; // Inicializa com um valor muito baixo

    for (int i = 0; i < vertices.GetTotalVertices(); ++i) {
        TipoNo* atual = vertices.EncontraVertice(i);
        int grauAtual = atual->TotalConexao();

        if (grauAtual > grauMaximo) {
            grauMaximo = grauAtual;
        }
    }

    return grauMaximo;
}

void Grafo::ImprimeVizinhos(int v) {
    if (v >= 0 && v < vertices.GetTotalVertices()) {
        TipoNo* atual = vertices.EncontraVertice(v);

        for(int i = 0; i < atual->TotalConexao(); i++){
            std::cout << atual->GetConexao(i) << " ";
        }

        std::cout << std::endl;
    } 
}