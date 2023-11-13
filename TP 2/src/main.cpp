#include "../include/Grafo.hpp"
#include "../include/verificaGuloso.hpp"
#include "../include/MetodosOrdenacao.hpp"
#include "../include/TipoVertice.hpp"
#include "../include/memlog.hpp"

int main() {
    Grafo meuGrafo;

    // Movida a parte de leitura do grafo para o final
    int n;
    char metodo;
    std::cin >> metodo >> n; // Número de vértices
    vertices* MeusVertices = new vertices[n];

    for (int i = 0; i < n; ++i) {
        meuGrafo.InsereVertice();
        MeusVertices[i].setGrau(i);
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
    for (int i = 0; i < n; ++i) {
        std::cin >> cor;
        MeusVertices[i].setCor(cor);
        meuGrafo.InsereCor(cor);
    }

    int resultado = verificaGrafo(meuGrafo);

    char lognome[100] = "/tmp/lean.out";
    int regmem = 1;

    iniciaMemLog(lognome);

    if(regmem) ativaMemLog();
    else desativaMemLog();

    defineFaseMemLog(0);
    if (resultado == 1) {
        switch (metodo) {
            case 'b':
                defineFaseMemLog(0);
                BubbleSort(MeusVertices, n);
                break;

            case 's':
                defineFaseMemLog(0);
                SelectionSort(MeusVertices, n);
                break;

            case 'i':
                defineFaseMemLog(0);
                InsertionSort(MeusVertices, n);
                break;

            case 'q':
                defineFaseMemLog(0);
                QuickSort(MeusVertices, n);
                break;

            case 'm':
                defineFaseMemLog(0);
                mergeSort(MeusVertices, 0, n - 1);
                break;

            case 'p':
                defineFaseMemLog(0);
                HeapSort(MeusVertices, n);
                break;

            case 'y':
                defineFaseMemLog(0);
                MeuSort(MeusVertices, n);
                break;

            default:
                break;
        }

        std::cout << resultado << " ";
        for (int i = 0; i < n; i++) {
            std::cout << MeusVertices[i].getGrau() << " " ;
        }
        std::cout << std::endl;
    } else {
        std::cout << resultado << std::endl;
    }
    delete[] MeusVertices;
    return 0;
}
