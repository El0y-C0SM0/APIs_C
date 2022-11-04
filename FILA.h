//Autor: Eloy Ribeiro
//Github: El0y-C0SM0

#ifndef FILA
#define FILA

#define FALSE 0
#define TRUE 1
#define ERR_INDICE_INVALIDO 2
#define ERR_LISTA_VAZIA 3

#include <stdio.h>
#include <stdlib.h>

typedef void* Item;

typedef struct Tno {
    Item item;
    struct Tno* proximo;
} No;

typedef struct {
    No *primeiro;
    int quant;
} Fila;

No *cria_no(Item valor, No *prox) {
    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL) 
        return NULL;

    novo->item = valor;
    novo->proximo = prox;

    return novo;
}

Fila *criar_fila() {
    Fila *novo = (Fila*) malloc(sizeof(Fila));

    if(novo == NULL) return NULL;

    novo->quant = 0;
    novo->primeiro = NULL;

    return novo;
}

int enfileirar();

int desenfileirar();

int esvaziar();

Item proximo_item();

#endif