#include "header.h"

void renderTxt(char *outputFile)
{
    FILE *output = fopen(outputFile, "w");

    if (output == NULL) {
        printf("Erro ao abrir arquivo.");
        exit(EXIT_FAILURE);
    }

    fprintf(
        output,
        "%d\n",
        afd.statesCount
    );

    printTxtStateNames(afd.state, output);

    fprintf(
        output,
        "%d\n",
        afd.symbolsCount
    );

    printTxtSymbols(afd.alphabet, output);

    fprintf(
        output,
        "%d\n",
        afd.transitionsCount
    );

    printTxtTransitions(afd.transition, output);

    printTxtInitialStates(afd.state, output);

    fprintf(
        output,
        "%d\n",
        countFinalStates(afd.state, 0)
    );

    printTxtFinalStates(afd.state, output);

    fclose(output);
    
    printf("Arquivo %s criado com sucesso.\n", outputFile);
}