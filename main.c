#include <stdlib.h>
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
		return 1;
	}
    
    	for(i = 0; i < atoi(argv[3]); i++){
          	newGen(&gen);
          	if(i < atoi(argv[4]) || i == atoi(argv[3]) - 1)
               		save(&gen, argv[2], i+1);
    	}
    	printf("Program zakonczyl dzialanie powodzeniem.\n");
    	return 0;
}
