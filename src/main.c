#include "def.h"

int main()
{
    int i;
    TCub cub = Init_Cub();
    if (cub == NULL) {
        goto eroare_1;
    }

    if(citire(cub) == NULL) {
        goto eroare_2;
    }

    afis(cub);
    while (1) {
        char c[15];
        scanf("%s", c);
        Rotate(c, cub);
        afis(cub);
    }

    

pas1:
    printf("Pasul 1 : Crucea Alba .................");
    if (CheckPas1(cub) == 0) {
        printf("Unsolved, giving you the alg:\n");
        if (SolvePas1(cub) == 1) {
            printf("Eroare la introducerea cubului sau piesele shiftate\n");
            return 0;
        }
    }
    printf("Solved, next step:\n");

    return 0;

eroare_2:
    //mai trebuie elib listele
    for (i = 0; i < N; i++) {
        free(cub->D[i]);
        free(cub->H[i]);
        free(cub->L[i]);
    }
    free(cub->D);
    free(cub->H);
    free(cub->L);
    free(cub);

eroare_1:
    return 1;
}