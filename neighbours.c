#include <stdlib.h>
#include "neighbours.h"

int neighbours(int *neighboursTab){
	int i, neighboursAlive = 0;
	for(i = 0; i<8; i++){
         	if(neighboursTab[i] == 1){
         	//printf("%i",i);
			neighboursAlive++;}
    	}
        //printf("%i", neighboursAlive);
    	return neighboursAlive;
}

