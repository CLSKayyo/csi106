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

    for (int i=0; i<afd.statesCount; i++) {
        fprintf(
            output,
            "%s\n",
            afd.states[i].name
        );
    }

    fprintf(
        output,
        "%d\n",
        afd.symbolsCount
    );

    for (int i=0; i<afd.symbolsCount; i++) {
        fprintf(
            output,
            "%s\n",
            afd.alphabet[i]
        );
    }

    fprintf(
        output,
        "%d\n",
        afd.transitionsCount
    );

    for (int i=0; i<afd.transitionsCount; i++) {
        fprintf(
            output,
            "%s %s %s\n",
            afd.transitions[i].state1->name,
            afd.transitions[i].symbol,
            afd.transitions[i].state2->name
        );
    }

    for (int i=0; i<afd.statesCount; i++) {
        if (afd.states[i].isInitial) {
            fprintf(
                output,
                "%s\n",
                afd.states[i].name
            );
        }
    }

    int finalStatesCount = 0;

    for (int i=0; i<afd.statesCount; i++) {
        if (afd.states[i].isFinal) {
            finalStatesCount++;
        }
    }

    fprintf(
        output,
        "%d\n",
        finalStatesCount
    );

    for (int i=0; i<afd.statesCount; i++) {
        if (afd.states[i].isFinal) {
            fprintf(
                output,
                "%s\n",
                afd.states[i].name
            );
        }
    }

    fclose(output);
    
    printf("Arquivo %s criado com sucesso.\n", outputFile);
}