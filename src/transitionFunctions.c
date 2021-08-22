#include "header.h"

void insertTransitionLast(_transition *transition, _transition *toInsert)
{
    if (transition->next == NULL) {
        transition->next = toInsert;
    } else {
        insertTransitionLast(transition->next, toInsert);
    }
}

_transition* checkAndDeleteTransitionByState(_transition *transition, _transition *resultTransition, _state *state)
{
    if (transition == NULL) return resultTransition;
    printf("%s\n", transition->state1->name);
    if (isSameState(transition->state1, state)) {
        if (resultTransition == NULL) {
            resultTransition = transition;
        } else {
            insertTransitionLast(resultTransition, transition);
        }
    }
    return checkAndDeleteTransitionByState(transition->next, resultTransition, state);
}

void deleteTransitionsWithStates(_transition *transition, _state *state)
{
    if (transition != NULL) {
        if (transition->next != NULL && isSameState(transition->next->state1, state)) {
            _transition *temp = transition->next;
            transition->next = transition->next->next;
            free(temp);
            afd.transitionsCount--;
            deleteTransitionsWithStates(transition, state);

        } else {
            deleteTransitionsWithStates(transition->next, state);
        }

    }
}

void deleteTransitionsWithNotUsedStates(_state *state)
{
    if (state != NULL) {
        deleteTransitionsWithStates(afd.transition, state);
        deleteTransitionsWithNotUsedStates(state->next);
    }
}

_transition* insertNewTransition(_transition *transition, char *state1, char *state2, char *symbol)
{
    _transition *newTransition = (_transition*) malloc(sizeof(_transition));

    newTransition->state1 = findStateByName(state1, afd.state);
    newTransition->state2 = findStateByName(state2, afd.state);
    newTransition->symbol = findSymbol(symbol, afd.alphabet);

    newTransition->next = transition;

    return newTransition;
}

_transition* findTransitionByStateAndSymbol(_transition *transition, _state *state, char symbol)
{
    if (transition == NULL || transition->state1 == NULL || state == NULL) return NULL;
    if (
        strcmp(transition->state1->name, state->name) == 0 && 
        transition->symbol->content[0] == symbol
    ) return transition;
    return findTransitionByStateAndSymbol(transition->next, state, symbol);
}

_transition* findTransitionByLastStateAndSymbol(_transition *transition, _state *state, char symbol)
{
    if (transition == NULL || transition->state2 == NULL || state == NULL) return NULL;
    if (
        strcmp(transition->state2->name, state->name) == 0 && 
        transition->symbol->content[0] == symbol
    ) return transition;
    return findTransitionByStateAndSymbol(transition->next, state, symbol);
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