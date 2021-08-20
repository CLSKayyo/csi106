#include "src/header.h"

int main(int argc, char *argv[])
{
    if (argc > 3) {
        if (strcmp(argv[1], "--dot") == 0) {
            populateAFDFromFile(argv[2]);
            renderDot(argv[4]);
            return 0;
        }

        if (strcmp(argv[1], "--complemento") == 0) {
            populateAFDFromFile(argv[2]);
            createComplement(afd.state);
            renderTxt(argv[4]);
            return 0;
        }

        if (strcmp(argv[1], "--reconhecer") == 0) {
            populateAFDFromFile(argv[2]);
            recognizeWords(argv[3], argv[5]);
            return 0;
        }

        printf("Comando %s não reconhecido.\n", argv[1]);
        return 0;
    }
    printf("Quantidade de argumentos inválida.\n");
    return 1;
}

#include "src/footer.c"
