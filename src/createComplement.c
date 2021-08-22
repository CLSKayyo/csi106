#include "header.h"

void createComplement(_state *state)
{
    if (state != NULL) {
        state->isFinal = (state->isFinal+1)%2;
        createComplement(state->next);
    }
}