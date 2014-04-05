#include <stdlib.h>
#include <stdio.h>
#include "data.h"
int main(int argc, char **argv){
    	if(argc != 5){
        	printf("Nieprawidlowa ilosc argumentow... \n");
            	return 1;
    	}
    	int i;
    	gen_t gen;

    	if(load(argv[1], &gen) < 0){
		printf("Nie moge otworzyc pliku z danymi");
            return EXIT_FAILURE;
	}

    	for(i = 0; i < atoi(argv[3]); i++){
          	newGen(&gen);
          	if(i < atoi(argv[4]) || i == atoi(argv[3]) - 1){
               		if((save(&gen, argv[2], i+1)) < 0){
                        printf("Nie udalo sie utworzyc pliku");
                        return EXIT_FAILURE;
               		};
          	}
    	}
    	printf("Program zakonczyl dzialanie powodzeniem.\n");
    	return 0;
}
