#ifndef TIPONOH
#define TIPONOH
#include <string>
using namespace std;

class TipoNo
{
public:
TipoNo();
void SetItem(string item);
string GetItem();
void SetResultado(char resultado);
char GetResultado();
TipoNo* GetEsq();
TipoNo* GetDir();
private:
char resultado;
string item;
TipoNo *esq;
TipoNo *dir;
friend class ArvoreBinaria;
};

#endif