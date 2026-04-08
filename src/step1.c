#include "def.h"

int CheckPas1(TCub cub)
{
    int i, j;
    for (i = 0; i < Nr_Fete; ++i){
        if (cub->F_M->c != cub->F_M->prev_L->c || cub->U_M->c != cub->U_M->next_L->c) {
            for (j = 0; j < i; ++j){
                Rotate("Cube_Left", cub, 0);
            }
            return 0;
        }
        Rotate("Cube_Right", cub, 0);
    }
    return 1;
}

void SolvePas1(TCub cub)
{    
    int i;
    for (i = 0; i < Nr_Fete; ++i) {
        int gasit;


        printf("\nRezolvam pt. fata: %c\n\n", cub->F_M->c);
        //verificam daca e pe fata de sus
        gasit = Search_Up(cub, cub->F_M->c);
        if (gasit != 0) {
            Alg_Up(cub, gasit);
            printf("\n");
            afis(cub);
            Rotate("Cube_Right", cub, 1);
            continue;
        }
        
        //verificam daca e pe randul 1
        gasit = Search_FR(cub, cub->F_M->c);
        if (gasit != 5) {
            Alg_FR(cub, gasit);
            printf("\n");
            afis(cub);
            Rotate("Cube_Right", cub, 1);
            continue;
        }

        //verificam daca e pe randul 2
        gasit = Search_SR(cub, cub->F_M->c);
        if (gasit != 5) {
            Alg_SR(cub, gasit);
            printf("\n");
            afis(cub);
            Rotate("Cube_Right", cub, 1);
            continue;
        }

        //verificam daca e pe randul 3
        gasit = Search_TR(cub, cub->F_M->c);
        if (gasit != 5) {
            Alg_TR(cub, gasit);
            printf("\n");
            afis(cub);
            Rotate("Cube_Right", cub, 1);
            continue;
        }
        //verificam daca e pe fata de jos
        gasit = Search_Down(cub, cub->F_M->c);
        if (gasit != 5)  {
            Alg_Down(cub, gasit);
            printf("\n");
            afis(cub);
            Rotate("Cube_Right", cub, 1);
            continue;   
        }
        printf("Nimic de rezolvat pe aceasta fata\n");
        afis(cub);
        Rotate("Cube_Right", cub, 1);
        printf("\n");
    }
    printf("\n");
}

int Search_Up(TCub cub, char c)
{
    int i, j;
    for (i = 0; i < Nr_Fete - 1; ++i) {
        Rotate("Cube_Right", cub, 0);
        if (cub->U_M->next_L->c == cub->U_M->c && c == cub->F_M->prev_L->c) {
            for(j = 0; j < i + 1; ++j) {
                Rotate("Cube_Left", cub, 0);
            }
            if(i == 2)
                return -1;
            return i + 1;
        }

    }
    Rotate("Cube_Right", cub, 0);
    return 0;
}

int Search_FR(TCub cub, char c)
{
    int i, j;
    for (i = 0; i < Nr_Fete; ++i) {
        if (cub->F_M->prev_L->c == cub->U_M->c && cub->U_M->next_L->c == c) {
            for (j = 0; j < i; ++j) {
                Rotate("Cube_Left", cub, 0);
            }
            if(i == 3)
                return -1;
            return i;
        }
        Rotate("Cube_Right", cub, 0);
    }
    return 5;
}

int Search_SR(TCub cub, char c)
{
    int i, j;
    for (i = 0; i < Nr_Fete; ++i) {
        if((culoare(cub->F_M->prev_H) == culoare(cub->U_M) && culoare(cub->L_M->next_H) == c) ||
           (culoare(cub->F_M->next_H) == culoare(cub->U_M) && culoare(cub->R_M->prev_H) == c)) {
            for (j = 0; j < i; ++j) {
                Rotate("Cube_Left", cub, 0);
            }
            if(i == 3)
                return -1;
            return i;
        }
        Rotate("Cube_Right", cub, 0);
    }
    return 5;
}

int Search_TR(TCub cub, char c)
{
    int i, j;
    for (i = 0; i < Nr_Fete; ++i) {
        if (cub->F_M->next_L->c == cub->U_M->c && cub->D_M->prev_L->c == c) {
            for (j = 0; j < i; ++j) {
                Rotate("Cube_Left", cub, 0);
            }
            if(i == 3)
                return -1;
            return i;
        }
        Rotate("Cube_Right", cub, 0);
    }
    return 5;
}

int Search_Down(TCub cub, char c)
{
    int i, j;
    for (i = 0; i < Nr_Fete; ++i) {
        if (cub->F_M->next_L->c == c && cub->D_M->prev_L->c == cub->U_M->c) {
            for (j = 0; j < i; ++j) {
                Rotate("Cube_Left", cub, 0);
            }
            if(i == 3)
                return -1;
            return i;
        }
        Rotate("Cube_Right", cub, 0);
    }
    return 5;
}

void Alg_Up(TCub cub, int cnt)
{
    int i;
    if (cnt > 0) {
        for(i = 0; i < cnt; ++i)
            Rotate("Cube_Right", cub, 1);
        printf("\n");
        Rotate("F\'", cub, 1);
        Rotate("F\'", cub, 1);
        for(i = 0; i < cnt; ++i)
            Rotate("Cube_Left", cub, 1);
        printf("\n");
        for(i = 0; i < cnt; ++i)
            Rotate("D\'", cub, 1);
        Rotate("F\'", cub, 1);
        Rotate("F\'", cub, 1);
    } else {
        Rotate("Cube_Left", cub, 1);
        printf("\n");
        Rotate("F\'", cub, 1);
        Rotate("F\'", cub, 1);
        Rotate("Cube_Right", cub, 1);
        printf("\n");
        Rotate("D", cub, 1);
        Rotate("F\'", cub, 1);
        Rotate("F\'", cub, 1);
    }
}

void Alg_FR(TCub cub, int cnt)
{
    int i;
    if (cnt >= 0) {
        for (i = 0; i < cnt; ++i) 
            Rotate("U", cub, 1);
    } else {
        Rotate("U\'", cub, 1);
    }
        Rotate("F", cub, 1);
        Rotate("U\'", cub, 1);
        Rotate("R", cub, 1);
        Rotate("U", cub, 1);
}

void Alg_SR(TCub cub, int cnt)
{
    int i;
    char mid = cub->F_M->c;
    if (cnt >= 0) {
        for (i = 0; i < cnt; ++i)
            Rotate("MH", cub, 1);
        if ((culoare(cub->F_M->prev_H) == culoare(cub->U_M)) && (mid == culoare(cub->L_M->next_H)))
            Rotate("F", cub, 1);
        else
            Rotate("F\'", cub, 1);
        Rotate("ML", cub, 1);
        Rotate("D", cub, 1);
        Rotate("ML\'", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("F", cub, 1);
        Rotate("F", cub, 1);
        for (i = 0; i < cnt; ++i)
            Rotate("MH\'", cub, 1);
    } else {
        Rotate("MH\'", cub, 1);
         if ((culoare(cub->F_M->prev_H) == culoare(cub->U_M)) && (culoare(cub->F_M) == culoare(cub->L_M->next_H)))
            Rotate("F\'", cub, 1);
        else
            Rotate("F", cub, 1);
        Rotate("ML", cub, 1);
        Rotate("D", cub, 1);
        Rotate("ML\'", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("F", cub, 1);
        Rotate("F", cub, 1);
        Rotate("MH", cub , 1);
    }
}

void Alg_TR(TCub cub, int cnt)
{
    int i;
    if(cnt >= 0) {
        for (i = 0; i < cnt; ++i)
            Rotate("D\'", cub, 1);
    } else {
        Rotate("D", cub, 1);
    }
    Rotate("ML", cub, 1);
    Rotate("D", cub, 1);
    Rotate("ML\'", cub, 1);
    Rotate("D", cub, 1);
    Rotate("F", cub, 1);
    Rotate("F", cub, 1);
}

void Alg_Down(TCub cub, int cnt)
{
    int i;
    if (cnt >= 0) {
        for (i = 0; i < cnt; ++i) 
            Rotate("D\'", cub, 1);
    } else {
        Rotate("D", cub , 1);
    }
    Rotate("F", cub, 1);
    Rotate("F", cub, 1);
}
