#include "../include/matriz.h"

// Construtor da classe matriz
matriz::matriz() {
    // Inicializa todos os elementos da matriz com 0
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            elementos[i][j] = 0;
        }
    }
}

// Função para definir um elemento da matriz
void matriz::setElemento(int linha, int coluna, long long valor, bool incrementar) {
    if (linha >= 0 && linha < 2 && coluna >= 0 && coluna < 2) {
        if (incrementar) {
            // Incrementa o valor existente
            elementos[linha][coluna] += valor;
        } else {
            // Define o valor sem incrementar
            elementos[linha][coluna] = valor;
        }
    } else {
        // Mensagem de erro para índices inválidos
        std::cerr << "Índices inválidos!" << std::endl;
    }
}

// Função para obter um elemento da matriz
long long matriz::getElemento(int linha, int coluna) {
    if (linha >= 0 && linha < 2 && coluna >= 0 && coluna < 2) {
        // Retorna o valor do elemento
        return elementos[linha][coluna];
    } else {
        // Mensagem de erro para índices inválidos e retorna um valor de erro
        std::cerr << "Índices inválidos!" << std::endl;
        return -1;  // Valor de erro
    }
}
