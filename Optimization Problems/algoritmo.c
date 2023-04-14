#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

// Gera um vizinho
// Parametros: solucao actual, vizinho, numero de totalVertices, numero de vertices da solucao
//Troca 1 vertice aleatório por outro aleatório
void gera_vizinho(const int sol[], int nova_sol[], int totalV, const int *k) {
    int v;

    //Copia solução para nova solução
    for (int i = 0; i < *k; i++)
        nova_sol[i] = sol[i];

    //Encontra posição aleatória do conjunto solução
    v = random_l_h(0, *k - 1);

    //Depois de localizar a posição, altera o valor da posição para outro vértice aleatório da vizinhaça
    while (sol[v] == nova_sol[v]) {
        nova_sol[v] = random_l_h(1, totalV);
        verf_repetidos(nova_sol, k, &totalV);
    }
    verf_repetidos(nova_sol, k, &totalV);

}

// Gera um vizinho
// Parametros: solucao actual, nova solucao, numero de totalVertices, numero de vertices da solucao
//Troca 2 vertices aleatórios por outros 2 aleatórios

void gera_vizinho2(const int sol[], int nova_sol[], int totalV, const int *k)
{
    int v1 = 0,v2 = 0;

    //Copia solução para nova solução
    for(int i = 0; i < *k; i++)
        nova_sol[i] = sol[i];

    //Encontra posição aleatória do conjunto solução
    v1 = random_l_h(0,*k-1);

    //Encontra 2 posição aleatória do conjunto solução
    while(v1 == v2){
        v2 = random_l_h(0,*k-1);
    }

    //Depois de localizar a posição, altera o valor da posição para outro vértice aleatório da vizinhaça
    while(sol[v1] == nova_sol[v1] ){
        nova_sol[v1] = random_l_h(1,totalV);
        verf_repetidos(nova_sol,k,&totalV);
    }

    while(sol[v2] == nova_sol[v2] ){
        nova_sol[v2] = random_l_h(1,totalV);
        verf_repetidos(nova_sol,k,&totalV);
    }
    verf_repetidos(nova_sol,k,&totalV);

}

// Trepa colinas first-choice
// Parametros: solucao, matriz de adjacencias, numero de totalVertices, numero de vertices da solucao
// Devolve o custo da melhor solucao encontrada
int trepa_colinas(int sol[], int **grafo, int totalV, const int *k, int num_iter) {

    int *nova_sol;
    int custo, custo_viz, n;

    nova_sol = malloc (sizeof(int)* (*k));

    if (nova_sol == NULL) {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    // Avalia solucao inicial
    custo = calcula_fit(sol, grafo, k);

    for(int i = 0; i < num_iter; i++){

    // Gerar vizinhaça
    //gera_vizinho(sol, nova_sol, totalV, k);
    gera_vizinho2(sol, nova_sol, totalV, k);

    // Avalia vizinho
    custo_viz = calcula_fit(nova_sol, grafo, k);

    // Aceita vizinho se o custo aumentar (o objetivo é a maximizacao)
    if (custo_viz >= custo) {
        substitui(sol, nova_sol, *k);
        custo = custo_viz;
    }

    }

    free(nova_sol);
    return custo;
}
