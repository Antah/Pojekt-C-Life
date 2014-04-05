#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(int argc, char **argv){
    int i;
    gen_t gen;

    if(flags(argc, argv) < 0)
        return EXIT_FAILURE;

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
