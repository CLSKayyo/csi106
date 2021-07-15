#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STR_LEN 100

int i;
FILE *arq;
char linha[STR_LEN];
char *result;

struct state {
    char name[STR_LEN];
    int isFinal;
    int isInitial;
};

struct transition {
    struct state *state1;
    struct state *state2;
    char symbol[STR_LEN];
};

int main(void)
{

    arq = fopen("afd.txt", "rt");

    if (arq == NULL) {
        return 1;
    }

    // getting state names

    int statesCount =  atoi(fgets(linha, STR_LEN, arq));

    struct state states[statesCount];

    for (int i=0; i<statesCount; i++) {
        char *name = fgets(linha, STR_LEN, arq);
        strcpy(states[i].name, name);
        states[i].isInitial = 0;
        states[i].isFinal = 0;
    }

    // getting the alphabet

    int symbolCount = atoi(fgets(linha, STR_LEN, arq));

    char alphabet[symbolCount][STR_LEN];

    for (int i=0; i<symbolCount; i++) {
        char *symbol = fgets(linha, STR_LEN, arq);
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

        struct transition lineTransition;

        strcpy(lineTransition.symbol, symbol);

        for (int y=0; y<statesCount; y++) {
            if (strcmp(states[y].name, state1) == 10) {
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

    // printing items

    printf("Estados:\n");
    for (int i=0; i<statesCount; i++) {
        printf("Estado %d\n", i+1);
        printf("Nome: %s\n", states[i].name);
        printf("Inicial: %d\n", states[i].isInitial);
        printf("Final: %d\n", states[i].isFinal);
        printf("--------\n");
    }

    printf("Transicoes:\n");
    for (int i=0; i<transitionCount; i++) {
        printf("Transicao %d\n", i+1);
        printf("Estado 1: %s\n", transitions[i].state1->name);
        printf("Símbolo: %s\n", transitions[i].symbol);
        printf("Estado 2: %s\n", transitions[i].state2->name);
        printf("--------\n");
    }

    fclose(arq);
}
