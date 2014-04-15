#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "data.h"

#define MAX_PATH_LENGTH 128

int save(gen_t *gen, int gen_number){
	FILE *gen_x;
	int i, j, x=0, y=0;
	char *file_name;
	static unsigned char color[3];
	if((file_name = (char*) malloc (MAX_PATH_LENGTH)) == NULL)
		return -1;
	if((sprintf(file_name, "%s/%s_gen", path, data)) < 0)
		return -1;
	for(i=10; i<=gen_amount;i*=10){
        if(gen_number<i)
            if((sprintf(file_name, "%s0", file_name)) < 0)
		return -1;
	}
	if((sprintf(file_name, "%s%i.ppm",file_name, gen_number)) < 0)
		return -1;
    mkdir(path, 0777);
	if((gen_x = fopen(file_name, "wb")) == NULL)
        return -1;
    fprintf( gen_x, "P6\n%i %i\n255\n", (cell_x+1)*(gen->w)+1, (cell_y+1)*(gen->h)+1 );
    for(i=1; i<=(cell_y+1)*(gen->h)+1; i++){
        if(i%(cell_y+1) == 1)
            x++;
        for(j=1; j<=(cell_x+1)*(gen->w)+1; j++){
            if(j%(cell_x+1) == 1)
                y++;
            if(i%(cell_y+1) == 1 || j%(cell_x+1) == 1){
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
            fwrite(color, 1, 3, gen_x);
		}
		y=0;
	}
	fclose(gen_x);
	return 1;
}
