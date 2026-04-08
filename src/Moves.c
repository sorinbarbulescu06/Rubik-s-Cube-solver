#include "def.h"

void Front_Inverted(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->D[0]->next_D;
        char aux = p->c;
        while (p != cub->D[0]->prev_D) {
            char aux_aux = p->next_D->c;
            p->next_D->c = aux;
            aux = aux_aux;
            p = p->next_D;
        }
        cub->D[0]->next_D->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->H[0]->next_H;
        char aux, aux_aux;
        aux = q->c;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
}

void Front(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->D[0]->prev_D;
        char aux = p->c;
        while (p != cub->D[0]->next_D) {
            char aux_aux = p->prev_D->c;
            p->prev_D->c = aux;
            aux = aux_aux;
            p = p->prev_D;
        }
        cub->D[0]->prev_D->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->H[0]->next_H;
        char aux, aux_aux;
        aux = q->c;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
}

void Left_Inverted(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->L[0]->prev_L;
        char aux = p->c;
        while (p != cub->L[0]->next_L) {
            char aux_aux = p->prev_L->c;
            p->prev_L->c = aux;
            aux = aux_aux;
            p = p->prev_L;
        }
        cub->L[0]->prev_L->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->D[0]->next_D;
        char aux, aux_aux;
        aux = q->c;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
    
}

void Up_Inverted(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->H[0]->next_H;
        char aux = p->c;
        while (p != cub->H[0]->prev_H) {
            char aux_aux = p->next_H->c;
            p->next_H->c = aux;
            aux = aux_aux;
            p = p->next_H;
        }
        cub->H[0]->next_H->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->L[0]->prev_L;
        char aux, aux_aux;
        aux = q->c;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
}

void Down(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->H[2]->next_H;
        char aux = p->c;
        while (p != cub->H[2]->prev_H) {
            char aux_aux = p->next_H->c;
            p->next_H->c = aux;
            aux = aux_aux;
            p = p->next_H;
        }
        cub->H[2]->next_H->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->H[2]->prev_H->next_D;
        char aux, aux_aux;
        aux = q->c;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }

}

void Down_Inverted(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->H[2]->prev_H;
        char aux = p->c;
        while (p != cub->H[2]->next_H) {
            char aux_aux = p->prev_H->c;
            p->prev_H->c = aux;
            aux = aux_aux;
            p = p->prev_H;
        }
        cub->H[2]->prev_H->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->H[2]->prev_H->next_D;
        char aux, aux_aux;
        aux = q->c;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
}

void ML(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->L[1]->next_L;
        char aux = p->c;
        while (p != cub->L[1]->prev_L) {
            char aux_aux = p->next_L->c;
            p->next_L->c = aux;
            aux = aux_aux;
            p = p->next_L;
        }
        cub->L[1]->next_L->c = aux;
    }
}

void ML_Inverted(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->L[1]->prev_L;
        char aux = p->c;
        while (p != cub->L[1]->next_L) {
            char aux_aux = p->prev_L->c;
            p->prev_L->c = aux;
            aux = aux_aux;
            p = p->prev_L;
        }
        cub->L[1]->prev_L->c = aux;
    }
}

void MD(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->D[1]->prev_D;
        char aux = p->c;
        while (p != cub->D[1]->next_D) {
            char aux_aux = p->prev_D->c;
            p->prev_D->c = aux;
            aux = aux_aux;
            p = p->prev_D;
        }
        cub->D[1]->prev_D->c = aux;
    }
}

void MD_Inverted(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->D[1]->next_D;
        char aux = p->c;
        while (p != cub->D[1]->prev_D) {
            char aux_aux = p->next_D->c;
            p->next_D->c = aux;
            aux = aux_aux;
            p = p->next_D;
        }
        cub->D[1]->next_D->c = aux;
    }
}

void MH(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->H[1]->prev_H;
        char aux = p->c;
        while (p != cub->H[1]->next_H) {
            char aux_aux = p->prev_H->c;
            p->prev_H->c = aux;
            aux = aux_aux;
            p = p->prev_H;
        }
        cub->H[1]->prev_H->c = aux;
    }
}

void MH_Inverted(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->H[1]->next_H;
        char aux = p->c;
        while (p != cub->H[1]->prev_H) {
            char aux_aux = p->next_H->c;
            p->next_H->c = aux;
            aux = aux_aux;
            p = p->next_H;
        }
        cub->H[1]->next_H->c = aux;
    }
}

void Up(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->H[0]->prev_H;
        char aux = p->c;
        while (p != cub->H[0]->next_H) {
            char aux_aux = p->prev_H->c;
            p->prev_H->c = aux;
            aux = aux_aux;
            p = p->prev_H;
        }
        cub->H[0]->prev_H->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->L[0]->prev_L;
        char aux, aux_aux;
        aux = q->c;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
}

void Left(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->L[0]->next_L;
        char aux = p->c;
        while (p != cub->L[0]->prev_L) {
            char aux_aux = p->next_L->c;
            p->next_L->c = aux;
            aux = aux_aux;
            p = p->next_L;
        }
        cub->L[0]->next_L->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->D[0]->next_D;
        char aux, aux_aux;
        aux = q->c;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
    
}

void Back_Inverted(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->D[2]->prev_D;
        char aux = p->c;
        while (p != cub->D[2]->next_D) {
            char aux_aux = p->prev_D->c;
            p->prev_D->c = aux;
            aux = aux_aux;
            p = p->prev_D;
        }
        cub->D[2]->prev_D->c = aux;
    }

    for (i = 0; i < 2; ++i) {
        TNod q = cub->D[2]->next_D->prev_H;
        char aux, aux_aux;
        aux = q->c;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
}

void Back(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->D[2]->next_D;
        char aux = p->c;
        while (p != cub->D[2]->prev_D) {
            char aux_aux = p->next_D->c;
            p->next_D->c = aux;
            aux = aux_aux;
            p = p->next_D;
        }
        cub->D[2]->next_D->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->D[2]->next_D->prev_H;
        char aux, aux_aux;
        aux = q->c;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_L; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }

}

void Right(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->L[2]->prev_L;
        char aux = p->c;
        while (p != cub->L[2]->next_L) {
            char aux_aux = p->prev_L->c;
            p->prev_L->c = aux;
            aux = aux_aux;
            p = p->prev_L;
        }
        cub->L[2]->prev_L->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->L[2]->next_L->next_H;
        char aux, aux_aux;
        aux = q->c;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
}

void Right_Inverted(TCub cub)
{
    int i;
    //rotim felia
    for (i = 0; i < N; ++i) {
        TNod p = cub->L[2]->next_L;
        char aux = p->c;
        while (p != cub->L[2]->prev_L) {
            char aux_aux = p->next_L->c;
            p->next_L->c = aux;
            aux = aux_aux;
            p = p->next_L;
        }
        cub->L[2]->next_L->c = aux;
    }

    //rotim fata
    for (i = 0; i < 2; ++i) {
        TNod q = cub->L[2]->next_L->next_H;
        char aux, aux_aux;
        aux = q->c;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->next_D; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
        q = q->prev_H; aux_aux = q->c; q->c = aux; aux = aux_aux;
    }
}

