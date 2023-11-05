#include "../include/Grafo.hpp"
#include "verificaGuloso.cpp"

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

//verifica se vertice é guloso
bool Grafo::verificaVertice(int v){
   TipoNo* verticeOrigem = vertices.EncontraVertice(v);
   TipoNo* aux = new TipoNo();
   if (verticeOrigem) {
    int conta_cor = 0;
    for(int i = 0; i < verticeOrigem->TotalConexao(); i++){ //anda pelas conexões do vertice
    int j = verticeOrigem->GetConexao(i); //recebe o vertice conectado
    aux = vertices.EncontraVertice(j);//recebe o nó correspondente ao vertice conectado
    int cores_verificadas[conta_cor]; //guarda as cores ja verificadas
    if(verticeOrigem->GetCor() == conta_cor-1){ //verifica se o vertice está ligado a todas as cores menores que ele
        return true;
    }else if(aux->GetCor() < verticeOrigem->GetCor()){
        if(!busca(cores_verificadas, conta_cor, aux->GetCor())){ //verifica se a cor foi verificada
        cores_verificadas[conta_cor] = aux->GetCor();//adiciona cor verificada no array
        conta_cor++;
        }
    }
    }
   }else{
    //trata vertice inexistente
   }
   return false;
   
}
