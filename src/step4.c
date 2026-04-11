#include "def.h"

int CheckPas4(TCub cub)
{
    char c = cub->U_M->c;
    if(c == cub->U_M->next_L->c && c == cub->U_M->prev_L->c 
       && c == cub->U_M->next_D->c && c == cub->U_M->prev_D->c)
        return 1;
    return 0;
}

void SolvePas4(TCub cub)
{
    int i,j;
    for (i = 0; i < Nr_Fete; ++i) {
        //verificare L
        if(cub->U_M->prev_L->c == cub->U_M->c &&
           cub->U_M->next_D->c == cub->U_M->c) {
            if (i == 3) {
                printf("U\' ");
            } else {
                for (j = 0; j < i; ++j) {
                    printf("U ");
                }
            }
            Algo(cub);
            printf("\n");
            afis(cub);
            printf("\n");
            return ;
        }

        //verificare Linie
        if(cub->U_M->next_D->c == cub->U_M->c &&
           cub->U_M->prev_D->c == cub->U_M->c) {
            if (i == 3) {
                printf("U\' ");
            } else {
                for (j = 0; j < i; ++j) {
                    printf("U ");
                }
            }
            Algo(cub);
            printf("\n");
            afis(cub);
            printf("\n");
            Algo(cub);
            printf("\n");
            afis(cub);
            printf("\n");
            return ;
        }
        Rotate("U", cub, 0);
    }
    Algo(cub);
    Rotate("U", cub, 1);
    printf("\n");
    afis(cub);
    printf("\n");
    Algo(cub);
    printf("\n");
    afis(cub);
    printf("\n");
    Algo(cub);
    printf("\n");
    afis(cub);
    printf("\n");
}

void Algo(TCub cub)
{
    Rotate("F", cub, 1);
    Rotate("U", cub, 1);
    Rotate("R", cub, 1);
    Rotate("U\'", cub, 1);
    Rotate("R\'", cub, 1);
    Rotate("F\'", cub, 1);
}
