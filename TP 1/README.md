# TP-1---ESTRUTURA-DE-DADOS

# Projeto de Lógica Booleana

## Introdução

Neste projeto, enfrentamos dois desafios de lógica booleana e desenvolvemos soluções para resolvê-los de maneira eficaz. O primeiro desafio tinha como objetivo resolver expressões booleanas com valores de bits específicos. Para resolver, foi adotada uma abordagem onde foi feito o armazenamento dos operadores e valores em duas pilhas separadas, calculando a expressão de forma pós-fixa. O segundo desafio envolveu a determinação da satisfatibilidade de uma expressão booleana, ou seja, determinar se existe uma valoração das variáveis que a torna verdadeira. Além disso, era necessário retornar um valor possível de valoração, caso a expressão fosse satisfazível. Para resolver esse problema, foi adotada uma abordagem baseada em árvores, onde foi armazenado todas as valorações possíveis em uma árvore. Em seguida, foi calculada a expressão com base nessas valorações, tratando os quantificadores "para todo" e "existe" de forma adequada. Essa abordagem nos permitiu determinar a satisfatibilidade da expressão e, se satisfazível, encontrar uma valoração que a tornasse verdadeira.

## Métodos

### Estruturas de Dados

Para a implementação deste projeto, foram usados 2 Tipos de Estrutura, foram elas: Árvore e Pilha, e 3 tipos abstratos de dados, foram eles: TipoNo, Tipoitem, TipoCelula. 
- O TipoNo foi responsável por armazenar as variáveis da árvore e interligá-las dinamicamente, cada nó recebeu um item do tipo string, um array de strings e dois ponteiro para um Nó da esquerda e outro para o nó da direita.  
- A árvore, foi muito útil para armazenar as ramificações das possíveis valorações na ordem correta, na árvore armazenamos as variáveis em nós (TAD citado anteriormente) de maneira dinâmica, onde cada nó é ligado a um pai, que tem os filhos da esquerda e da direita. 
- A pilha foi fundamental para calcular o resultado das expressões de maneira pós-fixa, já que o último que sai é sempre o primeiro a sair. Uma pilha recebe um ponteiro do tipo célula que corresponde ao topo. 
- O TipoItem é bem simples e foi usado para especificar o tipo de variável da pilha, ele recebe uma chave do tipo char e manipula de maneira necessária na pilha. 
- Por fim, TipoCelula é bem parecida com TipoNo, mas é específica para a pilha. Ela recebe um item do TipoItem e um ponteiro do tipo Célula que aponta para o próximo valor da pilha.

### Funções

No primeiro problema foi implementada uma função principal e algumas outras complementares a esta, a função principal (`posfixa`) recebe a expressão e os valores, e retorna uma pilha com o resultado da expressão.

No segundo problema, tem-se algumas funções fundamentais, a primeira (`setCombinações`) monta a árvore de possibilidades de maneira recursiva e in ordem. A segunda (`CalculaResultadosFolhas`) calcula o resultado das folhas da árvore com base nos valores armazenados nos nós e a expressão passada pelo usuário e armazena as expressões com valores que satisfazem a expressão. 
A terceira (`calculaResultadoExpressoes`) calcula o resultado do resto dos nós das árvores percorrendo a árvore em pós ordem calculando recursivamente primeiro o resultado dos filhos e também armazena as expressões com valores que satisfazem a expressão, mas agora se baseando também nas expressões que foram armazenadas nos filhos.
A quarta e última função principal (`verificaPossivel`) calcula e retorna um valor possível para satisfazer a expressão.

## Análise de Complexidade

- `posfixa`: A complexidade assintótica da função `posfixa` é linear, O(n), onde 'n' é o tamanho da string `p` de entrada. Isso ocorre porque a função passa por cada caractere na string uma única vez, realizando operações de empilhamento e desempilhamento com complexidade constante para cada caractere. A função não envolve loops aninhados ou iterações adicionais que dependam do tamanho da entrada, e a complexidade é diretamente proporcional ao tamanho da string de entrada.

- `setCombinações`: A complexidade assintótica dessa função é exponencial, pois a árvore construída crescerá exponencialmente com base no número de variáveis "a" e "e" na expressão original. A complexidade é O(2^n), onde 'n' é o número de variáveis "a" e "e" na expressão original.

- `calculaResultadosFolhas`: A complexidade depende da profundidade da árvore e do número de folhas, mas no pior caso, é linear em relação ao número total de folhas.

- `calculaResultadoExpressoes`: A complexidade da função é linear em relação ao número total de nós na árvore. No entanto, se a árvore for desequilibrada, a complexidade pode ser maior.

- `verificaPossivel`: A complexidade da função é linear em relação ao tamanho da expressão original no primeiro nó da árvore.

## Análise de Robustez

No projeto foram implementadas várias práticas de programação defensiva, como verificação de nulos, tratamento de casos especiais e verificação de limites, para evitar falhas e criação de avisos de exceção em funções específicas. Além disso, lidei com os resultados inesperados para garantir uma certa tolerância a falhas, permitindo que o programa continue funcionando em situações não ideais.

## Conclusão

Neste projeto desafiador, enfrentamos dois problemas relacionados à lógica booleana e desenvolvemos soluções eficazes para resolvê-los. No primeiro desafio, tivemos que lidar com expressões booleanas que envolviam valores de bits específicos. Para superar esse desafio, optamos por uma abordagem que incluía o armazenamento de operadores e valores em duas pilhas separadas e o cálculo da expressão de forma pós-fixa.

O segundo desafio foi ainda mais complexo, envolvendo a determinação da satisfatibilidade de expressões booleanas e a busca por uma valoração das variáveis que tornasse a expressão verdadeira. Além disso, era necessário retornar um valor possível de valoração, caso a expressão fosse satisfazível.

Nossa solução para esse segundo desafio se baseou na utilização de árvores. Criamos uma estrutura de árvore na qual armazenamos todas as valorações possíveis. Em seguida, efetuamos o cálculo da expressão com base nessas valorações, tratando os quantificadores "para todo" e "existe" de maneira apropriada. Essa abordagem nos permitiu não apenas determinar se a expressão era satisfatível, mas também encontrar uma valoração que a tornasse verdadeira, caso fosse possível.

## Bibliografia

- Expression Evaluation. GeeksForGeeks - 21 jun. 2022. Disponível em: [https://www.geeksforgeeks.org/expression-evaluation/](https://www.geeksforgeeks.org/expression-evaluation/).
- PAPPA, Gisele L. JR. MEIRA, Wagner. Slides virtuais da disciplina de estruturas de dados. Departamento de Ciência da Computação. Universidade Federal de Minas Gerais. Belo Horizonte, 2023.
