#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

#define STR_LEN 60

int i;
FILE *arq;
char linha[STR_LEN];
char *result;

struct _state {
    char name[STR_LEN];
    int isFinal;
    int isInitial;
};

struct _transition {
    struct _state *state1;
    struct _state *state2;
    char symbol[STR_LEN];
};

struct _afd {
    struct _state *states;
    struct _transition *transitions;
    char **alphabet;
    int statesCount;
    int transitionsCount;
    int symbolsCount;
} afd;

void populateAFDFromFile(char *inputFile);

void renderDot(char *outputFile);

void renderTxt(char *outputFile);

void createComplement();

#endif