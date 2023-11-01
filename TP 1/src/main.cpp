
#include "../include/Calculadora.h"
#include "../include/satisfabilidade.h"


int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " [-a | -s] <expressao> <valoração>" << std::endl;
        return 1;
    }

    std::string opcao = argv[1];
    std::string expressao = argv[2];
    std::string valores = argv[3];

    if (opcao == "-a") {
  
    string expressaotratada = trataexpressao(expressao,valores);
    PilhaEncadeada resultado = posfixa(expressaotratada);
    TipoItem x;

    while (!resultado.Vazia()) {
        x = resultado.Desempilha();
        int a = ConverteInteiro(x.GetChave());
        cout << a << " ";
    }
    cout << endl; 
    } else if (opcao == "-s") {
    ArvoreBinaria arvore;
    TipoNo *p = new TipoNo();
    string quant = guardaQuant(valores);
    setCombinacoes(arvore,p, valores);
    calcularResultadosFolhas(arvore,arvore.Getraiz(),expressao);
    calcularResultadosExpressoes(arvore,arvore.Getraiz(),quant);
    string valorPossivel = verificaPossivel(arvore,arvore.Getraiz(),quant, valores);



    // Agora, a árvore contém todas as combinações da expressão "00XX1".

    // Você pode usar a função InOrdem da sua classe para imprimir as combinações.
    std::cout << arvore.Getraiz()->GetItem() << " " << valorPossivel <<std::endl;
    } else {
        std::cerr << "Opção inválida: " << opcao << std::endl;
        return 1;
    }

    return 0;
}