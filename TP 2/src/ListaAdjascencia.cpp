
#include "../include/ListaAdjascencia.hpp"


ListaAdjascencia::ListaAdjascencia() {
    primeiro = nullptr;
    ultimo = nullptr;
    TotalVertices = 0;
    TotalArestas = 0;
}

ListaAdjascencia::~ListaAdjascencia() {
}

void ListaAdjascencia::InsereVertice() {
    TipoNo* novo = new TipoNo();
    novo->item = TotalVertices;
    
    
    if (!primeiro) {
        primeiro = novo;
        ultimo = novo;
    } else {
        ultimo->SetProximo(novo);
        ultimo = novo;
    }
    
    TotalVertices++;
}

void ListaAdjascencia::InsereAresta(int o, int d){
    TipoNo* verticeOrigem = EncontraVertice(o);

    if (verticeOrigem) {
        if (verticeOrigem->GetConexao(d) == -1) { // Verifica se a conexão não existe
            verticeOrigem->SetConexao(d); // Adiciona a conexão
            TotalArestas++;
        }
    } else {
        // Lida com o caso em que o vértice de origem não existe.
    }
}

void ListaAdjascencia::InsereCor(int c){
       TipoNo* atual = primeiro;
       while(atual != nullptr){
        if(atual->GetCor() != 0){
            atual = atual->GetProximo();
        }else{
        atual->SetCor(c);
       }
}
}

TipoNo* ListaAdjascencia::GetPrimeiro(){
    return primeiro;
}

TipoNo* ListaAdjascencia::EncontraVertice(int valor) {
    TipoNo* atual = primeiro;
    while (atual) {
        if (atual->GetItem() == valor) {
            return atual;
        }
        atual = atual->GetProximo();
    }
    return nullptr; // Vértice não encontrado
}

int ListaAdjascencia::GetTotalVertices(){
    return TotalVertices;
}

int ListaAdjascencia::GetTotalArestas(){
    return TotalArestas/2;
}

