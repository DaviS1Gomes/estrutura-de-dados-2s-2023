int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo_de_entrada\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = "arq_palavras_ordenado.txt";

    // Abrir o arquivo de entrada
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Contar o número de palavras no arquivo
    int numWords = 0;
    char buffer[100]; // Tamanho máximo de uma palavra

    while (fscanf(inputFile, "%s", buffer) != EOF) {
        numWords++;
    }

    // Voltar ao início do arquivo
    rewind(inputFile);

    // Ler as palavras para um array
    char **words = (char **)malloc(numWords * sizeof(char *));
    for (int i = 0; i < numWords; i++) {
        words[i] = (char *)malloc(100 * sizeof(char));
        fscanf(inputFile, "%s", words[i]);
    }

    // Ordenar as palavras usando o Bubble Sort
    bubbleSort(words, numWords);

    // Criar o arquivo de saída
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    // Escrever as palavras ordenadas no arquivo de saída
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\n", words[i]);
    }

    // Fechar os arquivos
    fclose(inputFile);
    fclose(outputFile);

    // Liberar memória alocada
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);

    printf("Palavras ordenadas e salvas em %s\n", outputFileName);

    return 0;
}