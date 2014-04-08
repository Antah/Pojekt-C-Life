#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(int argc, char **argv){
    int i;
    gen_t gen;

    if(flags(argc, argv) < 0){
        flagsHelp();
        return EXIT_FAILURE;
    }
    if(load(data, &gen) < 0){
        printf("Nie moge otworzyc pliku z danymi\n");
        return EXIT_FAILURE;
	}
    if((save(&gen, 0)) < 0){
                printf("Nie udalo sie utworzyc pliku\n");
                return EXIT_FAILURE;
            }
    for(i = 0; i < gen_amount; i++){
        newGen(&gen);
        if(i < gen_to_save || i == gen_amount - 1){
            if((save(&gen, i+1)) < 0){
                printf("Nie udalo sie utworzyc pliku\n");
                return EXIT_FAILURE;
            }
        }
    }
    printf("Program zakonczyl dzialanie powodzeniem.\n");
    return EXIT_SUCCESS;
}
