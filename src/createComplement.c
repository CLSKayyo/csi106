#include "header.h"

void createComplement()
{
    for (int i=0; i<afd.statesCount; i++) {
        afd.states[i].isFinal = (afd.states[i].isFinal+1)%2;
    }
}