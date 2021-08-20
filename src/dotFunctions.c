#include "header.h"

void printDotFinalStates(_state *state, FILE *output)
{
    if (state != NULL) {
        if (state->isFinal == 1) {
            fprintf(
                output, " %s",
                state->name
            );
        }
        printDotFinalStates(state->next, output);
    }
}

void printDotTransitions(_transition *transition, FILE *output)
{
    if (transition != NULL) {
        fprintf(
            output,
            "%s -> %s [label = \"%s\"]\n",
            transition->state1->name,
            transition->state2->name,
            transition->symbol->content
        );
        printDotTransitions(transition->next, output);
    }
}