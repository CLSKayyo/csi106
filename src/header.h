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

#include "declarations.c"

#endif