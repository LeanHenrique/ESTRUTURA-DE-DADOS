#include "../include/TipoNo.h"


TipoNo::TipoNo()
{
esq = NULL;
dir = NULL;
inicio = 0;
fim = 0;

}

TipoNo::TipoNo(int i, int f){
  esq = NULL;
  dir = NULL;
  inicio = i;
  fim = f;

}

void TipoNo::SetItem(matriz m){
    item = m;
}

matriz TipoNo::GetItem(){
  return item;
}

TipoNo* TipoNo::GetDir(){
    return dir;
}

TipoNo* TipoNo::GetEsq(){
    return esq;
}
