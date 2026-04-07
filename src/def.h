#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 3
#define Nr_Fete 4
#define BG_ROSU     "\033[41m"
#define BG_ALBASTRU "\033[44m"
#define BG_ORANJ    "\033[48;5;208m"
#define BG_VERDE    "\033[42m"
#define BG_GALBEN   "\033[43m"
#define BG_ALB      "\033[47m"
#define RESET       "\033[0m"


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
    TNod F_M;
    TNod L_M;
    TNod R_M;
    TNod U_M;
    TNod D_M;
    TNod B_M;
}size_cub, *TCub;

//func.c
TCub Init_Cub();
TCub citire(TCub cub);
void afis(TCub cub);
void Rotate(const char *c, TCub cub, int output);
char culoare(TNod t);

//func.c
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
void ML(TCub cub);
void ML_Inverted(TCub cub);
void MD(TCub cub);
void MD_Inverted(TCub cub);
void MH(TCub cub);
void MH_Inverted(TCub cub);

//step1.c
int CheckPas1(TCub cub);
void SolvePas1(TCub cub);
int Search_Up(TCub cub, char c);
int Search_FR(TCub cub, char c);
int Search_SR(TCub cub, char c);
int Search_TR(TCub cub, char c);
int Search_Down(TCub cub, char c);
void Alg_Up(TCub cub, int cnt);
void Alg_FR(TCub cub, int cnt);
void Alg_SR(TCub cub, int cnt);
void Alg_TR(TCub cub, int cnt);
void Alg_Down(TCub cub, int cnt);