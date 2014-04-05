#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "data.h"

int main(int argc, char **argv){
    int opt, i;
    gen_t gen;

    while((opt = getopt(argc, argv, "f:p:n:s:")) != -1){
        switch(opt){
            case 'f':
                data = optarg;
                break;
            case 'p':
                path = optarg;
                break;
            case 'n':
                genAmount = atoi(optarg);
                break;
            case 's':
                genToSave = atoi(optarg);
                break;
        }
    }
    if(data == NULL){
        printf("Nie podano nazwy pliku z danymi");
        return EXIT_FAILURE;
    }
    if(path == NULL){
        printf("Nie podano sciezki docelowej");
        return EXIT_FAILURE;
    }
    if(genAmount == NULL){
        printf("Nie podano ilosci generacji do wygenerowania");
        return EXIT_FAILURE;
    }
    if(genToSave == NULL){
        printf("Nie podano ilosci generacji do zapisania");
        return EXIT_FAILURE;
    }

    if(load(data, &gen) < 0){
        printf("Nie moge otworzyc pliku z danymi");
            return EXIT_FAILURE;
	}

    for(i = 0; i < genAmount; i++){
        newGen(&gen);
        if(i < genToSave || i == genAmount - 1){
            if((save(&gen, path, i+1)) < 0){
                printf("Nie udalo sie utworzyc pliku");
                return EXIT_FAILURE;
            }
        }
    }
    printf("Program zakonczyl dzialanie powodzeniem.\n");
    return EXIT_SUCCESS;
}
