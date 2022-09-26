#ifndef ORDENACAO
#define ORDENACAO

void troca_posicoes(int *a, int *b) {
    if(*a != *b){
        int aux = *a;
        *a = *b;
        *b = aux;
    }
}

void bubble_sort(int *vetor, int tam) {
    int aux;
    for(int i = 1; i < tam; i++) {
        for(int j = tam - 1; j >= i; j--) {
            if(vetor[j] < vetor[j - 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = aux;
            }
        }
    }
}

#endif