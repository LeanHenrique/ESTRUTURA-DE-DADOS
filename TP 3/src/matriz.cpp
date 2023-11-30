#include "../include/matriz.h"

matriz::matriz(){
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                elementos[i][j] = 0;
            }
        }
}

void matriz::setElemento(int linha, int coluna, int valor) {
    if (linha >= 0 && linha < 2 && coluna >= 0 && coluna < 2) {
        elementos[linha][coluna] = valor;
    } else {
        std::cerr << "Índices inválidos!" << std::endl;
    }
}

int matriz::getElemento(int linha, int coluna) {
    if (linha >= 0 && linha < 2 && coluna >= 0 && coluna < 2) {
        return elementos[linha][coluna];
    } else {
        std::cerr << "Índices inválidos!" << std::endl;
        return -1;  // Valor de erro
    }
}