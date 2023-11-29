# Projeto de Verificação da Gulosidade de um Grafo

## Introdução

Neste projeto, enfrentamos o desafio de verificar a gulosidade de um grafo. Recebemos como entrada um grafo junto com a coloração atribuída aos seus vértices. O objetivo principal era determinar se essa coloração era gulosa, onde um vértice de cor c deveria ter vizinhos de todas as cores menores que c. Se a coloração fosse gulosa, nosso segundo objetivo era ordenar os vértices com base em suas cores.

O projeto não apenas abordou a verificação da gulosidade do grafo, mas também proporcionou uma abordagem prática à aplicação de métodos de ordenação em um contexto específico, contribuindo para uma compreensão mais aprofundada dos conceitos estudados em sala de aula.

## Método

No desenvolvimento do projeto, foram utilizadas duas estruturas de dados principais: Grafos e Listas de Adjacência, além de dois Tipos Abstratos de Dados (TADs): TipoNo e TipoVertice.

- **TipoNo:** Armazena as variáveis da lista, representando os vértices e interligando-os dinamicamente.

- **TipoVertice:** Utilizado para facilitar a ordenação, fornecendo uma abordagem mais simples sem a necessidade de acessar o grafo em cada operação de ordenação.

- **Lista de Adjacência:** Armazena os vértices do grafo de maneira dinâmica e encadeada.

- **TAD Grafo:** Utilizado para representar o grafo, contendo métodos como inserir vértices e arestas.

## Funções

Foram implementadas funções para verificar a gulosidade do grafo e ordenar seus vértices. Algumas delas incluem:

- `VerificaVertice`: Verifica se um vértice específico é guloso.
- `VerificaGrafo`: Verifica se o grafo como um todo atende aos critérios de gulosidade.
- Métodos de ordenação, como Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, Merge Sort, Heap Sort e um método próprio chamado `MeuSort`.

## Análise de Complexidade

- **VerificaVertice e VerificaGrafo:** Complexidade de tempo total de O(n) e O(V⋅n), respectivamente.
- **MeuSort (Método Próprio de Ordenação):** Complexidade de tempo total de O(n^2) no pior caso e O(n) no melhor caso.

## Análise de Robustez

O código foi implementado seguindo práticas de programação defensiva, com comentários e indentação para facilitar a leitura e manutenção. Modularização foi utilizada para tornar o código mais compreensível.

## Análise Experimental

Utilizou-se o memlog e o analisamem para analisar o comportamento de memória. Além disso, o valgrind foi empregado para avaliar o desempenho do cache durante a execução.

## Conclusão

O projeto proporcionou uma compreensão teórica e prática sobre a gulosidade de grafos, bem como a aplicação de métodos de ordenação. A escolha adequada de algoritmos de ordenação em situações específicas foi enfatizada, enriquecendo significativamente o conhecimento.

## Bibliografia

PAPPA, Gisele L. JR. MEIRA, Wagner. Slides virtuais da disciplina de estruturas de dados. Departamento de Ciência da Computação. Universidade Federal de Minas Gerais. Belo Horizonte, 2023.
