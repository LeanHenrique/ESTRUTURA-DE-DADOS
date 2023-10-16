#ifndef TIPONOH
#define TIPONOH
#include <string>
#include <iostream>
using namespace std;
const int MAX_EXPRESSOES = 32;

class TipoNo
{
public:
TipoNo();
void SetItem(string item);
string GetItem();
void SetExpressao(string d);
string GetExpressao(int i);
int GetTotalConexoes();
TipoNo* GetEsq();
TipoNo* GetDir();
private:
string expressoes[MAX_EXPRESSOES];
int TotalConexoes;
string item;
TipoNo *esq;
TipoNo *dir;
friend class ArvoreBinaria;
};

#endif