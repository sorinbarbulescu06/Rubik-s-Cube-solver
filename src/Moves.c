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