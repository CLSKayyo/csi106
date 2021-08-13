#include "src/header.h"

int main(int argc, char *argv[])
{
    char *inputFile = NULL;
    char *outputFile = NULL;
    int operation = 0;

    static struct option long_options[] = {
        {"dot", required_argument, 0, 'd'},
        {"complemento", required_argument, 0, 'c'},
        {"output", required_argument, 0, 'o'},
        {0, 0, 0, 0}
    };

    int long_index = 0;
    int opt = 0;

    while(
        (opt = getopt_long(
            argc,
            argv,
            ":do:co:",
            long_options,
            &long_index
        )) != -1
    ) {
        switch (opt) {
            case 'd':
                inputFile = optarg;
                operation = 1;
                break;
            case 'c':
                inputFile = optarg;
                operation = 2;
                break;
            case 'o':
                outputFile = optarg;
                break;
        }
    }

    switch (operation) {
        case 1:
            printf("Visualização\n");
            populateAFDFromFile(inputFile);
            renderDot(outputFile);
            break;
        
        case 2:
            printf("Complemento\n");
            populateAFDFromFile(inputFile);
            createComplement();
            renderTxt(outputFile);
            break;
        
        default:
            populateAFDFromFile("exemplo_afd.txt");
            renderDot("afd-result.dot");
            printf("Comando não conhecido. \n");
            return 1;
    }

    return 0;

    // if (strcmp("--dot", argv[1]) == 0) {
    //     if (argc>4 && strcmp(argv[3], "--output") == 0) {
    //         populateAFDFromFile(argv[2]);
    //         renderDot(argv[4]);
    //         return 0;
    //     }
    //     printf("Poucos argumentos para o comando \"--dot\". Espera-se mais 3 argumentos. \n");
    //     return 1;
    // }

    // if (strcmp("--complemento", argv[1]) == 0) {
    //     if (argc>4 && strcmp(argv[3], "--output") == 0) {
    //         populateAFDFromFile(argv[2]);
    //         return 0;
    //     }
    //     printf("Poucos argumentos para o comando \"--dot\". Espera-se mais 3 argumentos. \n");
    //     return 1;
    // }

    printf("Comando não conhecido. \n");
    return 0;
}

#include "src/footer.c"
