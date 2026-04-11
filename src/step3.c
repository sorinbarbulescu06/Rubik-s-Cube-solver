#include "def.h"

int CheckPas3(TCub cub)
{
    if(cub->F_M->c != cub->F_M->next_H->c || cub->F_M->c != cub->F_M->prev_H->c)
        return 0;
    if(cub->L_M->c != cub->L_M->next_H->c || cub->L_M->c != cub->L_M->prev_H->c)
        return 0;
    if(cub->B_M->c != cub->B_M->next_H->c || cub->B_M->c != cub->B_M->prev_H->c)
        return 0;
    if(cub->R_M->c != cub->R_M->next_H->c || cub->R_M->c != cub->R_M->prev_H->c)
        return 0;
    return 1;
}

void SolvePas3(TCub cub)
{
    int i, j, k;
    for (i = 0; i < Nr_Fete; ++i) {
        int puse = Give_Puse(cub);
        printf("Rezolvam fata: %c\n\n", cub->F_M->c);
        for (j = 0; j < 2 - puse; ++j) {
            //cautam sus direct
            k = 0;
            for(k = 0; k < Nr_Fete && !(cub->F_M->prev_L->c == cub->F_M->c && cub->U_M->next_L->c != cub->U_M->c); ++k) 
                Rotate("U", cub, 0);
            if (k != Nr_Fete) { //caz in care am gasit
                for (int aux = 0; aux < k; ++aux)
                    printf("U ");
                if (cub->U_M->next_L->c == cub->L_M->c) {
                    Put_Left(cub);
                } else {
                    Put_Right(cub);
                }
                afis(cub);
                
                continue;
            }
            //cautam sus indirect
            k = 0;
            for(k = 0; k < Nr_Fete && !(cub->F_M->prev_L->c != cub->U_M->c && cub->U_M->next_L->c == cub->F_M->c); ++k) 
                Rotate("U", cub, 0);
            if (k != Nr_Fete) {
                for (int aux = 0; aux < k; ++aux)
                    printf("U ");
                if (cub->F_M->prev_L->c == cub->L_M->c) {
                    Rotate("U", cub, 1);
                    Rotate("Cube_Left", cub, 1);
                    printf("\n");
                    Put_Right(cub);
                    Rotate("Cube_Right", cub, 1);
                    printf("\n");
                } else {
                    Rotate("U\'", cub, 1);
                    Rotate("Cube_Right", cub, 1);
                    printf("\n");
                    Put_Left(cub);
                    Rotate("Cube_Left", cub, 1);
                    printf("\n");
                }
                afis(cub);
                continue;
            }

            //cautam printre celelalte
            int gasit = Others(cub);
            if(gasit != 5)
                Pune(cub, gasit);
        }


        Rotate("Cube_Right", cub, 1);
        printf("\n");
    }
}

void Put_Left(TCub cub)
{
    Rotate("U\'", cub, 1);
    Rotate("L\'", cub, 1);
    Rotate("U", cub, 1);
    Rotate("L", cub, 1);
    Rotate("Cube_Left", cub, 1);
    printf("\n");
    Rotate("U", cub, 1);
    Rotate("R", cub, 1);
    Rotate("U\'", cub, 1);
    Rotate("R\'", cub, 1);
    Rotate("Cube_Right", cub, 1);
    printf("\n");
}

void Put_Right(TCub cub)
{
    Rotate("U", cub, 1);
    Rotate("R", cub, 1);
    Rotate("U\'", cub, 1);
    Rotate("R\'", cub, 1);
    Rotate("Cube_Right", cub, 1);
    printf("\n");
    Rotate("U\'", cub, 1);
    Rotate("L\'", cub, 1);
    Rotate("U", cub, 1);
    Rotate("L", cub, 1);
    Rotate("Cube_Left", cub, 1);
    printf("\n");
}

int Give_Puse(TCub cub)
{
    int cnt = 0;
    if(cub->F_M->c == cub->F_M->prev_H->c && cub->L_M->c == cub->L_M->next_H->c)
        cnt++;
    if(cub->F_M->c == cub->F_M->next_H->c && cub->R_M->c == cub->R_M->prev_H->c)
        cnt++;
    return cnt;
}

int Others(TCub cub)
{
    char mid = cub->F_M->c;
    int i, j;
    if(cub->F_M->c ==  cub->F_M->prev_H->c && cub->R_M->c == cub->L_M->next_H->c)
        return 0;
    if(cub->F_M->c ==  cub->F_M->next_H->c && cub->L_M->c == cub->R_M->prev_H->c)
        return 0;
    Rotate("Cube_Right", cub, 0);
    for (i = 1; i < Nr_Fete; ++i) {
        if((cub->F_M->prev_H->c == mid && cub->L_M->next_H->c != cub->U_M->c) || (cub->F_M->next_H->c == mid && cub->R_M->prev_H->c !=cub->U_M->c)){
            int sgn = 1;
            if(cub->F_M->prev_H->c == mid && cub->L_M->next_H->c != cub->U_M->c)
                sgn = -1;
            for (j = 0; j < i; ++j) {
                Rotate("Cube_Left", cub, 0);
            }
            return sgn * i;
        }
        Rotate("Cube_Right", cub, 0);
    }
    return 5;
}

void Pune(TCub cub, int gasit)
{
    int sgn = 1;
    if(gasit < 0){
        sgn = -1;
        gasit = gasit * -1;
    }
    int i;
    if (gasit == 0) {
        if(cub->F_M->c == cub->F_M->prev_H->c && cub->L_M->next_H->c == cub->R_M->c) {
            Rotate("Cube_Left", cub, 1);
            printf("\n");
            Put_Right(cub);
            Rotate("U", cub, 1);
            Rotate("Cube_Right", cub, 1);
            printf("\n");
        } else {
            Rotate("Cube_Right", cub, 1);
            printf("\n");
            Put_Left(cub);
            Rotate("U\'", cub, 1);
            Rotate("Cube_Left", cub, 1);
            printf("\n");
        }
    } else {
        if (sgn == -1) {
            for (i = 0; i < gasit - 1; ++i) 
                Rotate("Cube_Right", cub, 1);
            printf ("\n");
            Put_Right(cub);
            if (gasit == 1) {
                Rotate("U\'", cub, 1);
                Rotate("U\'", cub, 1);
            }
            if (gasit == 2) {
                Rotate("U\'", cub, 1);
            }
            for (i = 0; i < gasit - 1; ++i) 
                Rotate("Cube_Left", cub, 1);
            printf("\n");
        } else {
            for (i = 0; i < gasit + 1; ++i) 
                Rotate("Cube_Right", cub, 1);
            printf ("\n");
            Put_Left(cub);
            if (gasit == 2) { 
                Rotate("U", cub, 1);
            }
            if (gasit == 3) { 
                Rotate("U", cub, 1);
                Rotate("U", cub, 1);
            }
            for (i = 0; i < gasit + 1; ++i) 
                Rotate("Cube_Left", cub, 1);
            printf("\n");
        }
    }
    if (cub->U_M->next_L->c == cub->L_M->c) {
        Put_Left(cub);
    } else {
        Put_Right(cub);
    }
    afis(cub);
    printf("\n");
}
