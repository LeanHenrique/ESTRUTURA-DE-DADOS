#ifndef ARVOREH
#define ARVOREH
#include "../include/TipoItem.h"
#include "../include/TipoNo.h"
#include<string>
using namespace std;

class ArvoreBinaria
{
public:
ArvoreBinaria();
~ArvoreBinaria();
void Caminha(int tipo);
void Limpa();
void InsereDireita(TipoNo*& p, const string& combinacao);
void InsereEsquerda(TipoNo*& p, const string& combinacao);
void ApagaRecursivo(TipoNo* p);
void Setraiz(TipoNo *p);
TipoNo * Getraiz();
void PorNivel();
void PreOrdem(TipoNo* p);
void InOrdem(TipoNo* p);
void PosOrdem(TipoNo* p);
private:
TipoNo *raiz;
};

#endif