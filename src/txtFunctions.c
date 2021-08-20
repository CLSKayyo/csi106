#include "header.h"

void printTxtStateNames(_state *state, FILE *output)
{
    if (state != NULL) {
        fprintf(
            output,
            "%s\n",
            state->name
        );
        printTxtStateNames(state->next, output);
    }
}

void printTxtSymbols(_symbol *symbol, FILE *output)
{
    if (symbol != NULL) {
        fprintf(
            output,
            "%s\n",
            symbol->content
        );
        printTxtSymbols(symbol->next, output);
    }
}

void printTxtTransitions(_transition *transition, FILE *output)
{
     if (transition != NULL) {
        fprintf(
            output,
            "%s %s %s\n",
            transition->state1->name,
            transition->symbol->content,
            transition->state2->name
        );
        printTxtTransitions(transition->next, output);
    }
}

void printTxtInitialStates(_state *state, FILE *output)
{
    if (state != NULL) {
        if (state->isInitial) {
            fprintf(
                output, "%s\n",
                state->name
            );
        }
        printTxtInitialStates(state->next, output);
    }
}

void printTxtFinalStates(_state *state, FILE *output)
{
    if (state != NULL) {
        if (state->isFinal) {
            fprintf(
                output, "%s\n",
                state->name
            );
        }
        printTxtFinalStates(state->next, output);
    }
}

int countFinalStates(_state *state, int count)
{
    if (state == NULL) {
        return count;
    }

    if (state->isFinal) {
        count++;
    }

    return countFinalStates(state->next, count);
}