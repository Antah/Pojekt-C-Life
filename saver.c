#include <stdio.h>
#include <stdlib.h>
#include "data.h"

#define MAX_PATH_LENGTH 128
#define CELL_SIZE 15

int save(gen_t *gen, char *path, int gen_number){
	FILE *genX;
	int i, j, x=0, y=0;
	char file_name[MAX_PATH_LENGTH];
	static unsigned char color[3];
	sprintf(file_name, "%s/gen%i.ppm", path, gen_number);

	puts(file_name);

	if((genX = fopen(file_name, "wb")) == NULL)
        return -1;
    printf("utworzylem");
    (void)fprintf( genX, "P6\n%i %i\n255\n", (CELL_SIZE+1)*(gen->w)+1, (CELL_SIZE+1)*(gen->h)+1 );
    printf("rozmiary");

    for(i=1; i<=(CELL_SIZE+1)*(gen->h)+1; i++){
        if(i%(CELL_SIZE+1) == 1)
            x++;
        for(j=1; j<=(CELL_SIZE+1)*(gen->w)+1; j++){
            if(j%(CELL_SIZE+1) == 1)
                y++;
            if(i%(CELL_SIZE+1) == 1 || j%(CELL_SIZE+1) == 1){
                color[0] = 175;
                color[1] = 175;
                color[2] = 175;
            } else if(gen->tabA[x][y] == 1){
                color[0] = 0;
                color[1] = 0;
                color[2] = 0;
            } else if(gen->tabA[x][y] == 0){
                color[0] = 255;
                color[1] = 255;
                color[2] = 255;
            }
            fwrite(color, 1, 3, genX);
		}
		y=0;
	}
	fclose(genX);
	printf("save\n");
	return 1;
}
