#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia);
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);
    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);
    No* lista = lista_criar();
    lista_inserir_fim(lista, 'A');
    lista_inserir_fim(lista, 'B');
    lista_inserir_fim(lista, 'C');
    lista_inserir_fim(lista, 'A');
    lista_inserir_fim(lista, 'D');

    char busca = 'B';
    if (lista_verificar_existencia(lista, busca)) {
        printf("O valor '%c' existe na lista.\n", busca);
    } else {
        printf("O valor '%c' não existe na lista.\n", busca);
    }

    int ocorrencias = lista_verificar_ocorrencias(lista, busca);
    printf("O valor '%c' ocorre %d vezes na lista.\n", busca, ocorrencias);

    printf("Lista: ");
    lista_imprimir(lista);
    printf("Lista Inversa: ");
    lista_imprimir_inversa(lista);
    printf("\n");

    lista_inserir_no_i(lista, 'E', 2);
    printf("Inserindo 'E' na posição 2:\n");
    lista_imprimir(lista);

    lista_remover_no_i(lista, 3);
    printf("Removendo o elemento na posição 3:\n");
    lista_imprimir(lista);

    char valor_remover = 'A';
    lista_remover_no(lista, valor_remover);
    printf("Removendo todos os elementos com valor '%c':\n", valor_remover);
    lista_imprimir(lista);

    lista_destruir(lista);
    return 0;
    exit(0);
}
