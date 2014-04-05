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
                gen_amount = atoi(optarg);
                break;
            case 's':
                gen_to_save = atoi(optarg);
                break;
            case 'x':
                cell_x = atoi(optarg);
                break;
            case 'y':
                cell_y = atoi(optarg);
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
    if(gen_amount == NULL){
        printf("Nie podano ilosci generacji do wygenerowania");
        return -1;
    }
    if(gen_to_save == NULL){
        printf("Nie podano ilosci generacji do zapisania");
        return -1;
    }
    if(cell_x == NULL)
        cell_x = 15;
    if(cell_y == NULL)
        cell_y = 15;
    return 1;
}
