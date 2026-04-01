#include <stdlib.h>
#include <stdio.h>

#define N 3

typedef struct list_node {
    char c;
    struct list_node *next_H;
    struct list_node *next_D;
    struct list_node *next_L;
    struct list_node *prev_H;
    struct list_node *prev_D;
    struct list_node *prev_L;
}NSize, *TNod;

typedef struct cub {
    TNod *H;
    TNod *L;
    TNod *D;
}size_cub, *TCub;

TCub Init_Cub();
TCub citire(TCub cub);