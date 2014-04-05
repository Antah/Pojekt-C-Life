#include <stdlib.h>
#include <stdio.h>
#include "data.h"

int load(char *data, gen_t *gen){
	FILE * gen0;
	int i, j;
	gen0 = fopen(data, "r");
	if(gen0 == NULL)
		return -1;

	fscanf(gen0, "%i", &gen->h);
	fscanf(gen0, "%i", &gen->w);
	//printf("h:%i w:%i\n",gen->h, gen->w); //pomocniczy wydruk
	alok(gen);
	for(i=0; i<2+gen->h; i++){
		for(j=0; j<2+gen->w; j++){
			if(i == 0 || i == 1+gen->h || j == 0 || j == 1+gen->w)
				gen->tabA[i][j] = 0;
			else{
				fscanf(gen0, "%i", &gen->tabA[i][j]);
				//printf("%i ", gen->tabA[i][j]); //pomocniczy wydruk
		}
			gen->tabB[i][j] = 0;
		}
		//printf("\n"); //pomocniczy wydruk
	}
	fclose(gen0);
	return 1;
}


void alok(gen_t *gen){
	int i;
	gen->tabA = malloc((2+gen->h) * sizeof * gen->tabA);
	gen->tabB = malloc((2+gen->h) * sizeof * gen->tabB);
	for(i=0; i<2+gen->h; i++){
        gen->tabA[i] = malloc((2+gen->w) * sizeof(int));
        gen->tabB[i] = malloc((2+gen->w) * sizeof(int));
    }
}

