#include "header.h"

void generateViewFile(char *inputFile, char *outputFile)
{
    arq = fopen(inputFile, "rt");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo.");
        exit(EXIT_FAILURE);
    }

    int statesCount =  atoi(fgets(linha, STR_LEN, arq));

    struct state states[statesCount];

    for (int i=0; i<statesCount; i++) {
        char *name = fgets(linha, STR_LEN, arq);
        strtok(name, "\n");
        strcpy(states[i].name, name);
        states[i].isInitial = 0;
        states[i].isFinal = 0;
    }

    // getting the alphabet

    int symbolCount = atoi(fgets(linha, STR_LEN, arq));

    char alphabet[symbolCount][STR_LEN];

    for (int i=0; i<symbolCount; i++) {
        char *symbol = fgets(linha, STR_LEN, arq);
        strtok(symbol, "\n");
        strcpy(alphabet[i], symbol);
    }
    
    // Transitions

    int transitionCount = atoi(fgets(linha, STR_LEN, arq));

    struct transition transitions[transitionCount];
    
    for (int i=0; i<transitionCount; i++) {
        char line[STR_LEN];
        strcpy(line, fgets(linha, STR_LEN, arq));

        char state1[STR_LEN];
        char state2[STR_LEN];
        char symbol[STR_LEN];

        int j = 0;
        int x = 0;
        while (j<(sizeof line)) {
            if (line[j] == ' '){
                j++;
                break;
            }

            state1[x] = line[j];
            j++;
            x++;
        }

        x = 0;

        while (j<(sizeof line)) {
            if (line[j] == ' '){
                j++;
                break;
            }

            symbol[x] = line[j];
            j++;
            x++;
        }

        x = 0;

        while (j<(sizeof line)) {
            if (line[j] == ' '){
                j++;
                break;
            }

            state2[x] = line[j];
            j++;
            x++;
        }
        strtok(state1, "\n");
        strtok(state2, "\n");

        struct transition lineTransition;

        strcpy(lineTransition.symbol, symbol);

        for (int y=0; y<statesCount; y++) {
            printf("%d\n", strcmp(states[y].name, state1));
            printf("%s\n", states[y].name);
            printf("%s\n", state1);
            if (strcmp(states[y].name, state1) == 0) {
                lineTransition.state1 = &states[y];
            }
        }

        for (int y=0; y<statesCount; y++) {
            if (strcmp(states[y].name, state2) == 0) {
                lineTransition.state2 = &states[y];
            }
        }

        transitions[i] = lineTransition;
    }
    
    // getting initial state and final states

    char *line = fgets(linha, STR_LEN, arq);
    char initialState[STR_LEN];

    strcpy(initialState, line);
    

    for (int i=0; i<statesCount; i++) {
        if (strcmp(states[i].name, initialState) == 0) {
            states[i].isInitial = 1;
        }
    }

    int finalCount = atoi(fgets(linha, STR_LEN, arq));

    for (int i=0; i<finalCount; i++) {
        char *newLine = fgets(linha, STR_LEN, arq);
        char finalState[STR_LEN];

        strcpy(finalState, newLine);

        for (int j=0; j<statesCount; j++) {
            if (strcmp(states[i].name, finalState) == 0) {
                states[i].isFinal = 1;
            }
        }
    }

    render(outputFile, transitions, transitionCount);

    fclose(arq);
}