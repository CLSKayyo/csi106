#include "header.h"

void populateAFDFromFile(char *inputFile)
{
    FILE *input = fopen(inputFile, "rt");

    afd.statesCount = 0;
    afd.symbolsCount = 0;
    afd.transitionsCount = 0;

    char linha[STR_LEN];

    if (input == NULL) {
        printf("Erro ao abrir arquivo.");
        exit(EXIT_FAILURE);
    }

    int statesCount =  atoi(fgets(linha, STR_LEN, input));

    afd.states = (struct _state*) malloc(statesCount*sizeof(struct _state));

    for (int i=0; i<statesCount; i++) {
        char *name = fgets(linha, STR_LEN, input);
        strtok(name, "\n");
        strcpy(afd.states[i].name, name);
        afd.states[i].isInitial = 0;
        afd.states[i].isFinal = 0;
    }

    afd.statesCount = statesCount;

    int symbolCount = atoi(fgets(linha, STR_LEN, input));

    afd.alphabet = (char**) malloc(symbolCount*sizeof(char));

    for (int i=0; i<symbolCount; i++) {
        char *symbol = fgets(linha, STR_LEN, input);
        strtok(symbol, "\n");
        afd.alphabet[i] = (char*) malloc(sizeof(char));
        strcpy(afd.alphabet[i], symbol);
    }

    afd.symbolsCount = symbolCount;

    int transitionCount = atoi(fgets(linha, STR_LEN, input));

    afd.transitionsCount = transitionCount;

    struct _transition transitions[transitionCount];
    for (int i=0; i<transitionCount; i++) {
        char *newLine = fgets(linha, STR_LEN, input); 
        char line[STR_LEN];
        strcpy(line, newLine);

        char state1[STR_LEN];
        char state2[STR_LEN];
        char symbol[STR_LEN];

        int x = 0;
        int y = 0;

        while (x<sizeof(line)) {
            if (line[x] == ' ') {
                x++;
                break;
            }

            state1[y] = line[x];
            state1[y+1] = 0;
            x++;
            y++;
        }

        y = 0;

        while (x<sizeof(line)) {
            if (line[x] == ' ') {
                x++;
                break;
            }

            symbol[y] = line[x];
            symbol[y+1] = 0;
            x++;
            y++;
        }

        y = 0;

        while (x<sizeof(line)) {
            if (line[x] == ' ') {
                x++;
                break;
            }

            state2[y] = line[x];
            state2[y+1] = 0;
            x++;
            y++;
        }

        strtok(state1, "\n");
        strtok(state2, "\n");

        struct _transition transition;

        strcpy(transition.symbol, symbol);

        for (int j=0; j<statesCount; j++) {
            if (strcmp(afd.states[j].name, state1) == 0) {
                transition.state1 = &afd.states[j];
                break;
            }
        }

        for (int j=0; j<statesCount; j++) {
            if (strcmp(afd.states[j].name, state2) == 0) {
                transition.state2 = &afd.states[j];
                break;
            }
        }

        transitions[i] = transition;
    }

    afd.transitions = transitions;

    char *line = fgets(linha, STR_LEN, input);
    char initialState[STR_LEN];

    strcpy(initialState, line);

    for (int i=0; i<statesCount; i++) {
        if (strcmp(afd.states[i].name, initialState) == 0) {
            afd.states[i].isInitial = 1;
            break;
        }
    }

    int finalStatesCount = atoi(fgets(linha, STR_LEN, input));

    for (int i=0; i<finalStatesCount; i++) {
        char *newLine = fgets(linha, STR_LEN, input);
        char finalState[STR_LEN];

        strcpy(finalState, newLine);

        for (int j=0; j<statesCount; j++) {
            if (strcmp(afd.states[j].name, finalState) == 0) {
                afd.states[j].isFinal = 1;
            }
        }
    }

    fclose(input);
    printf("AFD criado com sucesso a partir do arquivo %s.\n", inputFile);
}