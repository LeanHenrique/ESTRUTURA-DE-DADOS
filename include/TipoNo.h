#ifndef TIPONOH
#define TIPONOH
#include "../include/TipoItem.h"

class TipoNo
{
public:
TipoNo();
private:
TipoItem item;
TipoNo *esq;
TipoNo *dir;
friend class ArvoreBinaria;
};

#endif