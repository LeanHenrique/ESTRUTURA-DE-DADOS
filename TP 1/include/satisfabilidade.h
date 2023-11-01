#ifndef SATISFABILIDADEH
#define SATISFABILIDADEH

#include "Arvore.h" // Certifique-se de incluir o cabeçalho da sua classe ArvoreBinaria aqui.
#include "Calculadora.h"
#include <iostream>
using namespace std;

// Função para calcular o nível de um nó em uma árvore.
int calcularNivelDoNo(TipoNo* raiz, TipoNo* noAlvo, int nivelAtual);

// Função para configurar todas as combinações possíveis em uma árvore.
void setCombinacoes(ArvoreBinaria& arvore, TipoNo*& pai, std::string expressao);

// Função para calcular os resultados das folhas na árvore.
void calcularResultadosFolhas(ArvoreBinaria& arvore, TipoNo* no, std::string expressao);

// Função para calcular resultados das expressões em pós-ordem.
void calcularResultadosExpressoes(ArvoreBinaria& arvore, TipoNo* no, std::string quant);

// Função para verificar a expressão possível.
string verificaPossivel(ArvoreBinaria& arvore, TipoNo* raiz, std::string quant, string valores);

#endif
