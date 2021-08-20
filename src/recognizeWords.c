#include "header.h"

int tryRecognizeWord(char *linha)
{
    _state *state = findInitialState(afd.state);
    for (int i=0; linha[i] != '\0'; i++) {
        if (recognizeSymbol(state, linha[i]) == NULL) {
            break;
        }
        state = recognizeSymbol(state, linha[i]);
    }
    
    if (state == NULL) return 0;
    return state->isFinal;
}

void recognizeWords(char *inputFile, char *outputFile)
{
    FILE *input = fopen(inputFile, "rt");

    char linha[STR_LEN];

    if (input == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(outputFile, "w");

    if (output == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(linha, STR_LEN, input)) {
        int isWordRecognized = tryRecognizeWord(linha);

        printf("%d\n", isWordRecognized);
    }

    fclose(input);
    fclose(output);
}