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

//função para criar a arvore de segmentação
void ArvoreSegmentacao::ConstroiArvore(TipoNo* &p, int inicio, int fim){

    if (raiz == NULL){
        raiz = new TipoNo(inicio, fim);
        ConstroiArvore(raiz, inicio, fim);   
    }

    //gera matriz identidade
    matriz novaMatriz;
    novaMatriz = Matrizidentidade(novaMatriz);

    
    if(inicio == fim){
        p->item = novaMatriz;
        return;
    }
    
    int meio = (inicio + fim) / 2;
    InsereEsquerda(p, inicio, meio);
    TipoNo* paiEsq = p->esq;
    ConstroiArvore(paiEsq, inicio, meio);
    
    InsereDireita(p,meio + 1, fim);
    TipoNo* paiDir = p->dir;
    ConstroiArvore(paiDir, meio + 1, fim);

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