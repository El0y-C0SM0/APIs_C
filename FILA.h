//Autor: Eloy Ribeiro
//Github: El0y-C0SM0

#ifndef FILA
#define FILA

#define FALSE 0
#define TRUE 1
#define ERR_FILA_VAZIA 2

#include <stdio.h>
#include <stdlib.h>

typedef void* Item;

typedef struct Tno {
    Item item;
    struct Tno* proximo;
} No;

typedef struct {
    No *primeiro;
    No *ultimo;
    int quant;
} Fila;

No *cria_no(Item valor) {
    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL) 
        return NULL;

    novo->item = valor;
    novo->proximo = NULL;

    return novo;
}

Fila *criar_fila() {
    Fila *novo = (Fila*) malloc(sizeof(Fila));

    if(novo == NULL) return NULL;

    novo->quant = 0;
    novo->primeiro = NULL;

    return novo;
}

int esta_vazia(Fila *fila) {
    return fila->quant == 0;
}

int tamanho(Fila *fila) {
    return fila->quant;
}

int enfileirar(Fila *fila, Item item) {
    No *novo = cria_no(item);

    if(novo == NULL)
        return FALSE;

    if(esta_vazia(fila)) 
        fila->primeiro = novo;
    else 
        fila->ultimo->proximo = novo;
    fila->ultimo = novo;

    fila->quant++;

    return TRUE;
}

int desenfileirar(Fila *fila, Item item_removido) {
    if(esta_vazia(fila))
        return ERR_FILA_VAZIA;

    No *removido = fila->primeiro;
    item_removido = removido->item;

    fila->quant--;

    free(removido);

    return FALSE;
}

int esvaziar(Fila *fila) {
    if(esta_vazia(fila))
        return TRUE;

    No *removido = fila->primeiro;
    fila->primeiro = removido->proximo;
    fila->quant--;

    free(removido);

    int aux = esvaziar(fila);

    if(aux) 
        return TRUE;

    return FALSE;
}

Item primeiro_item(Fila *fila) {
    return fila->primeiro->item;
}

Item ultimo_item(Fila *fila) {
    return fila->ultimo->item;
}

#endif