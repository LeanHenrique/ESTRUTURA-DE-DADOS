#ifndef TIPONOH
#define TIPONOH
#include "matriz.h"
#include <string>
#include <iostream>
using namespace std;

class TipoNo
{
public:
TipoNo();
TipoNo(int inicio, int fim);
void SetItem(matriz item);
matriz GetItem();
TipoNo* GetEsq();
TipoNo* GetDir();
private:
int inicio, fim;
matriz item;
TipoNo *esq;
TipoNo *dir;
friend class ArvoreSegmentacao;
};

#endif