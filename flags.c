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
        printf("Nie podano nazwy pliku z danymi.\n");
        return -1;
    }
    if(path == NULL){
        printf("Nie podano sciezki docelowej.\n");
        return -1;
    }
    if(gen_amount == NULL){
        printf("Nie podano ilosci generacji do wygenerowania.\n");
        return -1;
    }
    if(gen_to_save == NULL){
        printf("Nie podano ilosci generacji do zapisania.\n");
        return -1;
    }
    if(cell_x == NULL)
        cell_x = 15;
    if(cell_y == NULL)
        cell_y = 15;
    return 1;
}

void flagsHelp(){
    printf("\n\tObsluga Gry w zycie");
    printf("\nAby program mogl dzialac i wyliczac generacje potrzebny jest plik tekstowy z danymi.");
    printf("\nPrzykladowy format pliku z danymi:");
    printf("\n4 4");
    printf("\n0 0 0 0");
    printf("\n0 1 1 0");
    printf("\n0 1 1 0");
    printf("\n0 0 0 0");
    printf("\nOprocz tego przy uruchomieniu programu wymagane sa nastepujace flagi:");
    printf("\n\t-f nazwa\t-\tnazwa pliku txt z danymi o formacie podanym powyzej.");
    printf("\n\t-p sciezka\t-\tsciezka do miejsca, w ktorym program ma zapisywac wyliczone generacje.");
    printf("\n\t-n liczba\t-\tliczba egenracji do wyliczenia.");
    printf("\n\t-s liczba\t-\tliczba generacji do zapisania(nie liczac zerowej i ostatniej, ktore program zawsze zapisuje).");
    printf("\nOpcjonalne flagi to:");
    printf("\n\t-x liczba\t-\tszerokosc pojedynczej komorki w pikselach(domyslnie 15).");
    printf("\n\t-y liczba\t-\twysokosc pojedynczej komorki w pikselach(domyslnie 15).\n");
}
