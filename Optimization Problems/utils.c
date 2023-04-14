#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// Leitura do ficheiro de input
// Recebe: nome do ficheiro, numero de vertices (ptr), numero de iteracoes (ptr)
// Devolve a matriz de adjacencias
int** init_dados(char *nome, int *totalV, int *k, int *totalA){

	FILE *f;

	int     **p, **q,
            *a, *b;

	f = fopen(nome, "r");

    //Se o ficheiro não existir ou a abertura não for bem sucedida
	if(!f){

		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(EXIT_FAILURE);

	}

	// Numero de sub-vértices
	fscanf(f, "k %d", k);

    printf("\n N de Sub Vertices: %d", *k);

	// Numero total de vertices e de arestas
	fscanf(f, " p edge %d %d", totalV, totalA);

    printf("\nTotal de Vertices: %d", *totalV);
    printf("\n Total de Arestas: %d", *totalA);

	// Alocação dinamica da matriz
    p= (int**) malloc (*totalV * sizeof(int*));

    for(int i = 0; i < *totalV; i++){
        p[i] = (int*) malloc (*totalV * sizeof(int));
    }

    //Se a alocação de memória falhar
	if(!p){

	    printf("Erro na alocacao de memoria\n");
	    exit(EXIT_FAILURE);

	}

    q=p;

    //Preenche todas as linhas da matriz a 0
    for(int i = 0; i < *totalV; i++){
        for(int j = 0; j < *totalV; j++){

            q[i][j] = 0;

        }
    }
	//Lê todas as linhas do ficheiro
    for(int i = 0; i < *totalA; i++){

        fscanf(f, " e %d %d", a, b);
        printf("\nA: %d, B: %d", *a, *b);


        if(q[*a-1][*b-1] == 0 || q[*b-1][*a-1] == 0){
            q[*a-1][*b-1] = 1;
            q[*b-1][*a-1] = 1;

        }
    }
	fclose(f);
    escreve_mat(p,totalV);

	return p;
}

void escreve_mat(int **p, const int *totalV){

printf("\n\n Matriz de ligacoes do grafo: \n");

    for(int i = 0; i < *totalV; i++){
        for(int j = 0; j < *totalV; j++){

            printf("%d ", p[i][j]);
        }
        printf("\n\n");
    }

}

// Gera a solucao inicial
// Parametros: array para a solução, total de Vertices, número de vértices do conjunto solução
void gera_sol_inicial(int *sol, const int *totalV, int *k) {
    //Random de 1 até totalV
    for (int i = 0; i < *k; i++) {
        sol[i] = random_l_h(1, *totalV);

        //Verifica se há números repetidos para gerar solução aceitável
    }
    verf_repetidos(sol,k, totalV);

}


//Verifica se há vértices repetidos
// Parametros: solucao, numero de subvertices e numero total de vertices
void verf_repetidos(int *sol, const int *k,const int *totalV){

    for (int i = 0; i < *k; i++) {
        for (int j = i + 1; j < *k; j++) {
            while (sol[i] == sol[j]) {
                sol[j] = random_l_h(1, *totalV);
            }
        }

    }
}

// Escreve solucao
// Parametros: solucao e numero de vertices
void escreve_sol(const int *sol, const int *k){

	printf("\nConjunto S: ");

    for(int i = 0; i < *k; i++)
        printf("%d ", sol[i]);

    printf("\n");
}

//Copia vector b para a (tamanho n)
void substitui(int *a, int *b, int tam){

    for(int i = 0; i < tam; i++)
        a[i] = b[i];
}

// Inicializa o gerador de numeros aleatorios
void init_rand(){

	srand((unsigned)time(NULL));

}

// Devolve valor inteiro aleatorio entre min e max
int random_l_h(int min, int max){

	return min + rand() % (max-min+1);

}

// Devolve um valor real aleatorio do intervalo [0, 1]
float rand_01(){

	return ((float)rand())/RAND_MAX;

}