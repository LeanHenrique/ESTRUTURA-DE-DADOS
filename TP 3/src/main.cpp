#include "../include/arvore.h"
using namespace std;

int main() {
    int instancia, qtd_op;
    cin >> instancia >> qtd_op;

    const int MAX_CONSULTAS = 100000;
    int conta_r = 0;
    matriz resultados[MAX_CONSULTAS];

    ArvoreSegmentacao MinhaArvore;
    TipoNo* Raiz = MinhaArvore.Getraiz();
    MinhaArvore.ConstroiArvore(Raiz, 0, instancia);

    char opcao;
    int conta_op = 0;

    while (conta_op < qtd_op) {
        cin >> opcao;
        conta_op++;

        switch (opcao) {
            case 'u': {
                int t;
                cin >> t;
                matriz A;
                // Ler os elementos da matriz A
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        int elemento;
                        cin >> elemento;
                        A.setElemento(i, j, elemento, false);
                    }
                }

                // Atualizar a árvore com a matriz A no nó t
                MinhaArvore.atualizar(Raiz, t, 0, instancia, A);
                break;
            }

            case 'q': {
                int inicio, fim;
                cin >> inicio >> fim;

                matriz A, result;
                // Ler os elementos da primeira coluna da matriz A
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        if (j == 0) {
                            int elemento;
                            cin >> elemento;
                            A.setElemento(i, j, elemento, false);
                        } else {
                            A.setElemento(i, j, 0, false);
                        }
                    }
                }

                // Consultar a árvore e armazenar o resultado no array
                result = MinhaArvore.consulta(Raiz, inicio, fim);
                resultados[conta_r] = multiplicaMatrizes(result, A);
                conta_r++;

                break;
            }

            default:
                break;
        }
    }

    // Imprimir os resultados ao final
    for (int i = 0; i < conta_r; i++) {
        for (int j = 0; j < 2; j++) {
            cout << resultados[i].getElemento(j, 0) << " ";
        }
        cout << endl;
    }

    return 0;
}
