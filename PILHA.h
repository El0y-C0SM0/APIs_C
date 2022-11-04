//Autor: Eloy Ribeiro
//Github: El0y-C0SM0

#ifndef PILHA
#define PILHA

#define FALSE 0
#define TRUE 1
#define ERR_PILHA_VAZIA 2

#include <stdio.h>
#include <stdlib.h>

typedef void* Item;

typedef struct Tno {
    Item item;
    struct Tno* proximo;
} No;

typedef struct {
    No *topo;
    int quant;
} Pilha;

No *cria_no(Item valor, No *prox) {
    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL) 
        return NULL;

    novo->item = valor;
    novo->proximo = prox;

    return novo;
}

Pilha *criar_pilha() {
    Pilha *novo = (Pilha*) malloc(sizeof(Pilha));

    if (novo == NULL)
        return NULL;

    novo->quant = 0;
    novo->topo = NULL;

    return novo;
}

int pilha_vazia(Pilha *pilha) {
    return pilha->quant == 0;
}

int pilha_tamanho(Pilha *pilha) {
    return pilha->quant;
}

int empilhar(Pilha *pilha, Item item) {
    No *novo = cria_no(item, pilha->topo); 

    if (novo == NULL)
        return FALSE;

    pilha->topo = novo;
    pilha->quant++;

    return TRUE;
}

int desenpilhar(Pilha *pilha, Item item_removido) {
    if (pilha_vazia(pilha))
        return ERR_PILHA_VAZIA;

    No *removido = pilha->topo;
    item_removido = removido->item;

    pilha->topo = removido->proximo;
    pilha->quant--;

    free(removido);

    return TRUE;
}

int esvaziar(Pilha *pilha) {
    if (pilha_vazia(pilha)) 
        return TRUE;

    No *removido = pilha->topo;

    pilha->topo = removido->proximo;
    pilha->quant--;

    free(removido);

    int aux = esvaziar(pilha);

    if (aux) 
        return TRUE;

    return FALSE;    
}

Item topo(Pilha *pilha) {
    return pilha->topo->item;
}


#endif