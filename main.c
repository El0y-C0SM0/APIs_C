#include <stdio.h>
#include "VETORES_E_MATRIZES.h"
#include "ARRAY_LIST.h"

#define TAM 3

int main() {
    int **matriz = malloc_matriz(TAM, TAM);

    inicia_matriz(matriz, TAM, TAM);

    printa_matriz(matriz, TAM, TAM);

    return 0;
}