# VETORES_E_MATRIZES.h

---

## Propósito

É uma biblioteca com funções para agilizar o trabalho com matrizes e vetores. 
Obs: Só trabalha com matrizes criadas dinamicamente (inclusive cria elas).

## Funções para vetores:

#### void inicia_vetor(int *vetor, int tam)
Recebe como parametro: o vetor, o tamanho e um valor.
Inicializa o vetor de tamanho tam com o valor passado.

#### void printa_vetor(int *vetor, int tam)
Recebe como parametro: um vetor e o tamanho.
Imprime um vetor, ideal para testes.

#### int compara_vetores(int *vetor1, int *vetor2, int tam)
Recebe como parametro: dois vetores e o tamanho.
Compara os dois vetores.
Retorna:
Se forem diferentes retorna FALSE.
se forem iguais retorna TRUE.

## Funções para matrizes:

#### int **malloc_matriz(int linhas, int colunas)
Recebe como parametro: o numero de linhas e de colunas.
Cria uma matriz dinamicamente alocada. 
Retorna:
um ponteiro de ponteiro se foi possivel alocar.
NULL se não foi possivel

#### void libera_matriz(int **matriz, int linhas)
Recebe como parametro: a matriz e o numero de linhas.
libera o espaço de uma matriz alocada dinamicamente.

#### void inicia_matriz(int **matriz, int linhas, int colunas)
Recebe como parametro: a matriz, a quantidade de linhas e a quantidade de colunas.
inicializa o matriz, dinamicamente criada, com variáveis inteiras escolhidas pelo usuario.

#### void preenche_matriz(int **matriz, int linhas, int colunas, int valor)
Recebe como parametro: a matriz, a quantidade de linhas, a quantidade de colunas e um valor.
preenche a matriz, dinamicamente criada, com o valor.

#### int compara_matriz(int **matriz1, int **matriz2, int linhas, int colunas)
Recebe como parametro: duas matrizes, a quantidade de linhas e a quantidade de colunas.
Compara as duas matrizes.
Retorna:
Se forem diferentes retorna FALSE.
se forem iguais retorna TRUE.

#### void printa_matriz(int **matriz, int linhas, int colunas)
Recebe como parametro: a matriz, a quantidade de linhas, a quantidade de colunas.
printa a matriz, ideal para testes.