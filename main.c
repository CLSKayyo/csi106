#include "header.h"

int main(int argc, char **argv)
{
    if (argc>1) {
        if (strcmp(argv[1], "--dot") == 0) {
            if (argc>4 && strcmp(argv[1], "--output")) {
                generateViewFile(argv[2], argv[4]);
                return 0;
            }
            printf("Poucos argumentos para o comando \"--dot\". Espera-se mais 3 argumentos. \n");
            return 1;
        }

        printf("Comando \"%s\" não reconhecido.\n", argv[1]);
        return 1;
    }

    printf("Favor inserir um comando.\n");
    return 1;
}

#include "footer.c"