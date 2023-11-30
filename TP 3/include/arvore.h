#ifndef ARVOREH
#define ARVOREH
#include "TipoNo.h"
#include "calculadora.h"
#include<string>
#include <iostream>
using namespace std;

class ArvoreSegmentacao
{
public:
ArvoreSegmentacao();
~ArvoreSegmentacao();
void Caminha(int tipo);
void Limpa();
void InsereDireita(TipoNo*& p, int inicio, int fim);
void InsereEsquerda(TipoNo*& p, int inicio, int fim);
void ConstroiArvore(TipoNo* &p, int inicio, int fim);
void ApagaRecursivo(TipoNo* p);
void Setraiz(TipoNo *p);
TipoNo * Getraiz();
void PorNivel();
void PreOrdem(TipoNo* p);
void InOrdem(TipoNo* p);
void CalculaResultado(TipoNo* p);
void atualizar(TipoNo*& p, int inicio, int fim, matriz& A);
matriz consulta(TipoNo*& p, int inicio, int fim, matriz A);
private:
TipoNo *raiz;
};

#endif