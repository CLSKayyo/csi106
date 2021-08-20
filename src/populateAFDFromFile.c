#include "header.h"

void populateAFDFromFile(char *inputFile)
{
    FILE *input = fopen(inputFile, "rt");

    char linha[STR_LEN];

    if (input == NULL) {
        printf("Erro ao abrir arquivo.");
        exit(EXIT_FAILURE);
    }

    int statesCount =  atoi(fgets(linha, STR_LEN, input));
    afd.statesCount = statesCount;

    _state *state = NULL;
    for (int i=0; i<statesCount; i++) {
        char *name = fgets(linha, STR_LEN, input);
        strtok(name, "\n");
        state = insertNewState(state, name);
    }

    afd.state = state;

    int symbolCount = atoi(fgets(linha, STR_LEN, input));
    afd.symbolsCount = symbolCount;

    _symbol *symbol = NULL;
    for (int i=0; i<symbolCount; i++) {
        char *content = fgets(linha, STR_LEN, input);
        strtok(content, "\n");
        symbol = insertNewSymbol(symbol, content);
    }

    afd.alphabet = symbol;

    int transitionCount = atoi(fgets(linha, STR_LEN, input));
    afd.transitionsCount = transitionCount;

    _transition *transition = NULL;
    for (int i=0; i<transitionCount; i++) {
        char *newLine = fgets(linha, STR_LEN, input); 
        char line[STR_LEN];
        strcpy(line, newLine);

        char state1[STR_LEN];
        char state2[STR_LEN];
        char symbolContent[STR_LEN];

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

            symbolContent[y] = line[x];
            symbolContent[y+1] = 0;
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

        transition = insertNewTransition(transition, state1, state2, symbolContent);
    }

    afd.transition = transition;

    char *line = fgets(linha, STR_LEN, input);
    char initialState[STR_LEN];
    strcpy(initialState, line);
    strtok(initialState, "\n");
    findStateByName(initialState, afd.state)->isInitial = 1;

    int finalStatesCount = atoi(fgets(linha, STR_LEN, input));

    for (int i=0; i<finalStatesCount; i++) {
        char *newLine = fgets(linha, STR_LEN, input);
        char finalState[STR_LEN];
        strcpy(finalState, newLine);
        strtok(finalState, "\n");

        findStateByName(finalState, afd.state)->isFinal = 1;
    }

    fclose(input);

    printf("AFD criado com sucesso a partir do arquivo %s.\n", inputFile);
}