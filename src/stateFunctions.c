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

_state* findFinalStates(_state *stateSearch, _state *stateResult)
{
    if (stateSearch == NULL) return stateResult;
    if (stateSearch->isFinal) {
       _state *newState = (_state*) malloc(sizeof(_state));

        strcpy(newState->name, stateSearch->name);
        newState->isFinal = 1;
        newState->isInitial = stateSearch->isInitial;
        newState->next = findFinalStates(stateSearch->next, stateResult);

        return newState;
    }

    return findFinalStates(stateSearch->next, stateResult);
}

_state* findNotFinalStates(_state *stateSearch, _state *stateResult)
{
    if (stateSearch == NULL) return stateResult;
    if (!stateSearch->isFinal) {
       _state *newState = (_state*) malloc(sizeof(_state));

        strcpy(newState->name, stateSearch->name);
        newState->isFinal = 1;
        newState->isInitial = stateSearch->isInitial;
        newState->next = findNotFinalStates(stateSearch->next, stateResult);

        return newState;
    }

    return findNotFinalStates(stateSearch->next, stateResult);
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

void printStatesName(_state *state)
{
    if (state != NULL) {
        printf("%s\n", state->name);
        printStatesName(state->next);
    }
}

int countFinalStates(_state *state, int count)
{
    if (state == NULL) return count;
    if (state->isFinal) count++;
    
    return countFinalStates(state->next, count);
}

_state* checkIfStateExists(_state *searchState, _state *state)
{
    if(searchState == NULL) return NULL;
    if (strcmp(searchState->name, state->name) == 0) return state;
    
    return checkIfStateExists(searchState->next, state);

}

int isSameState(_state *state1, _state *state2)
{
    return strcmp(state1->name, state2->name) == 0;
}