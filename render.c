#include "header.h"

void render(char *outputFile, struct transition *transitions, int transitionCount)
{

    FILE *output = fopen(outputFile, "w");

    if (output == NULL) {
        printf("Erro ao abrir arquivo.");
        exit(EXIT_FAILURE);
    }

    fputs("digraph finite_state_machine {\n", output);

    fputs("node [shape = doublecircle];\n", output);
    
    char lastUsedState[STR_LEN];
    for (int i=0; i<transitionCount; i++) {
        if (
            transitions[i].state1->isFinal &&
            strcmp(transitions[i].state1->name, lastUsedState)
        ) {
            fprintf(
                output, " %s",
                transitions[i].state1->name
            );
            strcpy(lastUsedState, transitions[i].state1->name);
        }
    }

    fputs(";\nnode [shape = circle];\n", output);
    for (int i=0; i<transitionCount; i++) {
        fprintf(
            output, "%s -> %s [label = \"%s\"];\n",
            transitions[i].state1->name,
            transitions[i].state2->name,
            transitions[i].symbol
        );
    }
    fputs("}\n", output);

    fclose(output);

    printf("Arquivo criado.");
}