//Autor: Eloy Ribeiro
//Github: El0y-C0SM0

#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define ERR_INDICE_INVALIDO 2
#define ERR_LISTA_VAZIA 3
#define ERR_SEM_ESPACO 4
#define N_ACHOU -1

typedef int Item;

typedef struct {
    Item *items;     // vetor de items
    int tamanho;    // número de elementos armazenados na lista
    int limite;     /* capacidade máxima, número máximo
                       de items que podem ser inseridos na lista, 
                       sem necessidade de realocar memória */
    int janela; //janela de crescimento da lista.
} ArrayList;

/**
 * Cria uma lista vazia.
 * @return  Retona uma lista vazia.
 *          Se retorno for NULL, memória insuficiente.  
 */
ArrayList* criar_lista(int tam, int janela) {
    ArrayList *lista = (ArrayList*) malloc(sizeof(ArrayList));
    
    // se há memória
    if (lista == NULL) 
        return NULL;    

    
    lista->tamanho = 0;                  // lista vazia
    lista->limite = tam;    // capacidade inicial
    lista->janela = janela;
    // cria vetor para armazenar os items de dados
    lista->items = (int*) malloc(lista->limite * sizeof(Item));

    if (lista->items == NULL) // não há memória
        return NULL;

    return lista;                        // retorna a lista criada e inicializada
}

/**
 * Recebe como parametro: uma lista.
 * Retorna o tamanho dela.
*/
int tamanho(ArrayList *lista) {
    return (lista == NULL) ? 0 : lista->tamanho;
}

/**
 * Recebe como parametro: uma lista
 * verifica se lista está vazia
 * @return TRUE se está vazia
 *         FALSE se não está
*/
int esta_vazia(ArrayList *lista) {
    return (tamanho(lista) == 0);
}

/**
 * Recebe como parametro: uma lista.
 * @return TRUE se é expansivel
 *         FALSE se não é expansivel
 */
int expansivel(ArrayList *lista) {
    return (lista->janela == 0) ? FALSE : TRUE;
}

/**
 *  Insere @code{item} no inicio de @code{lista}
 *  @param lista Lista na qual será inserido o @code{item}.
 *  @param item Item que será inserido em @code{lista}.
 *  @return TRUE se @code{item} for inserido em @code{lista}.
 *          FALSE se não houver memória. 
 */
int inserir_inicio(ArrayList *lista, int item) {
    if(lista->tamanho == lista->limite) {
        if(expansivel(lista)) {
            lista->limite += lista->janela;
            lista->items = (Item*) realloc(lista->items, lista->janela * sizeof(Item));
        }
        else 
            return FALSE;    
    }
    
    for (int i = lista->tamanho; i > 0; i--) 
        lista->items[i] = lista->items[i - 1];
    
    lista->items[0] = item;
    lista->tamanho++;

    return TRUE;
}

/** Insere @code{item} no final de @code{lista}
 *  @param lista Lista na qual será inserido o @code{item}.
 *  @param item Item que será inserido em @code{lista}.
 *  @return TRUE se @code{item} for inserido em @code{lista}.
 *          FALSE se não houver memória. */
int inserir_fim(ArrayList *lista, int item) {
    if(lista->tamanho == lista->limite) {
        if(expansivel(lista)) {
            lista->limite += lista->janela;
            lista->items = (Item*) realloc(lista->items, lista->janela * sizeof(Item));
        }
        else 
            return FALSE;    
    }
    
    lista->items[lista->tamanho] = item;
    lista->tamanho++;

    return TRUE;
}

/** 
 *  Insere @code{item} numa posição @code{pos} de @code{lista}
 *  @param lista Lista na qual será inserido o @code{item}.
 *  @param item Item que será inserido em @code{lista}.
 *  @param pos  Posição na qual o @code{item} deverá ser inserido.
 *  @return TRUE se @code{item} for inserido em @code{lista}
 *          FALSE se não houver memória 
 *          ERR_INDICE_INVALIDO se posição @code{pos} não é válida (@code{pos} < 0 || @code{pos} >= tamanho)
 */
int inserir_posicao(ArrayList *lista, int item, int pos, int *erro) {
    *erro = FALSE;
    if(lista->tamanho == lista->limite) {
        if(expansivel(lista)) {
            lista->limite += lista->janela;
            lista->items = (Item*) realloc(lista->items, lista->janela * sizeof(Item));
        }
        else {
            *erro = ERR_SEM_ESPACO;
            return FALSE;    
        }
    }

    if(pos < 0 || pos > tamanho(lista)) {
        *erro = ERR_INDICE_INVALIDO;
        return FALSE;
    }
    
    for(int i = lista->tamanho; i > pos; i--) 
        lista->items[i] = lista->items[i - 1];
    lista->items[pos] = item;

    lista->tamanho++;

    return TRUE;
}

/** Remove um @code{item} no inicio de @code{lista}
 *  @param lista Lista na qual será removio um @code{item}.
 *  @return se não houve erro retorna TRUE.
 *          ERR_LISTA_VAZIA se não existem itens em @code{lista}. */
int remover_inicio(ArrayList *lista) {
    if(esta_vazia(lista)) {
        return ERR_LISTA_VAZIA;
    }

    lista->tamanho--;

    for(int i = 0; i < lista->tamanho; i++)
        lista->items[i] = lista->items[i + 1];

    return TRUE;
}

/** Remove um @code{item} no final de @code{lista}
 *  @param lista Lista na qual será removio um @code{item}.
 *  @return se não houve erro retorna TRUE.
 *          ERR_LISTA_VAZIA se não existem itens em @code{lista}. */
int remover_fim(ArrayList *lista) {
    if(esta_vazia(lista)) {
        return ERR_LISTA_VAZIA;
    }

    lista->tamanho--;

    return TRUE;
}

/** Remove um @code{item} na posição @code{pos} de @code{lista}
 *  @param lista Lista na qual será removio um @code{item}.
 *  @param pos  Posição na qual será retirado o @code{item}.
 *  @return se não houve erro retorna TRUE.
 *          ERR_LISTA_VAZIA se não existem itens em @code{lista}.
 *          ERR_INDICE_INVALIDO se posição @code{pos} não é válida (@code{pos} < 0 || @code{pos} >= tamanho) */
int remover_posicao(ArrayList *lista, int pos) {
    if(esta_vazia(lista)) 
        return ERR_LISTA_VAZIA;
    
    if(pos < 0 || pos >= tamanho(lista)) 
        return ERR_INDICE_INVALIDO;

    lista->tamanho--;

    for(int i = pos; i < lista->tamanho; i++)
        lista->items[i] = lista->items[i + 1];

    return TRUE;
}
 
/** Recupera de @code{lista} o @code{item} na posição @code{pos}
 *  @param lista Lista que contém o @code{item}.
 *  @param pos  Posição na qual está o @code{item}.
 *  @return ERR_INDICE_INVALIDO se houve erro ou o item. */
int obter_item(ArrayList *lista, int pos) {
    return (pos < 0 || pos >= tamanho(lista)) ? ERR_INDICE_INVALIDO : lista->items[pos];
}

/** Atribui novo @code{item} à posição @code{pos} de @code{lista}
 *  @param lista Lista que contém os items.
 *  @param pos  Posição na qual será atribuído o @code{item}.
 *  @param item Novo item que sera atribuído a @code{lista}
 *  @return ERR_INDICE_INVALIDO se posição @code{pos} não é válida (@code{pos} < 0 || @code{pos} >= tamanho).
 *          TRUE se for possível. */
int atribuir_valor(ArrayList *lista, int pos, int item) {
    if(pos < 0 || pos >= tamanho(lista)) 
        return ERR_INDICE_INVALIDO;

    lista->items[pos] = item;

    return TRUE;
}

/** Acha a primeira posição de item @code{item} na lista  @code{lista}
 * @param lista Lista que contém os items.
 * @param item É o item que deseja achar a posição
 * @return A posição do item @code{item} 
 *         ou N_ACHOU (-1) se o item não existe ou não foi possivel acha-lo*/
int obtem_posicao(ArrayList *lista, Item item) {
    int posicao = N_ACHOU;

    for(int i = 0; i < lista->tamanho; i++) {
        if(lista->items[i] == item)
            posicao = i;
    }

    return (posicao == -1) ? N_ACHOU : posicao;
}

/** Acha a ultima posição de item @code{item} na lista  @code{lista}
 * @param lista Lista que contém os items.
 * @param item É o item que deseja achar a posição
 * @return A posição do item @code{item} 
 *         ou N_ACHOU (-1) se o item não existe ou não foi possivel acha-lo*/
int obtem_ultima_posicao(ArrayList *lista, Item item) {
    int posicao = -1;

    for(int i = lista->tamanho; i >= 0; i--) {
        if(lista->items[i] == item)
            posicao = i;
    }

    return (posicao == -1) ? N_ACHOU : posicao;
}

#endif