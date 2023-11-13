#include "../include/MetodosOrdenacao.hpp"
#include "../include/memlog.hpp"
#include <iostream>
#include <cmath>


void BubbleSort(vertices MeusVertices[], int total_vertices){
  int n = total_vertices;
 
  for(int i = 0; i < n; i++){
    for(int j = 1; j < n-i; j++){
        if(MeusVertices[j].getCor() < MeusVertices[j-1].getCor()){
            int aux_cor = MeusVertices[j].getCor();
            int aux_grau = MeusVertices[j].getGrau();
            MeusVertices[j].setGrau(MeusVertices[j-1].getGrau());
            MeusVertices[j].setCor(MeusVertices[j-1].getCor());
            MeusVertices[j-1].setGrau(aux_grau);
            MeusVertices[j-1].setCor(aux_cor);
        }
    }
  }
}

void SelectionSort(vertices MeusVertices[], int total_vertices) {
    int n = total_vertices;

    for (int i = 0; i < n; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (MeusVertices[j].getCor() < MeusVertices[min].getCor() || 
               (MeusVertices[j].getCor() == MeusVertices[min].getCor() && MeusVertices[j].getGrau() < MeusVertices[min].getGrau())) {
                min = j;
            }
        }

        if (i != min) {
         std::swap(MeusVertices[i],MeusVertices[min]);
        }
    }
}




void InsertionSort(vertices MeusVertices[], int total_vertices) {
    vertices aux;
    int n = total_vertices;
    int j;
    for(int i = 1; i < n; i++) {
        aux = MeusVertices[i];
        j = i - 1;
        while((j >= 0) && (aux.getCor() < MeusVertices[j].getCor())) {
            MeusVertices[j + 1] = MeusVertices[j];
            j--;
        }
        MeusVertices[j + 1] = aux;
    }
}


void Particao(int esq, int dir, int *i, int *j, vertices MeusVertices[]) {
    vertices x, w;
    *i = esq;
    *j = dir;
    int meio = (*i + *j) / 2;
    x = MeusVertices[meio];

    do {
        while (MeusVertices[*i].getCor() < x.getCor() || (MeusVertices[*i].getCor() == x.getCor() && MeusVertices[*i].getGrau() < x.getGrau())) (*i)++;
        while (MeusVertices[*j].getCor() > x.getCor() || (MeusVertices[*j].getCor() == x.getCor() && MeusVertices[*j].getGrau() > x.getGrau())) (*j)--;
        if (*i <= *j) {
            w = MeusVertices[*i];
            MeusVertices[*i] = MeusVertices[*j];
            MeusVertices[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int esq, int dir, vertices MeusVertices[]) {
    while (esq < dir) {
        int i, j;
        Particao(esq, dir, &i, &j, MeusVertices);

        // Aplica a recursão no menor intervalo
        if (j - esq < dir - i) {
            Ordena(esq, j, MeusVertices);
            esq = i;
        } else {
            Ordena(i, dir, MeusVertices);
            dir = j;
        }
    }
}

void QuickSort(vertices MeusVertices[], int total_vertices) {
    Ordena(0, total_vertices - 1, MeusVertices);
}

vertices* merge(vertices valuesL[], vertices valuesR[], int nl, int nr) {
    vertices* result = new vertices[nl + nr];
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nl && j < nr) {
        if (valuesL[i].getCor() < valuesR[j].getCor() || (valuesL[i].getCor() == valuesR[j].getCor() && valuesL[i].getGrau() < valuesR[j].getGrau())) {
            result[k] = valuesL[i];
            i++;
        } else {
            result[k] = valuesR[j];
            j++;
        }
        k++;
    }

    // Se houver elementos restantes em valuesL ou valuesR, copie-os para result
    while (i < nl) {
        result[k] = valuesL[i];
        i++;
        k++;
    }

    while (j < nr) {
        result[k] = valuesR[j];
        j++;
        k++;
    }

    return result;
}

void mergeSort(vertices MeusVertices[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        // Divide a array em duas metades e chama o mergeSort recursivamente
        mergeSort(MeusVertices, inicio, meio);
        mergeSort(MeusVertices, meio + 1, fim);

        // Chama a função merge para mesclar as duas metades ordenadas
        vertices* resultado = merge(MeusVertices + inicio, MeusVertices + meio + 1, meio - inicio + 1, fim - meio);

        // Copia os resultados mesclados de volta para a array original
        for (int i = 0; i < fim - inicio + 1; i++) {
            MeusVertices[inicio + i] = resultado[i];
        }

        // Libera a memória alocada para o array temporário
        delete[] resultado;
    }
}

void HeapSort(vertices MeusVertices[], int total_vertices) {
    int n = total_vertices - 1;
    // Constrói o heap a partir do meio para o início
    for (int i = n / 2; i >= 0; --i) {
        Refaz(i, n, MeusVertices);
    }
    // Extrai elementos do heap um por um
    for (int i = n; i > 0; --i) {
        // Move a raiz atual para o final
        vertices aux = MeusVertices[0];
        MeusVertices[0] = MeusVertices[i];
        MeusVertices[i] = aux;
        // Chama Refaz no heap reduzido
        Refaz(0, i - 1, MeusVertices);
    }
}

void Refaz(int Esq, int Dir, vertices MeusVertices[]) {
    int i = Esq;
    int j = 2 * i + 1; // Filho à esquerda

    vertices aux = MeusVertices[i];

    while (j <= Dir) {
        // Se houver um filho à direita e ele for maior ou (igual e o grau for maior)
        if (j < Dir && (MeusVertices[j].getCor() < MeusVertices[j + 1].getCor() ||
                        (MeusVertices[j].getCor() == MeusVertices[j + 1].getCor() && MeusVertices[j].getGrau() < MeusVertices[j + 1].getGrau()))) {
            ++j;
        }
        // Se o elemento pai for maior ou igual ao maior filho, interrompe
        if (aux.getCor() > MeusVertices[j].getCor() ||
            (aux.getCor() == MeusVertices[j].getCor() && aux.getGrau() >= MeusVertices[j].getGrau())) {
            break;
        }
        // Move o filho para o pai
        MeusVertices[i] = MeusVertices[j];

        // Atualiza índices
        i = j;
        j = 2 * i + 1;
    }
    // Coloca o pai na posição correta
    MeusVertices[i] = aux;
}


extern memlog_tipo ml;

void OrganizaMaior(vertices MeusVertices[], int& n) {
    vertices maior = MeusVertices[0];
    int marca_pos = 0;

    for (int i = 0; i < n; i++) {
        if (MeusVertices[i].getCor() > maior.getCor()) {
            maior = MeusVertices[i];
            marca_pos = i;
        }
    }

    if (MeusVertices[n - 1].getCor() < maior.getCor()) {
        MeusVertices[marca_pos] = MeusVertices[n - 1];
        MeusVertices[n - 1] = maior;
    }

    // Registra o acesso à memória após a troca
    LEMEMLOG(marca_pos, sizeof(vertices), 0);
    LEMEMLOG(n - 1, sizeof(vertices), 0);
    ESCREVEMEMLOG(marca_pos, sizeof(vertices), 0);
    ESCREVEMEMLOG(n - 1, sizeof(vertices), 0);
}

void MeuSort(vertices MeusVertices[], int total_vertices) {
    int n = total_vertices;

    // Registra o acesso à memória antes de iniciar o loop
    LEMEMLOG(0, n * sizeof(vertices), 0);

    while (n > 0) {
        OrganizaMaior(MeusVertices, n);
        n--;
    }

    // Registra o acesso à memória após o loop
    ESCREVEMEMLOG(0, n * sizeof(vertices), 0);
}
