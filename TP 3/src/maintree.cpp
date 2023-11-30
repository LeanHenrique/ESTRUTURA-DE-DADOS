#include "../include/arvore.h"


int main(){
    ArvoreSegmentacao arvore;
    TipoNo* no = arvore.Getraiz(); 
    arvore.ConstroiArvore(no, 0, 3);

    arvore.InOrdem(no);
}