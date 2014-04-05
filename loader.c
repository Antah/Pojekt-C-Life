#include <stdlib.h>
#include <stdio.h>
#include "data.h"

int load(char *plik, gen_t *gen){
	FILE * gen0;
	int i, j;
	gen0 = fopen(plik, "r");
	if(gen0 == NULL){
		printf("Nie moge otworzyc pliku\n");
		return -1;
	}
	fscanf(gen0, "%i", &gen->w);
	fscanf(gen0, "%i", &gen->h);
	printf("w:%i h:%i\n",gen->w, gen->h);
	alok(gen);
	for(i=0; i<2+gen->h; i++){
		for(j=0; j<2+gen->w; j++){
			if(i == 0 || i == 1+gen->h || j == 0 || j == 1+gen->w)
				gen->tabA[i][j] = 0;
			else{
				fscanf(gen0, "%i", &gen->tabA[i][j]);	
				printf("%i ", gen->tabA[i][j]);
			}
			gen->tabB[i][j] = 0;
		}
		printf("\n");
	}
	fclose(gen0);
	printf("loaded\n");
	return 1;
}


void alok(gen_t *gen){
	int i;
	gen->tabA = malloc((2+gen->w) * sizeof * gen->tabA);
	gen->tabB = malloc((2+gen->w) * sizeof * gen->tabB);
	for(i=0; i<2+gen->w; i++){
                gen->tabA[i] = malloc((2+gen->h) * sizeof(int));
                gen->tabB[i] = malloc((2+gen->h) * sizeof(int));
        }
}

