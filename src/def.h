#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
void afis(TCub cub);

void Rotate(const char *c, TCub cub);
void Front(TCub cub);
void Front_Inverted(TCub cub);
void Back(TCub cub);
void Back_Inverted(TCub cub);
void Right(TCub cub);
void Right_Inverted(TCub cub);
void Left(TCub cub);
void Left_Inverted(TCub cub);
void Up(TCub cub);
void Up_Inverted(TCub cub);
void Down(TCub cub);
void Down_Inverted(TCub cub);