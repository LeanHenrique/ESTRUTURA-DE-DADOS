#include "Pilha.h"
#include<iostream>

TipoCelula::TipoCelula()
{
item.SetChave(-1);
prox = NULL;
}

PilhaEncadeada::PilhaEncadeada() : Pilha()
{
topo = NULL;
}

void PilhaEncadeada::Empilha(TipoItem item){
TipoCelula *nova;
nova = new TipoCelula();
nova->item = item;
nova->prox = topo;
topo = nova;
tamanho++;
};

TipoItem PilhaEncadeada::Desempilha(){
TipoItem aux; TipoCelula *p;
if(tamanho == 0)
throw "A pilha está vazia!";
aux = topo->item;
p = topo;
topo = topo->prox;
delete p;
tamanho--;
return aux;
};

TipoItem PilhaEncadeada::Topo() {
    TipoItem aux;
        if (Vazia()) {
            throw "A pilha está vazia!";
        }
        aux = topo->item;
        return aux;
    }


void PilhaEncadeada::Limpa(){
while(!Vazia())
Desempilha();
} 

PilhaEncadeada::~PilhaEncadeada()
{
Limpa();
}