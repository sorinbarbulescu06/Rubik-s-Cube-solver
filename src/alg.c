#include "def.h"

int CheckPas1(TCub cub)
{
    if(cub->L[1]->next_L->c != 'W' || cub->L[1]->prev_L->c !=
       cub->L[1]->prev_L->prev_L->c)//up
        return 0;
    if(cub->H[1]->next_H->c != 'W' || cub->H[1]->prev_H->c !=
       cub->H[1]->prev_H->prev_H->c)//left
        return 0;
    if(cub->L[1]->next_L->next_L->next_L->c != 'W' ||
       cub->L[1]->next_L->next_L->next_L->next_L->c !=
       cub->L[1]->next_L->next_L->next_L->next_L->next_L->c)//down
        return 0;
    if(cub->H[1]->next_H->next_H->next_H->c != 'W' ||
       cub->H[1]->next_H->next_H->next_H->next_H->c !=
       cub->H[1]->next_H->next_H->next_H->next_H->next_H->c)//right
        return 0;
    return 1;
}

int SolvePas1(TCub cub)
{    
    
    return 0;
}
