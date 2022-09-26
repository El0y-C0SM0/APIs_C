#include <stdio.h>

#include "VETORES_E_MATRIZES.h"
#include "ARRAY_LIST.h"
#include "ORDENACAO.h"

#define TAM 3

int main() {
    int vetor[5];
    int tam = 5;

    inicia_vetor(vetor, tam);
    printa_vetor(vetor, tam);
    bubble_sort(vetor, tam);
    printa_vetor(vetor, tam);

    return 0;
}