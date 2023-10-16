#include "../include/TipoNo.h"


TipoNo::TipoNo()
{
item = "";
esq = NULL;
dir = NULL;
TotalConexoes = 0;
for (int i = 0; i < MAX_EXPRESSOES; i++) {
            expressoes[i] = "";  // Inicialize com strings vazias
        }
}

void TipoNo::SetItem(string s){
    item = s;
}

string TipoNo::GetItem(){
  return item;
}

string TipoNo::GetExpressao(int i) {
     if (i >= 0 && i < TotalConexoes) {
        return expressoes[i];
    }
    return ""; // Retorna -1 se o índice estiver fora dos limites
}

void TipoNo::SetExpressao(string d) {
     if (TotalConexoes < MAX_EXPRESSOES) { // Verifica se há espaço para adicionar mais conexões
        expressoes[TotalConexoes] = d;
        TotalConexoes++;
    } else {
        std::cerr << "Limite máximo de conexões atingido." << std::endl;
    }
}

int TipoNo::GetTotalConexoes(){
    return TotalConexoes;
}

TipoNo* TipoNo::GetDir(){
    return dir;
}

TipoNo* TipoNo::GetEsq(){
    return esq;
}

