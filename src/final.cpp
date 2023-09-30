#include "../include/Pilha.h"
#include <iostream>
using namespace std;

int prioridade(char c) {
    if (c == '&') {
        return 2; // Alta prioridade para &
    } else if (c == '|') {
        return 1; // Prioridade menor para |
    } else if (c == '~') {
        return 3; // Maior prioridade para ~
    }
    return 0; // Valor padrão para outros caracteres (como parênteses)
}

int applyBoolOp(int a, int b, char op) {
    switch (op) {
        case '&':
            if (a != b) {
                return 0;
            }
            return a;
        case '|':
            if (a == 1 || b == 1) {
                return 1;
            }
            return 0;
        case '~':
            if (a == 0) {
                return 1;
            }
            return 0;
        default:
            throw runtime_error("Operador inválido");
    }
}

PilhaEncadeada posfixa(string p) {
    PilhaEncadeada aux; // Pilha auxiliar para operadores
    PilhaEncadeada pos; // Pilha de saída (resultado)
    TipoItem x , y;

    for (int i = 0; i < p.size(); i++) {
        x.SetChave(p[i]);

        switch (p[i]) {
            case '(':
                aux.Empilha(x);
                break;

            case ')':
                while (!aux.Vazia() && aux.Topo().GetChave() != '(') {
                    y = pos.Desempilha();
                    int a = y.GetChave();
                    
                    y = pos.Desempilha();
                    int b = y.GetChave();
                    
                    y = aux.Desempilha();
                    int op = y.GetChave();

                    y.SetChave(applyBoolOp(a, b, op));
                    pos.Empilha(y);
                }

                if (!aux.Vazia() && aux.Topo().GetChave() == '(') {
                    aux.Desempilha(); // Desempilhar o '('
                }
                break;

            case '|':
            case '~':
            case '&':
                while (!aux.Vazia() && prioridade(x.GetChave()) <= prioridade(aux.Topo().GetChave())) {
                    y = pos.Desempilha();
                    int a = y.GetChave();
                    
                    y = pos.Desempilha();
                    int b = y.GetChave();
                    
                    y = aux.Desempilha();
                    int op = y.GetChave();

                    y.SetChave(applyBoolOp(a, b, op));
                    pos.Empilha(y); 
                } 

                aux.Empilha(x); // Empilhar o operador na pilha de operadores
                break;
          
            default:
                if (x.GetChave() != ' ') {
                    pos.Empilha(x); // Empilhar operandos na pilha de saída
                }
                break;
        }
    }

   if(!aux.Vazia()){
                     y = pos.Desempilha();
                    int a = y.GetChave();
                    
                    y = pos.Desempilha();
                    int b = y.GetChave();
                    
                    y = aux.Desempilha();
                    int op = y.GetChave();

                    y.SetChave(applyBoolOp(a, b, op));
                    pos.Empilha(y);
                } 
   

    return pos; // Retornar a pilha de saída (resultado da expressão pós-fixa)
}

int main() {
    // Teste posfixa
    string expressao = "1 & 1 & ( 1 & 1 )";
    PilhaEncadeada resultado = posfixa(expressao);
    TipoItem x;

    while (!resultado.Vazia()) {
        x = resultado.Desempilha();
        cout << x.GetChave() << " ";
    }

    cout << endl; 

    return 0;
}
