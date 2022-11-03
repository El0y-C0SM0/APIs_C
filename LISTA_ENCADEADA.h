//Autor: Eloy Ribeiro
//Github: El0y-C0SM0

#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#define TRUE 1
#define FALSE 0

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
    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL) 
        return NULL;

    novo->item = &valor;
    novo->anterior = ant;
    novo->proximo = prox;

    return novo;
}

Lista *criar_lista() {
    Lista *novo = (Lista*) malloc(sizeof(Lista));

    if(novo == NULL) 
        return NULL;

    novo->quant = 0;
    novo->primeiro = novo->ultimo = NULL;

    return novo;
}

int tamanho(Lista *lista) {
    return lista->quant;
}

int esta_vazia(Lista *lista) {
    return (lista->quant == 0) ? TRUE : FALSE;
}

No *obter_no(Lista *lista, int pos) {
    if(pos < 0 || pos >= tamanho(lista)) return NULL;
    
    No* item_procurado;

    if(pos <= tamanho(lista) / 2) {
        item_procurado = lista->primeiro;

        for(register int i = 0; i < pos; i++) 
            item_procurado = item_procurado->proximo;
    }
    else {
        item_procurado = lista->ultimo;
            
        for(register int i = tamanho(lista); i > pos; i--) 
            item_procurado = item_procurado->anterior;
    }

    return item_procurado;
}

int inserir_inicio(Lista *lista, int item) {
    No *novo = cria_no(item, NULL, lista->primeiro);

    if(novo == NULL) return FALSE;

    if(esta_vazia(lista)) 
        lista->ultimo = novo;

    lista->primeiro = novo;
    lista->quant++;

    return TRUE;
}

int inserir_fim(Lista *lista, int item) {
    No *novo = cria_no(item, lista->ultimo, NULL);

    if(novo == NULL) return FALSE;

    if(esta_vazia(lista)) 
        lista->primeiro = novo;
        
    lista->ultimo = novo;
    lista->quant++;

    return TRUE;
}





#endif 
