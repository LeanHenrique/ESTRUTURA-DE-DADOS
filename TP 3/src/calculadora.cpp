#include "../include/calculadora.h"

//função para criar matriz identidade
matriz Matrizidentidade(matriz matriz){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(i == j) {
                matriz.setElemento(i, j , 1);
            }else{
           matriz.setElemento(i, j, 0);
         }
        }
    }
    return matriz;
}


 

    