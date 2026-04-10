#include "def.h"

int CheckPas2(TCub cub)
{
    int i, j;
    for (i = 0; i < Nr_Fete; ++i) {
        if (cub->U_M->next_L->prev_D->c != cub->U_M->c ||
            cub->F_M->c != cub->F_M->prev_L->prev_H->c ||
            cub->L_M->c != cub->L_M->prev_D->next_H->c) {
            for (j = 0; j < i; ++j)
                Rotate("Cube_Left", cub, 0);
            return 0;
        }
        if (cub->U_M->next_L->next_D->c != cub->U_M->c ||
            cub->F_M->c != cub->F_M->prev_L->next_H->c ||
            cub->R_M->c != cub->R_M->next_D->prev_H->c){
            for (j = 0; j < i; ++j)
                Rotate("Cube_Left", cub, 0);
            return 0;
            }
        Rotate("Cube_Right", cub , 0);
    }
    return 1;
}

void SolvePas2(TCub cub)
{
    int i;
    for (i = 0; i < Nr_Fete; ++i) {
        printf("\nRezolvam pt. fata: %c\n\n", cub->F_M->c);

        //verificam pe fata de sus
        Corner_Up_Left(cub);
        Corner_Up_Right(cub);

        //verificam pe primul rand
        Search_FR2L(cub);

        //verificam pe ultimul rand
        Search_LR(cub);

        //verificam pe fata de jos
        if (Solve_DF(cub) == 1) {
            Rotate("Cube_Left", cub, 1);
            printf("\n");
            Alg_Right_Corner(cub);
            Rotate("Cube_Right", cub, 1);
            printf("\n");
            afis(cub);
            printf("\n");
        }

        Rotate("Cube_Right", cub, 1);
        printf("\n");
    }
}

void Corner_Up_Left(TCub cub)
{
    char mid = cub->F_M->c, left = cub->L_M->c;
    if(cmp_UL(cub, mid, left) == 1) {
        Rotate("R\'", cub, 1);
        Rotate("D", cub, 1);
        Rotate("R", cub, 1);
        Alg_Left_Corner(cub);
        printf("\n");
        afis(cub);
        printf("\n");
        return ;
    }
    Rotate("Cube_Right", cub, 0);
    if(cmp_UL(cub, mid, left) == 1) {
        Rotate("Cube_Left", cub, 0);
        Rotate("B\'", cub, 1);
        Rotate("D", cub, 1);
        Rotate("B", cub, 1);
        Rotate("D\'", cub, 1);
        Alg_Left_Corner(cub);
        printf("\n");
        afis(cub);
        printf("\n");
        return ;
    }
    Rotate("Cube_Right", cub, 0);
    if(cmp_UL(cub, mid, left) == 1) {
        Rotate("Cube_Left", cub, 0);
        Rotate("Cube_Left", cub, 0);
        Rotate("L\'", cub, 1);
        Rotate("D", cub, 1);
        Rotate("L", cub, 1);
        Rotate("D", cub, 1);
        Rotate("D", cub, 1);
        Alg_Left_Corner(cub);
        printf("\n");
        afis(cub);
        printf("\n");
        return;
    }
    Rotate("Cube_Right", cub, 0);
    Rotate("Cube_Right", cub, 0);
}

void Corner_Up_Right(TCub cub)
{
    char mid = cub->F_M->c, right = cub->R_M->c;
    if(cmp_UR(cub, mid, right) == 1) {
        Rotate("L", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("L\'", cub, 1);
        Alg_Right_Corner(cub);
        printf("\n");
        afis(cub);
        printf("\n");
        return ;
    }
    Rotate("Cube_Left", cub, 0);
    if(cmp_UR(cub, mid, right) == 1) {
        Rotate("Cube_Right", cub, 0);
        Rotate("B", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("B\'", cub, 1);
        Rotate("D", cub, 1);
        Alg_Right_Corner(cub);
        printf("\n");
        afis(cub);
        printf("\n");
        return ;
    }
    Rotate("Cube_Left", cub, 0);
    if(cmp_UR(cub, mid, right) == 1) {
        Rotate("Cube_Left", cub, 0);
        Rotate("Cube_Left", cub, 0);
        Rotate("R", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("R\'", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("D\'", cub, 1);
        Alg_Right_Corner(cub);
        printf("\n");
        afis(cub);
        printf("\n");
        return;
    }
    Rotate("Cube_Right", cub, 0);
    Rotate("Cube_Right", cub, 0);
}

void Alg_Left_Corner(TCub cub)
{
    Rotate("L", cub, 1);
    Rotate("D\'", cub, 1);
    Rotate("L\'", cub, 1);
}

void Alg_Right_Corner(TCub cub)
{
    Rotate("R\'", cub, 1);
    Rotate("D", cub, 1);
    Rotate("R", cub, 1);
}

int cmp_UL(TCub cub, char mid, char left)
{
    
    return cub->F_M->prev_L->next_H->c == left &&
        cub->R_M->next_D->prev_H->c == mid &&
            cub->U_M->next_L->prev_D->c == cub->U_M->c;
}

int cmp_UR(TCub cub, char mid, char right)
{
    return cub->F_M->prev_L->prev_H->c == right &&
        cub->L_M->prev_D->next_H->c == mid &&
            cub->U_M->next_L->next_D->c == cub->U_M->c;
}

int Search_FR2L(TCub cub)
{
    int i, j;
    char mid = cub->F_M->c, left = cub->L_M->c;
    for (i = 0; i < Nr_Fete; ++i) {
        if(cub->F_M->prev_L->prev_H->c == cub->U_M->c &&
            cub->U_M->next_L->next_D->c == left && 
            cub->L_M->next_H->prev_D->c == mid) {
            for (j = 0; j < i; ++j)
                Rotate("Cube_Right", cub ,0);
            if (i == 0) {
                Rotate("L", cub, 1);
                Rotate("D\'", cub, 1);
                Rotate("L\'", cub, 1);
                Rotate("D", cub ,1);
                Alg_Left_Corner(cub);
                printf("\n");
                afis(cub);
                printf("\n");
                return 1;
            }
            if (i == 1) {
                Rotate("B", cub, 1);
                Rotate("D\'", cub, 1);
                Rotate("B\'", cub, 1);
                Rotate("D", cub ,1);
                Rotate("D", cub ,1);
                Alg_Left_Corner(cub);
                printf("\n");
                afis(cub);
                printf("\n");
                return 1;
            }
            if (i == 2) {
                Rotate("R", cub, 1);
                Rotate("D\'", cub, 1);
                Rotate("R\'", cub, 1);
                Rotate("D\'", cub, 1);
                Alg_Left_Corner(cub);
                printf("\n");
                afis(cub);
                printf("\n");
                return 1;
            }
            if (i == 3) {
                Rotate("F", cub, 1);
                Rotate("D\'", cub, 1);
                Rotate("F\'", cub, 1);
                Alg_Left_Corner(cub);
                printf("\n");
                afis(cub);
                printf("\n");
                return 1;
            }
        }
        if (cub->F_M->prev_L->next_H->c == cub->U_M->c &&
            cub->U_M->next_L->prev_D->c == mid &&
            cub->R_M->next_D->prev_H->c == left) {
            for (j = 0; j < i; ++j)
                Rotate("Cube_Right", cub ,0);
            if (i == 0) {
                Rotate("R\'", cub , 1);
                Rotate("D", cub , 1);
                Rotate("R", cub , 1);
                Rotate("D\'", cub , 1);
                Rotate("D\'", cub , 1);
                Rotate("Cube_Left", cub, 1);
                printf("\n");
                Alg_Right_Corner(cub);
                Rotate("Cube_Right", cub, 1);
                printf("\n");
                afis(cub);
                printf("\n");
                return 1;
            }
            if (i == 1) {
                Rotate("F\'", cub , 1);
                Rotate("D", cub , 1);
                Rotate("F", cub , 1);
                Rotate("D\'", cub , 1);
                Rotate("Cube_Left", cub, 1);
                printf("\n");
                Alg_Right_Corner(cub);
                Rotate("Cube_Right", cub, 1);
                printf("\n");
                afis(cub);
                printf("\n");
                return 1;
            }
            if (i == 2) {
                Rotate("L\'", cub , 1);
                Rotate("D", cub , 1);
                Rotate("L", cub , 1);
                Rotate("Cube_Left", cub, 1);
                printf("\n");
                Alg_Right_Corner(cub);
                Rotate("Cube_Right", cub, 1);
                printf("\n");
                afis(cub);
                printf("\n");
                return 1;
            }
            if (i == 3) {
                Rotate("B\'", cub , 1);
                Rotate("D", cub , 1);
                Rotate("B", cub , 1);
                Rotate("D", cub , 1);
                Rotate("Cube_Left", cub, 1);
                printf("\n");
                Alg_Right_Corner(cub);
                Rotate("Cube_Right", cub, 1);
                printf("\n");
                afis(cub);
                printf("\n");
                return 1;
            }


        }
        Rotate("Cube_Left", cub, 0);
    }
    return 0;
}

int Search_LR(TCub cub)
{
    int i, j;
    char mid = cub->F_M->c;
    char left = cub->L_M->c;
    for (i = 0; i < Nr_Fete; ++i) {
        if (cub->F_M->next_L->prev_H->c == cub->U_M->c && 
            cub->L_M->next_H->next_D->c == left && 
            cub->F_M->next_L->prev_H->next_L->c == mid) {
            for(j = 0; j < i; ++j)
                Rotate("Cube_Right", cub, 0);
            if (i == 0) {
                Rotate("D", cub, 1);
            }
            if (i == 1) {
                Rotate("D", cub, 1);
                Rotate("D", cub, 1);
            }
            if (i == 2) {
                Rotate("D\'", cub, 1);
            }
            Alg_Left_Corner(cub);
            printf("\n");
            afis(cub);
            printf("\n");
            return 0;
        }
        if (cub->F_M->next_L->next_H->c == cub->U_M->c &&
            cub->F_M->next_L->next_H->next_H->c == mid &&
            cub->F_M->next_L->next_H->next_L->c == left) {
            for(j = 0; j < i; ++j)
                Rotate("Cube_Right", cub, 0);
            if (i == 0) {
                Rotate("D\'", cub, 1);
                Rotate("D\'", cub, 1);
            }
            if (i == 1) {
                Rotate("D\'", cub, 1);
            }
            if (i == 3) {
                Rotate("D", cub, 1);
            }
            Rotate("Cube_Left", cub, 1);
            printf("\n");
            Alg_Right_Corner(cub);
            Rotate("Cube_Right", cub, 1);
            printf("\n");
            afis(cub);
            printf("\n");
            return 0;
        }
        Rotate("Cube_Left", cub, 0);
    }

    return 0;
}

int Solve_DF(TCub cub)
{
    if(cub->F_M->next_L->prev_H->c == cub->L_M->c &&
       cub->F_M->next_L->prev_H->next_L->c == cub->U_M->c &&
       cub->F_M->next_L->prev_H->next_L->prev_D->c == cub->F_M->c) {
        Rotate("L", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("L\'", cub, 1);
        Rotate("D", cub, 1);
        return 1;
    }
    if (cub->F_M->next_L->next_H->c == cub->F_M->c &&
       cub->F_M->next_L->next_H->next_L->c == cub->U_M->c &&
       cub->F_M->next_L->next_H->next_H->c == cub->L_M->c) {
        Rotate("D\'", cub, 1);
        Rotate("L", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("L\'", cub, 1);
        Rotate("D", cub, 1);
        return 1;
    }
    if(cub->L_M->next_D->prev_H->c == cub->L_M->c && 
       cub->L_M->next_D->prev_H->next_D->c == cub->U_M->c &&
       cub->L_M->next_D->prev_H->prev_H->c == cub->F_M->c) {
        Rotate("D", cub, 1);
        Rotate("L", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("L\'", cub, 1);
        Rotate("D", cub, 1);
        return 1;
    }
    if(cub->R_M->prev_D->next_H->c == cub->F_M->c && 
       cub->R_M->prev_D->next_H->prev_D->c == cub->U_M->c &&
       cub->R_M->prev_D->next_H->next_H->c == cub->L_M->c) {
        Rotate("D", cub, 1);
        Rotate("D", cub, 1);
        Rotate("L", cub, 1);
        Rotate("D\'", cub, 1);
        Rotate("L\'", cub, 1);
        Rotate("D", cub, 1);
        return 1;
    }
    return 0;
}
