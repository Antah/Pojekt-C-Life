#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

void save(gen_t *gen, char *dir, int x){
	FILE *genX;
	int i, j, s;
	char c[1];
	char plik[20];
	s = sprintf(plik, "%s/gen%i.txt", dir, x);
	if(s < 0){
	
	}
	puts(plik);
	genX = fopen(plik, "a");
        for(i=0; i<gen->w; i++){
		for(j=0; j<gen->h; j++){
			s = sprintf(c, "%i", gen->tabA[i][j]);
			fputs(c, genX);
			fputs(" ", genX);
		}
		fputs("\n", genX);
	}
	fclose(genX);
	printf("save\n");
}
