#include <stdio.h>
#include <stdlib.h>
#include "rules.h"

int rules(int neighboursAlive, int cellState){
   	if(cellState == 0 && neighboursAlive == 3){
        return 1;
	}
	if(cellState == 1 &&(neighboursAlive == 2 || neighboursAlive == 3)){
		return 1;
	}
    return 0;
}
