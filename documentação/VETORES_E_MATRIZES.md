# VETORES_E_MATRIZES.h

---

## Propósito

É uma biblioteca com funções para agilizar o trabalho com matrizes e vetores. <br>
Obs: Só trabalha com matrizes criadas dinamicamente (inclusive cria elas). <br>

## Funções para vetores:

### void inicia_vetor(int *vetor, int tam)
Recebe como parametro: o vetor, o tamanho e um valor.<br>
Inicializa o vetor de tamanho tam com o valor passado.<br>

### void printa_vetor(int *vetor, int tam)
Recebe como parametro: um vetor e o tamanho.<br>
Imprime um vetor, ideal para testes.<br>

### int compara_vetores(int *vetor1, int *vetor2, int tam)
Recebe como parametro: dois vetores e o tamanho.<br>
Compara os dois vetores.<br>
Retorna:<br>
Se forem diferentes retorna FALSE.<br>
se forem iguais retorna TRUE.<br>

## Funções para matrizes:

### int **malloc_matriz(int linhas, int colunas)
Recebe como parametro: o numero de linhas e de colunas.<br>
Cria uma matriz dinamicamente alocada.<br>
Retorna:<br>
um ponteiro de ponteiro se foi possivel alocar.<br>
NULL se não foi possivel.<br>

### void libera_matriz(int **matriz, int linhas)
Recebe como parametro: a matriz e o numero de linhas.<br>
libera o espaço de uma matriz alocada dinamicamente.<br>

### void inicia_matriz(int **matriz, int linhas, int colunas)
Recebe como parametro: a matriz, a quantidade de linhas e a quantidade de colunas.<br>
inicializa o matriz, dinamicamente criada, com variáveis inteiras escolhidas pelo usuario.<br>

### void preenche_matriz(int **matriz, int linhas, int colunas, int valor)
Recebe como parametro: a matriz, a quantidade de linhas, a quantidade de colunas e um valor.<br>
preenche a matriz, dinamicamente criada, com o valor.<br>

### int compara_matriz(int **matriz1, int **matriz2, int linhas, int colunas)
Recebe como parametro: duas matrizes, a quantidade de linhas e a quantidade de colunas.<br>
Compara as duas matrizes.<br>
Retorna:<br>
Se forem diferentes retorna FALSE.<br>
se forem iguais retorna TRUE.<br>

### void printa_matriz(int **matriz, int linhas, int colunas)
Recebe como parametro: a matriz, a quantidade de linhas, a quantidade de colunas.<br>
printa a matriz, ideal para testes.<br>