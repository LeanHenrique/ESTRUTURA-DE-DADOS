#ifndef CALCULADORAH
#define CALCULADORAH

#include "Pilha.h"
#include<string>
using namespace std;

int prioridade(char c);
int Operacao(int a, int b, char op);
int negacao(int a);
bool VerificaDigito(char c);
int ConverteInteiro(char c);
bool busca(string s, char c);
int OperacaoB(char c, int a, int b);
string guardaQuant(string expressao);
std::string trataexpressao(std::string p, std::string s);
PilhaEncadeada posfixa(std::string p);

#endif // CALCULADORAH
