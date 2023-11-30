// matriz.h

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class matriz {
public:
    matriz();
    void criarMatrizIdentidade();
    void exibirMatriz();
    void setElemento(int linha, int coluna, int valor);
    int getElemento(int linha, int coluna);
    
private:
    int elementos[2][2];
};

#endif
