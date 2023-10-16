#include "../include/TipoNo.h"
#include <iostream>

using namespace std;

TipoNo::TipoNo()
{
item = "";
esq = NULL;
dir = NULL;
}

void TipoNo::SetItem(string s){
    item = s;
}

string TipoNo::GetItem(){
  return item;
}

void TipoNo::SetResultado(char s){
    resultado = s;
}

char TipoNo::GetResultado(){
  return resultado;
}

TipoNo* TipoNo::GetDir(){
    return dir;
}

TipoNo* TipoNo::GetEsq(){
    return esq;
}

