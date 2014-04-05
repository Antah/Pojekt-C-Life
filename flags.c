#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "data.h"

int flags(int argc, char **argv){
    int opt;
    while((opt = getopt(argc, argv, "f:p:n:s:x:y:")) != -1){
        switch(opt){
            case 'f':
                data = optarg;
                break;
            case 'p':
                path = optarg;
                break;
            case 'n':
                genAmount = atoi(optarg);
                break;
            case 's':
                genToSave = atoi(optarg);
                break;
            case 'x':
                cellX = atoi(optarg);
                break;
            case 'y':
                cellY = atoi(optarg);
                break;
        }
    }
    if(data == NULL){
        printf("Nie podano nazwy pliku z danymi");
        return -1;
    }
    if(path == NULL){
        printf("Nie podano sciezki docelowej");
        return -1;
    }
    if(genAmount == NULL){
        printf("Nie podano ilosci generacji do wygenerowania");
        return -1;
    }
    if(genToSave == NULL){
        printf("Nie podano ilosci generacji do zapisania");
        return -1;
    }
    if(cellX == NULL)
        cellX = 15;
    if(cellY == NULL)
        cellY = 15;
    return 1;
}
