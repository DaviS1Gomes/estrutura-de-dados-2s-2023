#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s num1 num2 num3 ... numN\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int numbers[n];

    // Convertendo argumentos para inteiros e armazenando-os em um array
    for (int i = 0; i < n; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    // Chamando a função bubbleSort para ordenar os números
    bubbleSort(numbers, n);

    // Imprimindo a lista ordenada
    printf("Saída: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}