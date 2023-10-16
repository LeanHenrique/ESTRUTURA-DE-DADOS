#include "../include/Calculadora.h"
#include "../include/Arvore.h"
#include <iostream>
#include <string>
using namespace std;

int calcularNivelDoNo(TipoNo* raiz, TipoNo* noAlvo, int nivelAtual) {
    if (raiz == NULL) {
        return -1;  // Nó não encontrado na árvore.
    }
    if (raiz == noAlvo) {
        return nivelAtual;
    }
    
    int nivelEsq = calcularNivelDoNo(raiz->GetEsq(), noAlvo, nivelAtual + 1);
    if (nivelEsq != -1) {
        return nivelEsq;
    }
    
    int nivelDir = calcularNivelDoNo(raiz->GetDir(), noAlvo, nivelAtual + 1);
    return nivelDir;
}


//guarda todas as combinações possiveis na arvore, incluindo as intermediárias
void setCombinacoes(ArvoreBinaria& arvore, TipoNo*& pai, string expressao) {
    if (arvore.Getraiz() == NULL) {
        arvore.Setraiz(new TipoNo());
        arvore.Getraiz()->SetItem(expressao);
        TipoNo* raiz = arvore.Getraiz();
        setCombinacoes(arvore, raiz, expressao);
    } else {
        while (busca(expressao, 'a') || busca(expressao, 'e')) {
            int it = 0;
            string itemesq = expressao;
            string itemdir = expressao;
            while (it < static_cast<int>(expressao.size()) && (itemesq[it] != 'a' && itemesq[it] != 'e' && itemdir[it] != 'a' && itemdir[it] != 'e')) {
                it++;
            }

            if (it < static_cast<int>(expressao.size())) {
                itemdir[it] = '0';
                
                itemesq[it] = '1';
            }

            arvore.InsereEsquerda(pai, itemesq);
            TipoNo* paiEsq = pai->GetEsq();
            setCombinacoes(arvore, paiEsq, itemesq);
            arvore.InsereDireita(pai, itemdir);
            TipoNo* paiDir = pai->GetDir();
            setCombinacoes(arvore, paiDir, itemdir);
            break;
        }
        // Adicione uma condição de parada aqui, se necessário.
    }
}

// Função para calcular o resultado de todas as folhas na árvore
void calcularResultadosFolhas(ArvoreBinaria& arvore, TipoNo* no, string expressao) {
    if(no->GetDir() != NULL){
        calcularResultadosFolhas(arvore,no->GetDir(), expressao);
        calcularResultadosFolhas(arvore,no->GetEsq(), expressao);
    } else{

        string valores = no->GetItem();
        string aux = trataexpressao(expressao, valores);
        PilhaEncadeada resultado = posfixa(aux);

        string r = "";
        TipoItem x;

            x = resultado.Desempilha();
            r += x.GetChave();
   
     
        // Atualiza o valor do nó na árvore com o resultado da expressão
        no->SetItem(r);
    }
}



// Função para calcular resultados das expressões em pós-ordem
void calcularResultadosExpressoes(ArvoreBinaria& arvore, TipoNo* no, string quant) {
    if (no == NULL) {
        return; // Verificação de nó nulo.
    }

    // Primeiro, calcule os resultados dos filhos esquerdo e direito
    calcularResultadosExpressoes(arvore, no->GetEsq(),quant);
    calcularResultadosExpressoes(arvore, no->GetDir(),quant);

    if(no->GetItem() != "1" && no->GetItem()!="0"){
    int nivel = calcularNivelDoNo(arvore.Getraiz(),no, 0);
    
        char operador = quant[nivel];
        string FilhoEsquerdo = no->GetEsq()->GetItem();
        string FilhoDireito = no->GetDir()->GetItem();
        int FE = ConverteInteiro(FilhoEsquerdo[0]);
        int FD = ConverteInteiro(FilhoDireito[0]);

        int result = OperacaoB(operador, FE, FD);
        char r = result + '0';
        string item = "";
        item += r;
        
        // Atualize o valor do nó na árvore com o resultado da expressão
        no->SetItem(item);
    }

}


int main() {
    ArvoreBinaria arvore;
    TipoNo *p = new TipoNo();
    std::string valores = "0e0";
    string expressao= "0 | 1 & 2";

    string quant = guardaQuant(valores);
    setCombinacoes(arvore,p, valores);
    calcularResultadosFolhas(arvore,arvore.Getraiz(),expressao);
    calcularResultadosExpressoes(arvore,arvore.Getraiz(),quant);




    // Agora, a árvore contém todas as combinações da expressão "00XX1".

    // Você pode usar a função InOrdem da sua classe para imprimir as combinações.
    std::cout << "Combinações possíveis da expressão " << expressao << ":" << std::endl;
    arvore.PreOrdem(arvore.Getraiz());

    return 0;
}