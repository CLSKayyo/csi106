#include "header.h"

_symbol* findSymbol(char *content, _symbol *symbol) 
{
    if (symbol == NULL) return NULL;
    if (strcmp(symbol->content, content) == 0) return symbol;
    return findSymbol(content, symbol->next);
}

_symbol* insertNewSymbol(_symbol *symbol, char *content)
{
    _symbol *newSymbol = (_symbol*) malloc(sizeof(_symbol));
    strcpy(newSymbol->content, content);
    newSymbol->next = symbol;

    return newSymbol;
}

_state* recognizeSymbol(_state *state, char symbol)
{
    _transition *transition = findTransitionByStateAndSymbol(afd.transition, state, symbol);
    if (transition == NULL) return NULL;
    return transition->state2;
}

void printSymbols(_symbol *symbol)
{
    if (symbol != NULL) {
        printf("%s\n", symbol->content);
        printSymbols(symbol->next);
    }
}