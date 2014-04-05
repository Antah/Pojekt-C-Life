#include <stdlib.h>
#include "rules.h"

int rules(int neighboursAlive, int cellState){
   	if(cellState == 0 && neighboursAlive == 3){
      		return 1;
	}
	else if(cellState == 1 &&(neighboursAlive == 2 || neighboursAlive == 3)){
		return 1;
	}
	else{
    		return 0;
	}
}

