#include "../include/Arvore.h"
#include <iostream>
using namespace std;
ArvoreBinaria::ArvoreBinaria()
{
raiz = NULL;
}


void ArvoreBinaria::InsereEsquerda(TipoNo* &p, const string& combinacao) {
    if(p==NULL){
    return ;  
}      
else{
   TipoNo* NovoNo = new TipoNo();
   NovoNo->item = combinacao;
   p->esq = NovoNo;
}
  
}

void ArvoreBinaria::InsereDireita(TipoNo* &p, const string& combinacao) {
    if(p==NULL){
    return ;  
}      
else{
   TipoNo* NovoNo = new TipoNo();
   NovoNo->item = combinacao;
   p->dir = NovoNo;
}
  
}
  
TipoNo * ArvoreBinaria::Getraiz(){
    return raiz;
}

void ArvoreBinaria::Setraiz(TipoNo *p){
    raiz = p;
}

void ArvoreBinaria::PreOrdem(TipoNo *p){
if(p!=NULL){
cout << p->item << endl;
PreOrdem(p->esq);
PreOrdem(p->dir);
}
}

void ArvoreBinaria::InOrdem(TipoNo *p){
if(p!=NULL){
InOrdem(p->esq);
cout << p->item << endl;
InOrdem(p->dir);
}
}

void ArvoreBinaria::PosOrdem(TipoNo *p){
if(p!=NULL){
PosOrdem(p->esq);
PosOrdem(p->dir);
cout << p->item << endl;
}
}

void ArvoreBinaria::Limpa(){
ApagaRecursivo(raiz);
raiz = NULL;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
if(p!=NULL){
ApagaRecursivo(p->esq);
ApagaRecursivo(p->dir);
delete p;
}
}

ArvoreBinaria::~ArvoreBinaria()
{
Limpa();
}