#include "../include/TipoVertice.hpp"

vertices::vertices(){
    grau = 0;
    cor = 0;
}

void vertices::setGrau(int g){
   grau = g;
}

int vertices::getGrau(){
    return grau;
}

void vertices::setCor(int c){
    cor = c;
}

int vertices::getCor(){
    return cor;
}