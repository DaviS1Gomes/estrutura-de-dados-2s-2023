#include <stdio.h>

int soma_array(int variables[], int size){
    int i, resultado = 0;

    for (i = 0; i < size; i++) {
        resultado = resultado + variables[i];
    }

    printf("Conta: variables = %d", resultado);
    return resultado;
}

int main() {
    int array[] = {8, 7, 9, 6};
    int tamanho = sizeof(array) / sizeof(array[0]);
    soma_array(array, tamanho);

    return 0;
}
