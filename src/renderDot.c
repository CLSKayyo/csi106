#include "header.h"

// ALTERAR FUTURAMENTE

void renderDot(char *outputFile)
{

    FILE *output = fopen(outputFile, "w");

    if (output == NULL) {
        printf("Erro ao abrir arquivo.");
        exit(EXIT_FAILURE);
    }

    fputs("digraph finite_state_machine {\n", output);

    fputs("node [shape = doublecircle];\n", output);
    
    char lastUsedState[STR_LEN];
    for (int i=0; i<afd.transitionsCount; i++) {
        if (
            afd.transitions[i].state1->isFinal &&
            strcmp(afd.transitions[i].state1->name, lastUsedState)
        ) {
            fprintf(
                output, " %s",
                afd.transitions[i].state1->name
            );
            strcpy(lastUsedState, afd.transitions[i].state1->name);
        }
    }

    fputs(";\nnode [shape = circle];\n", output);
    
    for (int i=0; i<afd.transitionsCount; i++) {
        fprintf(
            output, "%s -> %s [label = \"%s\"];\n",
            afd.transitions[i].state1->name,
            afd.transitions[i].state2->name,
            afd.transitions[i].symbol
        );
    }

    fputs("}\n", output);

    fclose(output);

    printf("Arquivo %s criado com sucesso.\n", outputFile);
}