#include "../include/Grafo.hpp"


bool busca(const int array[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == valor) {
            return true; // Valor encontrado no array
        }
    }
    return false; // Valor não encontrado no array
}


//verifica se grafo é guloso
int verificaGrafo(Grafo& meuGrafo){
    for(TipoNo* atual = meuGrafo.GetVertices().GetPrimeiro(); atual != nullptr; atual->GetProximo()){
            int cont = 0;
            while(cont < atual->TotalConexao()){
            if(!meuGrafo.verificaVertice(atual->GetItem())){
                return 0;
            }
            }
    }
    return 1;
}