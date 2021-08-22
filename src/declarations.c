// symbolFunctions.c

_symbol* findSymbol(char *content, _symbol *symbol);
_symbol* insertNewSymbol(_symbol *symbol, char *content);
_state* recognizeSymbol(_state *state, char symbol);
void printSymbols(_symbol *symbol);

// stateFunctions.c

_state* findStateByName(char *name, _state *state);
_state* findInitialState(_state *state);
_state* findFinalStates(_state *stateSearch, _state *stateResult);
_state* findNotFinalStates(_state *stateSearch, _state *stateResult);
_state* insertNewState(_state *state, char *name);
void printStatesName(_state *state);
int countFinalStates(_state *state, int count);
_state* checkIfStateExists(_state *searchState, _state *state);
int isSameState(_state *state1, _state *state2);

// transitionFunctions.c

void insertTransitionLast(_transition *transition, _transition *toInsert);
_transition* checkAndDeleteTransitionByState(_transition *transition, _transition *resultTransition, _state *state);
void deleteTransitionsWithStates(_transition *transition, _state *state);
void deleteTransitionsWithNotUsedStates(_state *state);
_transition* insertNewTransition(_transition *transition, char *state1, char *state2, char *symbol);
_transition* findTransitionByStateAndSymbol(_transition *transition, _state *state, char symbol);
_transition* findTransitionByLastStateAndSymbol(_transition *transition, _state *state, char symbol);
void printTransitions(_transition *transition);

// populateAfdFromFile.c

void populateAfdFromFile(char *inputFile);

// createComplement.c

void createComplement(_state *state);

// recognizeWords.c

int tryRecognizeWord(char *linha);
void recognizeWords(char *inputFile, char *outputFile);

// minifyAfd.c

void minifyAfd();

// dotFunctions.c

void printDotFinalStates(_state *state, FILE *output);
void printDotTransitions(_transition *transition, FILE *output);

// txtFunctions.c

void printTxtStateNames(_state *state, FILE *output);
void printTxtSymbols(_symbol *symbol, FILE *output);
void printTxtTransitions(_transition *transition, FILE *output);
void printTxtInitialStates(_state *state, FILE *output);
void printTxtFinalStates(_state *state, FILE *output);

// renderDot.c

void renderDot(char *outputFile);

// renderTxt.c

void renderTxt(char *outputFile);