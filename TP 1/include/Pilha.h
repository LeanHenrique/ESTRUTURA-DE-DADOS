#ifndef PILHAH 
#define PILHAH

#include "TipoItem.h"
#include<iostream>
using namespace std;


class TipoCelula
{
public:
TipoCelula();
private:
TipoItem item;
TipoCelula *prox;
friend class PilhaEncadeada;
};

class Pilha
{
public:
Pilha(){tamanho = 0;};
int GetTamanho() {return tamanho;};
bool Vazia() {return tamanho == 0;};
virtual void Empilha(TipoItem item) = 0;
virtual TipoItem Desempilha() = 0;
virtual void Limpa() = 0;
protected:
int tamanho;
};

class PilhaEncadeada : public Pilha
{
public:
    PilhaEncadeada();
    virtual ~PilhaEncadeada();
    void Empilha(TipoItem item);
    TipoItem Topo();
    TipoItem Desempilha();
    void Limpa();

private:
    TipoCelula* topo;
};

#endif 
