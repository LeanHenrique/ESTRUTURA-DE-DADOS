#include "../include/memlog.hpp"  // Certifique-se de incluir o cabeçalho correto
#include "../include/Grafo.hpp"
#include "../include/verificaGuloso.hpp"
#include "../include/msgassert.hpp"
#include <iostream>


bool busca(const int array[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == valor) {
            return true; // Valor encontrado no array
        }
    }

    return false; // Valor não encontrado no array
}

bool verificaVertice(Grafo& meuGrafo, int v) {
    // Registra o acesso à memória no início da função
    LEMEMLOG(0, sizeof(Grafo), 0);

    TipoNo* verticeOrigem = meuGrafo.GetVertices().EncontraVertice(v);
    TipoNo* aux;
    int conta_cor = 0;
    int totconexoes = verticeOrigem->TotalConexao();
    int* cores_verificadas = new int[totconexoes]();

    if (verticeOrigem) {
        // Registra o acesso à memória antes do primeiro if
        LEMEMLOG(sizeof(Grafo), sizeof(TipoNo), 0);

        if (verticeOrigem->GetCor() != 1) { // verifica se é igual a 1
            for (int i = 0; i < verticeOrigem->TotalConexao(); i++) { // anda pelas conexões do vértice
                int j = verticeOrigem->GetConexao(i); // recebe o vértice conectado
                aux = meuGrafo.GetVertices().EncontraVertice(j); // recebe o nó correspondente ao vértice conectado

                // Registra o acesso à memória dentro do loop
                LEMEMLOG(sizeof(Grafo) + i * sizeof(int), sizeof(int), 0);
                LEMEMLOG(sizeof(Grafo) + verticeOrigem->TotalConexao() * sizeof(int), sizeof(TipoNo), 0);

                if (aux->GetCor() < verticeOrigem->GetCor()) {
                    if (!busca(cores_verificadas, verticeOrigem->TotalConexao(), aux->GetCor())) {
                        cores_verificadas[conta_cor] = aux->GetCor();
                        conta_cor++;
                    }
                }
            }
        } else {
            // caso for igual a 1, retorna true
            delete[] cores_verificadas;  // Libera a memória antes de retornar
            return true;
        }
    } else {
        // trata vértice inexistente
    }

    // Registra o acesso à memória antes do último if
    LEMEMLOG(sizeof(Grafo) + verticeOrigem->TotalConexao() * sizeof(int), sizeof(int), 0);

    if (verticeOrigem->GetCor() - 1 == conta_cor) {
        delete[] cores_verificadas;  // Libera a memória antes de retornar
        return true;
    }

    delete[] cores_verificadas;  // Libera a memória antes de retornar
    return false;
}

int verificaGrafo(Grafo& meuGrafo) {
    // Registra o acesso à memória no início da função
    LEMEMLOG(0, sizeof(Grafo), 0);

    for (TipoNo* atual = meuGrafo.GetVertices().GetPrimeiro(); atual != nullptr; atual = atual->GetProximo()) {
        // Registra o acesso à memória dentro do loop
        LEMEMLOG(sizeof(Grafo), sizeof(TipoNo), 0);

        if (!verificaVertice(meuGrafo, atual->GetItem())) {
            return 0;
        }
    }

    return 1;
}
