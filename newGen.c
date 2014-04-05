#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "neighbours.h"
#include "rules.h"
void newGen(gen_t *gen){
     int i, j, neighboursAlive;
     int neighboursTab[8];
     for(i=1; i < 1+gen->h; i++){
        for(j=1; j < 1+gen->w; j++){
            neighboursTab[0] = gen->tabA[i-1][j-1];
            neighboursTab[1] = gen->tabA[i-1][j];
            neighboursTab[2] = gen->tabA[i-1][j+1];
            neighboursTab[3] = gen->tabA[i][j-1];
            neighboursTab[4] = gen->tabA[i][j+1];
            neighboursTab[5] = gen->tabA[i+1][j-1];
            neighboursTab[6] = gen->tabA[i+1][j];
            neighboursTab[7] = gen->tabA[i+1][j+1];

            neighboursAlive = neighbours(neighboursTab);
            gen->tabB[i][j] = rules(neighboursAlive, gen->tabA[i][j]);
			//printf("%i ", gen->tabB[i][j]);//pomocniczy wydruk
        }
        //printf("\n");//pomocniczy wydruk
    }
	for(i=1; i<1+gen->h;i++){
		for(j=1; j<1+gen->w; j++){
			gen->tabA[i][j] = gen->tabB[i][j];
		}
	}
}
