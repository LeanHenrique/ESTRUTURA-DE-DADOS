#include "../include/Pilha.h"
#include <iostream>
using namespace std;

int prioridade(char c){
    if (c == '&') {
        return 2; // Alta prioridade para &
    } else if (c == '|') {
        return 1; // Prioridade menor para |
    } else if (c == '~') {
        return 3; // Maior prioridade para ~
    return 0; // Valor padrão para outros caracteres (como parênteses)
}
}

PilhaEncadeada posfixa(string p) {
    PilhaEncadeada aux; // Pilha auxiliar para operadores
    PilhaEncadeada pos; // Pilha de saída (resultado)
    TipoItem x;

    for (int i = 0; i < p.size(); i++) {
        x.SetChave(p[i]);

        switch (p[i]) {
            case '(':
                aux.Empilha(x);
                break; // Adicione o break para sair do switch após empilhar '('

            case ')':
                while (!aux.Vazia() && aux.Topo().GetChave() != '(') {
                    x = aux.Desempilha();
                    pos.Empilha(x);
                }
                // Aqui, você deve verificar se o '(' foi encontrado na pilha auxiliar e desempilhá-lo, se necessário.
                if (!aux.Vazia() && aux.Topo().GetChave() == '(') {
                    aux.Desempilha(); // Desempilhar o '('
                }
                aux.Empilha(x);
                break;
            
            case '~':
                while ((!aux.Vazia() && aux.Topo().GetChave() != '(' ) && prioridade(x.GetChave()) >= prioridade(aux.Topo().GetChave())) {
                    x = aux.Desempilha();
                    pos.Empilha(x);
                }
                // Aqui, você deve verificar se o '(' foi encontrado na pilha auxiliar e desempilhá-lo, se necessário.
                if ((!aux.Vazia() && aux.Topo().GetChave() == '(') || prioridade(x.GetChave()) <= prioridade(aux.Topo().GetChave())){
                    aux.Desempilha(); // Desempilhar o '(' ou '|'
                }
                aux.Empilha(x);
                break;

            case '&':
                while ((!aux.Vazia() && aux.Topo().GetChave() != '(' ) && prioridade(x.GetChave()) >= prioridade(aux.Topo().GetChave())) {
                    x = aux.Desempilha();
                    pos.Empilha(x);
                }
                // Aqui, você deve verificar se o '(' foi encontrado na pilha auxiliar e desempilhá-lo, se necessário.
                if ((!aux.Vazia() && aux.Topo().GetChave() == '(') || prioridade(x.GetChave()) <= prioridade(aux.Topo().GetChave())){
                    aux.Desempilha(); // Desempilhar o '(' ou '|'
                }
                aux.Empilha(x);
                break;
            
            case '|':
                while (!aux.Vazia() && aux.Topo().GetChave() != '(' ) {
                    x = aux.Desempilha();
                    pos.Empilha(x);
                }
                // Aqui, você deve verificar se o '(' foi encontrado na pilha auxiliar e desempilhá-lo, se necessário.
                if (!aux.Vazia() && aux.Topo().GetChave() == '(') {
                    aux.Desempilha(); // Desempilhar o '('
                }
                break;        

            default:
                if(x.GetChave() != ' '){
                  pos.Empilha(x);
                }
                break;
        }
    }

    // Aqui, você deve verificar se há algum operador restante na pilha auxiliar e empilhá-lo na pilha de saída, se necessário.

    return pos; // Retornar a pilha de saída (resultado da expressão pós-fixa)
}

int main() {

    //teste posfixa
    string expressao = "1 & ~ 2 | ( 1 & 0 )";
    PilhaEncadeada resultado = posfixa(expressao);
    TipoItem x;

    while(!resultado.Vazia()){
        x = resultado.Desempilha();
        x.Imprime();
    }

    return 0;
}
