#include "../include/arvore.h"
using namespace std;

ArvoreSegmentacao::ArvoreSegmentacao() {
    raiz = NULL;
}

void ArvoreSegmentacao::InsereEsquerda(TipoNo* &p, int inicio, int fim) {
    if (p == NULL) {
        return;
    } else {
        TipoNo* NovoNo = new TipoNo(inicio, fim);
        p->esq = NovoNo;
    }
}

void ArvoreSegmentacao::InsereDireita(TipoNo* &p, int inicio, int fim) {
    if (p == NULL) {
        return;
    } else {
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

TipoNo* ArvoreSegmentacao::Getraiz() {
    return raiz;
}

void ArvoreSegmentacao::Setraiz(TipoNo* p) {
    raiz = p;
}


void ArvoreSegmentacao::CalculaResultado(TipoNo* p) {
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

// Função para atualizar
void ArvoreSegmentacao::atualizar(TipoNo*& p, int i, int inicio, int fim, matriz& A) {
    if (p != NULL) {
        if (i < p->inicio || i > p->fim) {
            return;
        }
        if (p->inicio == p->fim) {
            p->item = A;
            return;
        }

        int meio = (inicio + fim) / 2;
        atualizar(p->esq, i, inicio, meio, A);
        atualizar(p->dir, i, meio + 1, fim, A);
    }
    return;
}

matriz ArvoreSegmentacao::consulta(TipoNo*& p, int inicio, int fim) {
    matriz resultado;

    // Verifica se o nó atual é nulo ou está completamente fora do intervalo [inicio, fim]
    if (p == NULL || p->inicio > fim || p->fim < inicio) {
        // Nó completamente fora do intervalo [inicio, fim]
        return matriz();
    }

    // Verifica se o nó atual abrange exatamente o intervalo [inicio, fim]
    if (p->inicio == inicio && p->fim == fim) {
        // Calcula o resultado para o nó atual
        CalculaResultado(p);
        return p->item;
    }

    matriz resultEsq;
    matriz resultDir;

    // Verifica se os filhos à esquerda e à direita são não nulos
    if (p->esq != NULL && p->dir != NULL) {
        // Verifica se a consulta se sobrepõe aos filhos à esquerda e à direita
        if (fim > p->esq->fim && inicio < p->dir->inicio) {
            // Consulta os filhos à esquerda e à direita
            resultEsq = consulta(p->esq, inicio, p->dir->inicio - 1);
            resultDir = consulta(p->dir, p->dir->inicio, fim);
            
            // Multiplica as matrizes dos filhos à esquerda e à direita
            return multiplicaMatrizes(resultEsq, resultDir);
        } else if (fim <= p->esq->fim) {
            // Se a consulta está totalmente à esquerda, consulta apenas o filho à esquerda
            return consulta(p->esq, inicio, fim);
        } else {
            // Se a consulta está totalmente à direita, consulta apenas o filho à direita
            return consulta(p->dir, inicio, fim);
        }
    }

    // Retorna uma matriz vazia se algum dos filhos for nulo
    return matriz();
}





void ArvoreSegmentacao::Limpa() {
    ApagaRecursivo(raiz);
    raiz = NULL;
}

void ArvoreSegmentacao::ApagaRecursivo(TipoNo* p) {
    if (p != NULL) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

ArvoreSegmentacao::~ArvoreSegmentacao() {
    Limpa();
}
