#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int** init_dados(char *nome, int *totalV, int *k, int *totalA);

void gera_sol_inicial(int *sol, const int *totalV, int *k);
void escreve_sol(const int *sol, const int *k);
void substitui(int *a, int *b, int tam);
void escreve_mat(int **p, const int *totalV);
void verf_repetidos(int *sol, const int *k,const int *totalV);

//Funções Random
void init_rand();
int random_l_h(int min, int max);
float rand_01();

