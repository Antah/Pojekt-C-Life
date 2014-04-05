#ifndef _DATA
        #define _DATA
        #include <stdio.h>

typedef struct{
        int **tabA;
        int **tabB;
        int w, h;
}gen_t;

int gen_amount, gen_to_save, cell_x, cell_y;
char *path, *data;

//load.c
int load(char *plik, gen_t *gen);

void alok(gen_t *gen);

//save.c
int save(gen_t *gen, int gen_number);

//newGen.c
void newGen(gen_t *gen);

//flags.c
int flags(int argc, char **argv);

#endif

