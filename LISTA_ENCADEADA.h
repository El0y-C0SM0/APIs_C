//Autor: Eloy Ribeiro
//Github: El0y-C0SM0

#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#define FALSE 0
#define TRUE 1
#define ERR_INDICE_INVALIDO 2
#define ERR_LISTA_VAZIA 3

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

    novo->item = valor;
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

        for(int i = 0; i < pos; i++) 
            item_procurado = item_procurado->proximo;
    }
    else {
        item_procurado = lista->ultimo;
            
        for(int i = tamanho(lista); i > pos; i--) 
            item_procurado = item_procurado->anterior;
    }

    return item_procurado;
}

int inserir_inicio(Lista *lista, Item item) {
    No *novo = cria_no(item, NULL, lista->primeiro);

    if(novo == NULL) return FALSE;

    if(esta_vazia(lista)) 
        lista->ultimo = novo;

    lista->primeiro = novo;
    lista->quant++;

    return TRUE;
}

int inserir_fim(Lista *lista, Item item) {
    No *novo = cria_no(item, lista->ultimo, NULL);

    if(novo == NULL) return FALSE;

    if(esta_vazia(lista)) 
        lista->primeiro = novo;
        
    lista->ultimo = novo;
    lista->quant++;

    return TRUE;
}

int inserir_posicao(Lista *lista, Item item, int pos) {
    if(pos < 0 || pos >= tamanho(lista)) return ERR_INDICE_INVALIDO;

    No *antigo = obter_no(lista, pos);
    No *novo = cria_no(item, antigo->anterior, antigo);

    if(novo == NULL) return FALSE;

    lista->quant++;

    return TRUE;
}

int remover_inicio(Lista *lista, Item valor_removido) {
    if(esta_vazia(lista)) return ERR_LISTA_VAZIA;

    No *eliminado = lista->primeiro;
    valor_removido = eliminado->item;

    lista->primeiro = eliminado->proximo;
    lista->primeiro->anterior = NULL;
    lista->quant--;

    free(eliminado);

    return FALSE;
}

int remover_fim(Lista *lista, Item valor_removido) {
    if(esta_vazia(lista)) return ERR_LISTA_VAZIA;

    No *eliminado = lista->ultimo;
    valor_removido = eliminado->item;

    lista->ultimo = eliminado->anterior;
    lista->ultimo->proximo = NULL;
    lista->quant--;

    free(eliminado);

    return FALSE;
}

int remover_posicao(Lista *lista, Item valor_removido, int pos) {
    if(esta_vazia(lista)) return ERR_LISTA_VAZIA;

    if(pos < 0 || pos >= tamanho(lista)) return ERR_INDICE_INVALIDO;

    No *eliminado = obter_no(lista, pos);
    
    valor_removido = eliminado->item;

    No *eliminado_anterior = eliminado->anterior->proximo;

    eliminado_anterior->proximo = eliminado->proximo;

    lista->quant--;

    free(eliminado);

    return FALSE;
}

int atribuir_valor(Lista *lista, Item valor, int pos) {
    if(esta_vazia(lista)) return ERR_LISTA_VAZIA;

    if(pos < 0 || pos >= tamanho(lista)) return ERR_INDICE_INVALIDO;

    No *elemento = obter_no(lista, pos);

    elemento->item = valor;

    return TRUE;
}


#endif 
