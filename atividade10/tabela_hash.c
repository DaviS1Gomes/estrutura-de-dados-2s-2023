#include "tabela_hash.h"
#include <string.h>

#define MAX_SIZE 100

char* hash_table[MAX_SIZE];

unsigned int hash(char *chave) {
    unsigned int h = 0;
    for (; *chave; chave++) {
        h = h * 101 + (unsigned int)*chave;
    }
    return h % MAX_SIZE;
}

void hash_table_put(char* chave, char* dado) {
    unsigned int index = hash(chave);
    hash_table[index] = dado;
}

char* hash_table_get(char* chave) {
    unsigned int index = hash(chave);
    return hash_table[index];
}

int hash_table_contains(char* chave) {
    unsigned int index = hash(chave);
    return (hash_table[index] != NULL);
}

void hash_table_remove(char* chave) {
    unsigned int index = hash(chave);
    hash_table[index] = NULL;
}
