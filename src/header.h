#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STR_LEN 60

struct state {
    char name[STR_LEN];
    int isFinal;
    int isInitial;
    struct state *next;
};

typedef struct state _state;

struct transition {
    struct state *state1;
    struct state *state2;
    struct symbol *symbol;
    struct transition *next;
};

typedef struct transition _transition;

struct symbol {
    char content[STR_LEN];
    struct symbol *next;
};

typedef struct symbol _symbol;

struct _afd {
    struct state *state;
    struct transition *transition;
    struct symbol *alphabet;
    int statesCount;
    int transitionsCount;
    int symbolsCount;
} afd;

_state* findStateByName(char *name, _state *state);
_state* findInitialState(_state *state);
_symbol* findSymbol(char *content, _symbol *symbol);
_state* insertNewState(_state *state, char *name);
_symbol* insertNewSymbol(_symbol *symbol, char *content);
_transition* insertNewTransition(
    _transition *transition,
    char *state1,
    char *state2,
    char *symbol
);
void printStatesName(_state *state);
void printSymbols(_symbol *symbol);
void printTransitions(_transition *transition);
_state* recognizeSymbol(_state *state, char symbol);
_transition* findTransitionByStateAndSymbol(_transition *transition, _state *state, char symbol);

void createComplement(_state *state);

void printDotFinalStates(_state *state, FILE *output);
void printDotTransitions(_transition *transition, FILE *output);

void printTxtStateNames(_state *state, FILE *output);
void printTxtSymbols(_symbol *symbol, FILE *output);
void printTxtTransitions(_transition *transition, FILE *output);
void printTxtInitialStates(_state *state, FILE *output);
void printTxtFinalStates(_state *state, FILE *output);
int countFinalStates(_state *state, int count);

void populateAFDFromFile(char *inputFile);
void recognizeWords(char *inputFile, char *outputFile);

void renderDot(char *outputFile);
void renderTxt(char *outputFile);

#endif