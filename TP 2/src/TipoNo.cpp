#include "../include/TipoNo.hpp"
#include <iostream>

TipoNo::TipoNo() {
    item = 0;
    proximo = nullptr;
    TotalConexoes = 0;
    cor = 0;
}

int TipoNo::GetItem() {
    return item;
}

TipoNo* TipoNo::GetProximo() {
    return proximo;
}

void TipoNo::SetProximo(TipoNo* prox) {
    proximo = prox;
}

int TipoNo::GetConexao(int i) {
     if (i >= 0 && i < TotalConexoes) {
        return conexao[i];
    }
    return -1; // Retorna -1 se o índice estiver fora dos limites
}

void TipoNo::SetConexao(int d) {
     if (TotalConexoes < MAX_CONEXOES) { // Verifica se há espaço para adicionar mais conexões
        conexao[TotalConexoes] = d;
        TotalConexoes++;
    } else {
        std::cerr << "Limite máximo de conexões atingido." << std::endl;
    }
}

void TipoNo::SetCor(int c){
   cor = c;
}

int TipoNo::GetCor(){
    return cor;
}

int TipoNo::TotalConexao(){
    return TotalConexoes;
}

