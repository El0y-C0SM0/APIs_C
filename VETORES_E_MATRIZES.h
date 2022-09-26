//Autor: Eloy Ribeiro
//Github: El0y-C0SM0

#ifndef VETORES_E_MATRIZES
#define VETORES_E_MATRIZES

#include <stdio.h>
#include <stdlib.h>

#define ERR_N_ALOCADO NULL
#define TRUE 1
#define FALSE 0

/*
	Recebe como parametros o numero de linhas e de colunas.
	Cria uma matriz dinamicamente alocada. 
	Retorna um ponteiro de ponteiro se foi possivel alocar.
	Retorna NULL se não foi possivel
*/
int **malloc_matriz(int linhas, int colunas) {
    int **matriz;

    matriz = (int**) malloc(linhas * sizeof(int*));

	if(matriz == NULL) return ERR_N_ALOCADO;

    for(int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
		if(matriz[i] == NULL) return ERR_N_ALOCADO;
	}

    return matriz;
}

/*
	libera o espaço de uma matriz alocada
	dinamicamente
*/
void libera_matriz(int **matriz, int linhas) {
	for(int i = 0; i < linhas; i++)
		free(matriz[i]);
	free(matriz);
}

/*
	Recebe como parametro o vetor e o tamanho
    inicializa o vetor de tamanho tam com variáveis
    inteiras escolhidas pelo usuario.
*/
void inicia_vetor(int *vetor, int tam) {
    for(int i = 0; i < tam; i++)
        scanf("%d", &vetor[i]);
}

/*
	Recebe como parametro o vetor, o tamanho e um valor.
    inicializa o vetor de tamanho tam com o valor passado.
*/
void preenche_vetor(int *vetor, int tam, int valor) {
    for(int i = 0; i < tam; i++)
        vetor[i] = valor;
}

/*
	Recebe como um vetor e o tamanho.
    imprime um vetor, ideal para testes
*/
void printa_vetor(int *vetor, int tam) {
	for(int i = 0; i < tam; i++)
		printf("%2d", vetor[i]);
	printf("\n");
}

/*
	Recebe como parametro dois vetores e o tamanho.
    Compara dois vetores.
	Se forem diferentes retorna FALSE.
	se forem iguais retorna TRUE.
*/
int compara_vetores(int *vetor1, int *vetor2, int tam) {
	for(int i = 0; i < tam; i++) {
		if(vetor1[i] != vetor2[i])
			return FALSE;
	}
	return TRUE;
}

/*
	Recebe como parametros a matriz, a quantidade de linhas 
	e a quantidade de colunas.
    inicializa o matriz, dinamicamente criada, com variáveis
    inteiras escolhidas pelo usuario.
*/
void inicia_matriz(int **matriz, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++)
            scanf("%d", &matriz[i][j]);
    }
}

/*
	Recebe como parametros a matriz, a quantidade de linhas,
	a quantidade de colunas e um valor.
    preenche a matriz, dinamicamente criada, com o valor.
*/
void preenche_matriz(int **matriz, int linhas, int colunas, int valor) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++)
            matriz[i][j] = valor;
    }
}

/*
	Recebe como parametro duas matrizes, a quantidade
	de linhas e a quantidade de colunas.
    Compara as duas matrizes.
	Se forem diferentes retorna FALSE.
	se forem iguais retorna TRUE.
*/
int compara_matriz(int **matriz1, int **matriz2, int linhas, int colunas) {
	for(int i = 0; i < linhas; i++) {
		for(int j = 0; j < colunas; j++) {
			if(matriz1[i][j] != matriz2[i][j])
				return FALSE;
		}
	}
	return TRUE;
}

/*
	Recebe como parametros a matriz, a quantidade de linhas,
	a quantidade de colunas.
	printa a matriz, ideal para testes.
*/
void printa_matriz(int **matriz, int linhas, int colunas) {
	for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++)
            printf("%2d", matriz[i][j]);
		printf("\n");
    }
}

#endif