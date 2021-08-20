#include "header.h"

void renderDot(char *outputFile)
{
    FILE *output = fopen(outputFile, "w");

    if (output == NULL) {
        printf("Erro ao abrir arquivo.");
        exit(EXIT_FAILURE);
    }

    fputs("digraph finite_state_machine {\n", output);
    fputs("node [shape = doublecircle];\n", output);

    printDotFinalStates(afd.state, output);

    fputs(";\nnode [shape = circle];\n", output);

    printDotTransitions(afd.transition, output);

    fputs("}\n", output);

    fclose(output);

    printf("Arquivo %s criado com sucesso.\n", outputFile);
}