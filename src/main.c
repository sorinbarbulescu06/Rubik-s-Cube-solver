#include "def.h"

int main()
{
    int i;
    TCub cub = Init_Cub();
    if (cub == NULL) {
        goto eroare_1;
    }

    printf("Citeste cubul cu fata alba in sus\n");

    if(citire(cub) == NULL) {
        goto eroare_2;
    }

    Rotate("Cube_Down", cub, 0);
    afis(cub);
    
    Solve(cub);
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