#include "../include/arvore.h"
using namespace std;

ArvoreSegmentacao::ArvoreSegmentacao()
{
raiz = NULL;
}


void ArvoreSegmentacao::InsereEsquerda(TipoNo* &p, int inicio, int fim) {
    if(p==NULL){
    return ;  
}      
else{
   TipoNo* NovoNo = new TipoNo(inicio, fim);
   p->esq = NovoNo;
}
  
}

void ArvoreSegmentacao::InsereDireita(TipoNo* &p, int inicio, int fim) {
    if(p==NULL){
    return ;  
}      
else{
   TipoNo* NovoNo = new TipoNo(inicio, fim);
   p->dir = NovoNo;
}
  
}

void ArvoreSegmentacao::ConstroiArvore(TipoNo* &p, int inicio, int fim) {
    if (p == NULL) {
        p = new TipoNo(inicio, fim);
    }

    if (inicio == fim) {
        // Gera matriz identidade
        matriz novaMatriz;
        novaMatriz = Matrizidentidade();
        p->item = novaMatriz;
        return;
    }

    int meio = (inicio + fim) / 2;
    
    InsereEsquerda(p, inicio, meio);
    ConstroiArvore(p->esq, inicio, meio);
    
    InsereDireita(p, meio + 1, fim);
    ConstroiArvore(p->dir, meio + 1, fim);
}

  
TipoNo * ArvoreSegmentacao::Getraiz(){
    return raiz;
}

void ArvoreSegmentacao::Setraiz(TipoNo *p){
    raiz = p;
}

void ArvoreSegmentacao::InOrdem(TipoNo *p){
if(p!=NULL){
InOrdem(p->esq);
std::cout << "[ " << p->inicio << "," << p->fim << " ]" << endl;
InOrdem(p->dir);
}
}

void ArvoreSegmentacao::CalculaResultado(TipoNo *p) {
    if (p != NULL) {
        // Calcula os itens dos filhos recursivamente
        CalculaResultado(p->esq);
        CalculaResultado(p->dir);

        // Realiza o cálculo para o nó atual
        if (p->esq != NULL && p->dir != NULL) {
            p->item = multiplicaMatrizes(p->esq->item, p->dir->item);
        }
    }
}

// Função para atualizar (corrigida)
void ArvoreSegmentacao::atualizar(TipoNo*& p, int inicio, int fim, matriz& A) {
    if (p != NULL) {
        if(p->inicio == inicio && p->fim == fim){
           p->item = A;
           CalculaResultado(raiz); 
           return;
        }
        atualizar(p->esq, inicio, fim, A);

        atualizar(p->dir, inicio, fim, A);
    }
}

matriz ArvoreSegmentacao::consulta(TipoNo*& p, int inicio, int fim, matriz A){
    matriz result;
        if (p != NULL) {
        if(p->inicio == inicio && p->fim == fim){
           result = multiplicaMatrizes(p->item, A);
           return result;
        }
        consulta(p->esq, inicio, fim, A);
        consulta(p->dir, inicio, fim, A);
    }
   return result;
}



void ArvoreSegmentacao::Limpa(){
ApagaRecursivo(raiz);
raiz = NULL;
}

void ArvoreSegmentacao::ApagaRecursivo(TipoNo *p){
if(p!=NULL){
ApagaRecursivo(p->esq);
ApagaRecursivo(p->dir);
delete p;
}
}

ArvoreSegmentacao::~ArvoreSegmentacao()
{
 Limpa();
}