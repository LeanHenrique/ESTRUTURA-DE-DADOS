// matriz.h

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class matriz {
public:
    matriz();
    void setElemento(int linha, int coluna, long long valor, bool incrementar);
    long long getElemento(int linha, int coluna);
    
private:
    long long elementos[2][2];
};

#endif
