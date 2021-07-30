#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STR_LEN 30

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

void render(char *outputFile, struct transition *transitions, int transitionCount);

void generateViewFile(char *inputFile, char *outputFile);

#endif