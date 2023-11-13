#ifndef METODOSORDENACAO_HPP
#define METODOSORDENACAO_HPP
#include "TipoVertice.hpp"



void BubbleSort(vertices MeusVertices[], int total_vertices);
void SelectionSort(vertices MeusVertices[], int total_vertices);
void InsertionSort(vertices MeusVertices[],int total_vertices);
void Particao(int esq, int dir, int *i, int *j, vertices MeusVertices[]);
void Ordena(int esq, int dir, vertices MeusVertices[]);
void QuickSort(vertices MeusVertices[],int total_vertices);
vertices* merge(vertices valuesL[], vertices valuesR[], int nl, int nr);
void mergeSort(vertices MeusVertices[], int inicio, int fim);
void HeapSort(vertices MeusVertices[],int total_vertices);
void Refaz(int Esq, int Dir, vertices MeusVertices[]);
void OrganizaMaior(vertices MeusVertices[],int& n);
void MeuSort(vertices MeusVertices[], int total_vertices);





#endif