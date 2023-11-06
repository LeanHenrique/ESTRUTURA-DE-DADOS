#include "../include/Grafo.hpp"
#include "../include/verificaGuloso.hpp"

     
int main(){     
    Grafo meuGrafo;
       // Movida a parte de leitura do grafo para o final
    int n;
    std::cin >> n; // Número de vértices


    for (int i = 0; i < n; ++i) {
        meuGrafo.InsereVertice();
    }
       
    for (int i = 0; i < n; ++i) {
        int m;
         std::cin >> m; // Número de vizinhos do vértice i
        for (int j = 0; j < m; ++j) {
            int vizinho;
            std::cin >> vizinho; // Leitura de cada vizinho do vértice i
            meuGrafo.InsereAresta(i, vizinho);
        }
    } 
    
    int cor;
    int cont = 0;
    while(cont < n){
        std::cin >> cor;
        meuGrafo.InsereCor(cor);
    }
    
    int resultado = verificaGrafo(meuGrafo);

    std::cout << resultado << std::endl;
}
