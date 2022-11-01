//Autor: Eloy Ribeiro
//Github: El0y-C0SM0

#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include <stdio.h>
#include <stdlib.h>

typedef void* Item;

typedef struct Tno {
    Item item;
    struct Tno* anterior;
    struct Tno* proximo;
} No;


typedef struct {
    No *primeiro;
    No *ultimo;
    int quant;
} Lista;

No *cria_no(Item valor, No *ant, No *prox) {
    No *novo = malloc(sizeof(No));

    if(novo == NULL) {
        return NULL;
    }

    novo->item = &valor;
    novo->anterior = ant;
    novo->proximo = prox;

    return novo;
}





#endif 
