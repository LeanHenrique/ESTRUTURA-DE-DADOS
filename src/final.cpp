#include "../include/Pilha.h"
#include <iostream>
#include <string>
using namespace std;


int prioridade(char c) {
    if (c == '~') {
        return 3; // Prioridade absoluta para ~
    }
    if (c == '&') {
        return 2; // Alta prioridade para &
    } else if (c == '|') {
        return 1; // Prioridade menor para |
    } 
    return 0; // Valor padrão para outros caracteres (como parênteses)
}

int Operacao(int a, int b, char op) {
    switch (op) {
        case '&':
            return (a * b);
        case '|':
            if (a == 1 && b == 1) {
                return a;
            }
            return (a + b);
        default:
            throw std::runtime_error("Operador inválido");
    }
}

int negacao(int a) {
    if (a == 0) {
        return 1;
    } else {
        return 0;
    }
}

bool VerificaDigito(char c) {
    return (c >= '0' && c <= '9');
}

int ConverteInteiro(char c){
    return c - '0';
}

string trataexpressao(string p, string s) {
   string resultado;

    for (int i = 0; i < static_cast<int>(p.size()); i++) {
        if (VerificaDigito(p[i])) {
            if (i + 1 < static_cast<int>(p.size()) && VerificaDigito(p[i + 1])) {
                int duploDigito = (p[i] - '0') * 10 + (p[i + 1] - '0');
                resultado += s[duploDigito];
                i++; // Pulando o próximo valor da expressão
            } else {
                int digit = p[i] - '0';
                resultado += s[digit];
            }
        } else {
            resultado += p[i];
        }
    }

    return resultado;
}

PilhaEncadeada posfixa(string p) {
    PilhaEncadeada aux; // Pilha auxiliar para operadores
    PilhaEncadeada pos; // Pilha de saída (resultado)
    TipoItem x , y;

    for (int i = 0; i < static_cast<int>(p.size()); i++) {
        x.SetChave(p[i]);

        switch (p[i]) {
            case '(':
                aux.Empilha(x);
                break; 

            case ')':
                while (!aux.Vazia() && aux.Topo().GetChave() != '(') {
                    // Desempilhando e armazenando as variaveis com valor padrão
                    y = pos.Desempilha();
                    int a = ConverteInteiro(y.GetChave());
                    
                    y = pos.Desempilha();
                    int b = ConverteInteiro(y.GetChave());
                    
                    y = aux.Desempilha();
                    int op = y.GetChave();

                    int c = Operacao(a,b,op);

                    //empilhando as variaveis com valor ASCII
                    y.SetChave(c + '0');
                    pos.Empilha(y);
                }

                if (!aux.Vazia() && aux.Topo().GetChave() == '(') {
                    aux.Desempilha(); // Desempilhar o '('
                }
                break;

            case '~':
            {
                x.SetChave(p[i + 2]);
                int digit = ConverteInteiro(x.GetChave());
                x.SetChave(negacao(digit) + '0');
                pos.Empilha(x);
                i = i+2; // Avance para o próximo caractere (o operando negado)
                break;
            }     

            case '|':
            case '&':
                while (!aux.Vazia() &&  prioridade(aux.Topo().GetChave()) >= prioridade(x.GetChave())) {
                    // Deempilhando e armazenando as variaveis com valor padrão
                    y = pos.Desempilha();
                    int a = ConverteInteiro(y.GetChave());
                    
                    y = pos.Desempilha();
                    int b = ConverteInteiro(y.GetChave());
                    
                    y = aux.Desempilha();
                    int op = y.GetChave();

                    int c = Operacao(a,b,op);

                    //empilhando as variaveis com valor ASCII
                    y.SetChave(c + '0');
                    pos.Empilha(y);
                }
                aux.Empilha(x); // Empilhar o operador na pilha de operadores
                break;
          
            default:
                if (x.GetChave() != ' ') {
                    if ((VerificaDigito(p[i])))
                    {
                        pos.Empilha(x); // Empilhar operandos na pilha de saída

                    }     
                }
                break;
        }
    }

   if(!aux.Vazia()){
                    // Dsempilhando e armazenando as variaveis com valor padrão
                    y = pos.Desempilha();
                    int a = ConverteInteiro(y.GetChave());
                    
                    y = pos.Desempilha();
                    int b = ConverteInteiro(y.GetChave());
                    
                    y = aux.Desempilha();
                    int op = y.GetChave();

                    int c = Operacao(a,b,op);

                    //empilhando as variaveis com valor ASCII
                    y.SetChave(c + '0');
                    pos.Empilha(y);
                } 
   

    return pos; // Retornar a pilha de saída (resultado da expressão pós-fixa)
}

int main() {
    // Teste posfixa
    string expressao = " 0 & ~ 12 | ( 1 & 32 ) & 5 | ( 6 & 7 ) | 8 & 9 ";
    string valores = "010101001100110101001100110110101";
    
    string expressaotratada = trataexpressao(expressao,valores);
    cout << expressaotratada << endl;
    PilhaEncadeada resultado = posfixa(expressaotratada);
    TipoItem x;

    while (!resultado.Vazia()) {
        x = resultado.Desempilha();
        int a = ConverteInteiro(x.GetChave());
        cout << a << " ";
    }

    cout << endl; 

    return 0;
}
