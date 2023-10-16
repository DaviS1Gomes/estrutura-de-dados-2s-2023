#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

double calcularTempoMedioInsercao(No* lista, FILE* arquivo) {
    clock_t inicio, fim;
    double tempoTotal = 0.0;
    char linha[20];
    float valor;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        valor = atof(linha);

        inicio = clock();
        No* novoNo = (No*)malloc(sizeof(No));
        novoNo->valor = valor;
        lista_inserir_no_ordenado(lista, novoNo);
        fim = clock();

        tempoTotal += ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    }

    return tempoTotal;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L){
    if(L != NULL){
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }
}

No* lista_criar() {
    No* cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = NULL;
    return cabeca;
}

void lista_inserir_fim(No* L, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    No* atual = L;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novoNo;
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int count = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            count++;
        }
        atual = atual->proximo;
    }
    return count;
}

void lista_imprimir(No* L) {
    No* atual = L->proximo;
    while (atual != NULL) {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo != NULL) {
        lista_imprimir_inversa(L->proximo);
        printf("%c ", L->proximo->valor);
    }
}

void lista_inserir_no_i(No* L, char valor, int i) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    No* atual = L;
    for (int j = 0; j < i; j++) {
        if (atual->proximo == NULL) {
            free(novoNo);
            return; 
        }
        atual = atual->proximo;
    }
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    for (int j = 0; j < i; j++) {
        if (atual->proximo == NULL) {
            return; 
        }
        atual = atual->proximo;
    }
    No* temp = atual->proximo;
    if (temp != NULL) {
        atual->proximo = temp->proximo;
        free(temp);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    No* atual = L;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor_busca) {
            No* temp = atual->proximo;
            atual->proximo = temp->proximo;
            free(temp);
        } else {
            atual = atual->proximo;
        }
    }
}

void lista_destruir(No* L) {
    No* atual = L->proximo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(L);
}