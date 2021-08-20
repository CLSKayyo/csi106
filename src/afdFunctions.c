#include "header.h"

_state* findStateByName(char *name, _state *state)
{
    if (state == NULL) return NULL;
    if (strcmp(state->name, name) == 0) return state;
    return findStateByName(name, state->next);
}

_state* findInitialState(_state *state)
{
    if (state == NULL) return NULL;
    if (state->isInitial) return state;
    return findInitialState(state->next);
}

_symbol* findSymbol(char *content, _symbol *symbol) 
{
    if (symbol == NULL) return NULL;
    if (strcmp(symbol->content, content) == 0) return symbol;
    return findSymbol(content, symbol->next);
}

_state* insertNewState(_state *state, char *name)
{
    _state *newState = (_state*) malloc(sizeof(_state));

    strcpy(newState->name, name);
    newState->isFinal = 0;
    newState->isInitial = 0;
    newState->next = state;

    return newState;
}

_symbol* insertNewSymbol(_symbol *symbol, char *content)
{
    _symbol *newSymbol = (_symbol*) malloc(sizeof(_symbol));
    strcpy(newSymbol->content, content);
    newSymbol->next = symbol;

    return newSymbol;
}

_transition* insertNewTransition(
    _transition *transition,
    char *state1,
    char *state2,
    char *symbol
) {
    _transition *newTransition = (_transition*) malloc(sizeof(_transition));

    newTransition->state1 = findStateByName(state1, afd.state);
    newTransition->state2 = findStateByName(state2, afd.state);
    newTransition->symbol = findSymbol(symbol, afd.alphabet);

    newTransition->next = transition;

    return newTransition;
}

_transition* findTransitionByStateAndSymbol(_transition *transition, _state *state, char symbol)
{
    if (transition == NULL) return NULL;
    if (
        transition->state1 == state && 
        transition->symbol->content[0] == symbol
    ) return transition;
    return findTransitionByStateAndSymbol(transition->next, state, symbol);
}

_state* recognizeSymbol(_state *state, char symbol)
{
    _transition *transition = findTransitionByStateAndSymbol(afd.transition, state, symbol);
    if (transition == NULL) return NULL;
    return transition->state2;
}

void printStatesName(_state *state)
{
    if (state != NULL) {
        printf("%s\n", state->name);
        printStatesName(state->next);
    }
}

void printSymbols(_symbol *symbol)
{
    if (symbol != NULL) {
        printf("%s\n", symbol->content);
        printSymbols(symbol->next);
    }
}

void printTransitions(_transition *transition)
{
    if (transition != NULL) {
        printf(
            "%s %s %s\n",
            transition->state1->name,
            transition->symbol->content,
            transition->state2->name
        );
        printTransitions(transition->next);
    }
}

void createComplement(_state *state)
{
    if (state != NULL) {
        state->isFinal = (state->isFinal+1)%2;
        createComplement(state->next);
    }
}