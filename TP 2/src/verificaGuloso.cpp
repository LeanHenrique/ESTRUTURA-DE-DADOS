#include "../include/Grafo.hpp"
#include "../include/verificaGuloso.hpp"

bool busca(const int array[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == valor) {
            return true; // Valor encontrado no array
        }
    }
    return false; // Valor não encontrado no array
}

//verifica se vertice é guloso
bool verificaVertice(Grafo& meuGrafo, int v){
   TipoNo* verticeOrigem = meuGrafo.GetVertices().EncontraVertice(v);
   TipoNo* aux = new TipoNo();
   if (verticeOrigem) {
    int conta_cor = 0;
    for(int i = 0; i < verticeOrigem->TotalConexao(); i++){ //anda pelas conexões do vertice
    int j = verticeOrigem->GetConexao(i); //recebe o vertice conectado
    aux = meuGrafo.GetVertices().EncontraVertice(j);//recebe o nó correspondente ao vertice conectado
    int cores_verificadas[conta_cor]; //guarda as cores ja verificadas
    if(verticeOrigem->GetCor() == conta_cor-1){ //verifica se o vertice está ligado a todas as cores menores que ele
        return true;
    }else if(aux->GetCor() < verticeOrigem->GetCor()){
        if(!busca(cores_verificadas, conta_cor, aux->GetCor())){ //verifica se a cor foi verificada
        cores_verificadas[conta_cor] = aux->GetCor();//adiciona cor verificada no array
        conta_cor++;
        }
    }
    }
   }else{
    //trata vertice inexistente
   }
   return false;
   
}


//verifica se grafo é guloso
int verificaGrafo(Grafo& meuGrafo){
    for(TipoNo* atual = meuGrafo.GetVertices().GetPrimeiro(); atual != nullptr; atual->GetProximo()){
            int cont = 0;
            while(cont < atual->TotalConexao()){
            if(!verificaVertice(meuGrafo, atual->GetItem())){
                return 0;
            }
            }
    }
    return 1;
}