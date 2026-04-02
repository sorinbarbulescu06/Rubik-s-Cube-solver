#include "def.h"

void afis(TCub cub)
{
    TNod q;
    int i, j;
    for (i = N - 1; i >= 0; --i) {
        q = cub->D[i]->prev_D; printf("      %c ", q->c);
        q = q->prev_D; printf("%c ", q->c);
        q = q->prev_D; printf("%c\n", q->c);
    }
    for (i = 0; i < N; ++i) {
        q = cub->H[i]->prev_H->prev_H->prev_H; printf("%c ", q->c);
        q = q->next_H; printf("%c ", q->c);
        q = q->next_H; printf("%c ", q->c);
        q = cub->H[i]->next_H; printf("%c ", q->c);
        for (j = 0; j < 8; ++j) {
            q = q->next_H; printf("%c ", q->c);
        }
        printf("\n");
    }
    for (i = 0; i < N; ++i) {
        q = cub->D[i]->next_D->next_D->next_D->next_D; printf("      %c ", q->c);
        q = q->next_D; printf("%c ", q->c);
        q = q->next_D; printf("%c\n", q->c);
    }
    
}

void Rotate(const char *c, TCub cub)
{
    printf("%s ", c);
    if (!strcmp(c, "F")) {
        Front(cub);
    } else if (!strcmp(c, "F\'")) {
        Front_Inverted(cub);
    } else if (!strcmp(c, "L")) {
        Left(cub);
    } else if (!strcmp(c, "L\'")) {
        Left_Inverted(cub);
    } else if (!strcmp(c, "R")) {
        Right(cub);
    } else if (!strcmp(c, "R\'")) {
        Right_Inverted(cub);
    } else if (!strcmp(c, "U")) {
        Up(cub);
    } else if (!strcmp(c, "U\'")) {
        Up_Inverted(cub);
    } else if (!strcmp(c, "D")) {
        Down(cub);
    } else if (!strcmp(c, "D\'")){
        Down_Inverted(cub);
    } else if (!strcmp(c, "B")) {
        Back(cub);
    } else if (!strcmp(c, "B\'")) {
        Back_Inverted(cub);
    } else if (!strcmp(c, "ML")) {
        ML(cub);
    } else if (!strcmp(c, "ML\'")) {
        ML_Inverted(cub);
    } else if (!strcmp(c, "MD")) {
        MD(cub);
    } else if (!strcmp(c, "MD\'")) {
        MD_Inverted(cub);
    } else if (!strcmp(c, "MH")) {
        MH(cub);
    } else if (!strcmp(c, "MH\'")) {
        MH_Inverted(cub);
    }


}

TCub Init_Cub()
{
    int i;
    TCub cub = (TCub)malloc(sizeof(size_cub));
    if (cub == NULL) {
        goto eroare_1;
    }
    cub->D = (TNod *)malloc(N * sizeof(TNod));
    cub->L = (TNod *)malloc(N * sizeof(TNod));
    cub->H = (TNod *)malloc(N * sizeof(TNod));

    if (cub->D == NULL || cub->H == NULL || cub->L == NULL) {
        goto eroare_2;
    }
    int eroare = 0;
    for (i = 0; i < N; i++) {
        cub->D[i] = (TNod)malloc(sizeof(NSize));
        if (cub->D[i] != NULL) {
            cub->D[i]->next_D = cub->D[i];
            cub->D[i]->prev_D = cub->D[i];
        } else {
            eroare = 1;
        }
        cub->L[i] = (TNod)malloc(sizeof(NSize));
        if (cub->L[i] != NULL) {
            cub->L[i]->next_L = cub->L[i];
            cub->L[i]->prev_L = cub->L[i];
        } else {
            eroare = 1;
        }
        cub->H[i] = (TNod)malloc(sizeof(NSize));
        if (cub->H[i] != NULL) {
            cub->H[i]->next_H = cub->H[i];
            cub->H[i]->prev_H = cub->H[i];
        } else {
            eroare = 1;
        }
    }
    if  (eroare == 1) {
        goto eroare_3;
    }

    return cub;
    
eroare_3:

    for (i = 0; i < N; i++) {
        free(cub->D[i]);
        free(cub->H[i]);
        free(cub->L[i]);
    }

eroare_2:

    free(cub->D);
    free(cub->H);
    free(cub->L);
    free(cub);

eroare_1:
    return NULL;
}

TCub citire(TCub cub)
{
    int i, j, k;
    
    //branch-ul H
    for (i = 0; i < N; ++i) {
        TNod p = cub->H[i];
        for (j = 0; j < 12; ++j) {//Y,W,O,R,G,B
            TNod t = (TNod)malloc(sizeof(NSize));
            scanf("%c", &t->c);
            p->next_H = t;
            t->prev_H = p;
            p = p->next_H;
        }
        cub->H[i]->prev_H = p;
        p->next_H = cub->H[i];
    }
    
    //branch-ul L
    for (k = 0; k < N; ++k) {
        TNod p = cub->L[k];
        for (i = 0; i < N; ++i) {
            TNod aux = cub->H[i];
            for (j = 0; j < k + 1; ++j)
                aux = aux->next_H;
            p->next_L = aux;
            aux->prev_L = p;
            p = p->next_L;
        }
        for (i = 0; i < N; ++i) {
            TNod t = (TNod)malloc(sizeof(NSize));
            scanf("%c", &t->c);
            p->next_L = t;
            t->prev_L = p;
            p = p->next_L;
        }
        for (i = N - 1; i >= 0; --i) {
            TNod aux = cub->H[i];
            for (j = 0; j < 4 + k; j++)
                aux = aux->prev_H;
            p->next_L = aux;
            aux->prev_L = p;
            p = p->next_L;
        }
        for (i = 0; i < N; ++i) {
            TNod t = (TNod)malloc(sizeof(NSize));
            scanf("%c", &t->c);
            p->next_L = t;
            t->prev_L = p;
            p = p->next_L;
        }
        p->next_L = cub->L[k];
        cub->L[k]->prev_L = p;
    }

    //branch-ul D
    for (k = 0; k < N; ++k) {
        TNod p = cub->D[k];
        for (j = 0; j < N; ++j) {
            TNod aux = cub->H[j];
            for(i = 0; i < k + 1; ++i)
                aux = aux->prev_H;
            p->next_D = aux;
            aux->prev_D = p;
            p = p->next_D;
        }
        for(j = 0; j < N; ++j) {
            TNod aux = cub->L[j];
            for(i = 0; i < k + 4; ++i)
                aux = aux->next_L;
            p->next_D = aux;
            aux->prev_D = p;
            p = p->next_D;
        }
        for(j = N - 1; j >= 0; --j) {
            TNod aux = cub->H[j];
            for(i = 0; i < k + 4; ++i)
                aux = aux->next_H;
            p->next_D = aux;
            aux->prev_D = p;
            p = p->next_D;
        }
        for(j = N - 1; j >= 0; --j) {
            TNod aux = cub->L[j];
            for(i = 0; i < k + 1; ++i)
                aux = aux->prev_L;
            p->next_D = aux;
            aux->prev_D = p;
            p = p->next_D;
        }
        p->next_D = cub->D[k];
        cub->D[k]->prev_D = p;
    }
    return cub;
}
