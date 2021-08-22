#include "src/header.h"

int main(int argc, char *argv[])
{
    if (argc > 3) {
        if (strcmp(argv[1], "--dot") == 0) {
            populateAfdFromFile(argv[2]);
            printf("\nVisualização em .Dot\n\n");
            renderDot(argv[4]);
            return 0;
        }

        if (strcmp(argv[1], "--complemento") == 0) {
            populateAfdFromFile(argv[2]);
            printf("\nComplemento\n\n");
            createComplement(afd.state);
            renderTxt(argv[4]);
            return 0;
        }

        if (strcmp(argv[1], "--reconhecer") == 0) {
            populateAfdFromFile(argv[2]);
            printf("\nReconhecimento de Palavra\n\n");
            recognizeWords(argv[3], argv[5]);
            return 0;
        }

        if (strcmp(argv[1], "--minimizacao") == 0) {
            populateAfdFromFile(argv[2]);
            printf("\nMinimização\n\n");
            minifyAfd();
            renderTxt(argv[4]);
            return 0;
        }

        printf("Comando %s não reconhecido.\n", argv[1]);
        return 1;
    }
    printf("Quantidade de argumentos inválida.\n");
    return 1;
}

#include "src/footer.c"
