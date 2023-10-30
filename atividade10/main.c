#include <stdio.h>
#include "tabela_hash.h"

int main() {
    char* chave = "chave";
    char* dado = "dado";

    printf("Inserindo na tabela hash...\n");
    hash_table_put(chave, dado);

    printf("Verificando se a chave existe na tabela...\n");
    if (hash_table_contains(chave)) {
        printf("A chave existe na tabela.\n");
        printf("O valor associado à chave é: %s\n", hash_table_get(chave));
    } else {
        printf("A chave não existe na tabela.\n");
    }

    printf("Removendo a chave da tabela...\n");
    hash_table_remove(chave);

    printf("Verificando se a chave ainda existe na tabela...\n");
    if (hash_table_contains(chave)) {
        printf("A chave ainda existe na tabela.\n");
    } else {
        printf("A chave foi removida com sucesso.\n");
    }

    return 0;
}
