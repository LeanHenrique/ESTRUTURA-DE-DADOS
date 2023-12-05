#include "../include/calculadora.h"

// Função para criar matriz identidade
matriz Matrizidentidade() {
    matriz identidade;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == j) {
                identidade.setElemento(i, j, 1, false);
            } else {
                identidade.setElemento(i, j, 0, false);
            }
        }
    }
    return identidade;
}

matriz multiplicaMatrizes(matriz A, matriz B) {
    matriz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            long long int valorAtual = 0;
            for (int k = 0; k < 2; ++k) {
                valorAtual += (A.getElemento(i, k) * B.getElemento(k, j));
            }
            // Obter apenas o dígito mais significativo
            valorAtual %= 100000000;
            result.setElemento(i, j, valorAtual, false);
        }
    }
    return result;
}
