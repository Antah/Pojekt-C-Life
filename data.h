#ifndef _DATA
        #define _DATA
        #include <stdio.h>
typedef struct{
        int **tabA;
        int **tabB;
        int w, h;
}gen_t;

//load.c
int load(char *plik, gen_t *gen);

void alok(gen_t *gen);

//save.c
void save(gen_t *gen, char *dir, int x);

//newGen.c
void newGen(gen_t *gen);

#endif

