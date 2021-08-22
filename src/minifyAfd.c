#include "header.h"

void minifyAfd()
{
    _state *finalStates = NULL;
    finalStates = findFinalStates(afd.state, finalStates);

    _state *notFinalStates = NULL;
    notFinalStates = findNotFinalStates(afd.state, notFinalStates);

    int resultStateCount = 0;
    _state *resultState = NULL;
    _state *notUsedStates = NULL;
    _state *usedStates = NULL;

    for (
        _state *stateX = finalStates;
        stateX != NULL;
        stateX = stateX->next
    ) {
        for (
            _state *stateY = finalStates;
            stateY != NULL;
            stateY = stateY->next
        ) {
            int isEqual = 1;
            for (
                _symbol *symbol = afd.alphabet;
                symbol != NULL;
                symbol = symbol->next
            ) {

                if (isSameState(stateX, stateY)) {
                    isEqual = 0;
                    break;
                }

                _transition *transitionX = findTransitionByStateAndSymbol(afd.transition, stateX, symbol->content[0]);
                _transition *transitionY = findTransitionByStateAndSymbol(afd.transition, stateY, symbol->content[0]);

                if (transitionX == NULL || transitionY == NULL) {
                    break;
                }

                if (
                    transitionX->state2 == transitionY->state2 ||
                    (
                        transitionX->state1 == transitionY->state2 &&
                        transitionX->state2 == transitionY->state1
                    ) ||
                    (
                        transitionX->state1 == transitionY->state1 &&
                        transitionX->state2 == transitionY->state2
                    )
                ) {
                    isEqual = 1;
                } else {
                    isEqual = 0;
                    break;
                }
            }

            if (isEqual) {
                if (
                    (
                        checkIfStateExists(resultState, stateX) == NULL &&
                        checkIfStateExists(resultState, stateY) == NULL
                    ) &&
                    (
                        checkIfStateExists(usedStates, stateX) == NULL &&
                        checkIfStateExists(usedStates, stateY) == NULL
                    )
                ) {
                    resultState = insertNewState(resultState, stateX->name);
                    resultState->isFinal = stateX->isFinal;
                    resultState->isInitial = stateX->isInitial || stateY->isInitial;
                    resultStateCount++;

                    notUsedStates = insertNewState(notUsedStates, stateY->name);
                    notUsedStates->isFinal = stateY->isFinal;
                    notUsedStates->isInitial = stateY->isInitial;

                    usedStates = insertNewState(usedStates, stateX->name);
                    usedStates->isFinal = stateX->isFinal;
                    usedStates->isInitial = stateX->isInitial;
                    if (strcmp(stateX->name, stateY->name) != 0) {
                        usedStates = insertNewState(usedStates, stateY->name);
                        usedStates->isFinal = stateY->isFinal;
                        usedStates->isInitial = stateY->isInitial;
                    }

                    for (
                        _transition *transition = afd.transition;
                        transition != NULL;
                        transition = transition->next
                    ) {
                        if (isSameState(transition->state2, stateY)) {
                            transition->state2 = stateX;
                        }
                    }
                }
            }
        }
    }

    deleteTransitionsWithNotUsedStates(notUsedStates);

    for (
        _state *stateX = notFinalStates;
        stateX != NULL;
        stateX = stateX->next
    ) {
        for (
            _state *stateY = notFinalStates;
            stateY != NULL;
            stateY = stateY->next
        ) {
            int isEqual = 1;
            for (
                _symbol *symbol = afd.alphabet;
                symbol != NULL;
                symbol = symbol->next
            ) {

                if (isSameState(stateX, stateY)) {
                    isEqual = 0;
                    break;
                }

                _transition *transitionX = findTransitionByStateAndSymbol(afd.transition, stateX, symbol->content[0]);
                _transition *transitionY = findTransitionByStateAndSymbol(afd.transition, stateY, symbol->content[0]);

                if (transitionX == NULL || transitionY == NULL) {
                    break;
                }

                if (
                    transitionX->state2 == transitionY->state2 ||
                    (
                        transitionX->state1 == transitionY->state2 &&
                        transitionX->state2 == transitionY->state1
                    ) ||
                    (
                        transitionX->state1 == transitionY->state1 &&
                        transitionX->state2 == transitionY->state2
                    )
                ) {
                    isEqual = 1;
                } else {
                    isEqual = 0;
                    break;
                }
            }

            if (isEqual) {
                if (
                    (
                        checkIfStateExists(resultState, stateX) == NULL &&
                        checkIfStateExists(resultState, stateY) == NULL
                    ) &&
                    (
                        checkIfStateExists(usedStates, stateX) == NULL &&
                        checkIfStateExists(usedStates, stateY) == NULL
                    )
                ) {
                    resultState = insertNewState(resultState, stateX->name);
                    resultState->isFinal = 0;
                    resultState->isInitial = stateX->isInitial || stateY->isInitial;
                    resultStateCount++;

                    notUsedStates = insertNewState(notUsedStates, stateY->name);
                    notUsedStates->isFinal = stateY->isFinal;
                    notUsedStates->isInitial = stateY->isInitial;

                    usedStates = insertNewState(usedStates, stateX->name);
                    usedStates->isFinal = stateX->isFinal;
                    usedStates->isInitial = stateX->isInitial;
                    if (strcmp(stateX->name, stateY->name) != 0) {
                        usedStates = insertNewState(usedStates, stateY->name);
                        usedStates->isFinal = stateY->isFinal;
                        usedStates->isInitial = stateY->isInitial;
                    } 

                    for (
                        _transition *transition = afd.transition;
                        transition != NULL;
                        transition = transition->next
                    ) {
                        if (isSameState(transition->state2, stateY)) {
                            transition->state2 = stateX;
                        }
                    }
                }
            }
        }
    }

    deleteTransitionsWithNotUsedStates(notUsedStates);

    afd.state = resultState;
    afd.statesCount = resultStateCount;
}