#include "algoritmo.h"
#include "utils.h"

#define DEFAULT_RUNS 100 //Nº de repetições do programa

int main(int argc, char *argv[]) {

    char nome_fich[100];

    int totalV,
            arestas,
            k,
            i,
            num_iter,
            runs,
            custo,
            best_custo = 0,
            **grafo,
            *sol,
            *best;

    float mbf = 0;

    if (argc == 3) {

        runs = atoi(argv[2]);
        strcpy(nome_fich, argv[1]);

    } else if (argc == 2) {

        runs = DEFAULT_RUNS;
        strcpy(nome_fich, argv[1]);

    } else {

        runs = DEFAULT_RUNS;
        printf("Nome do Ficheiro: ");
        gets(nome_fich);

        if (runs <= 0)
            return 0;

        init_rand();

        // Preenche matriz de adjacencias
        grafo = init_dados(nome_fich, &totalV, &k, &arestas);

        sol = malloc(sizeof(int) * k);

        best = malloc(sizeof(int) * k);

        if (sol == NULL || best == NULL) {

            printf("Erro na alocacao de memoria");
            exit(1);

        }

        printf("\nQuantas iteracoes deseja efetuar?");
        scanf("%d",&num_iter);

        for (i = 0; i < runs; i++) {

            // Gerar solucao inicial
            gera_sol_inicial(sol, &totalV, &k);
            printf("Solucao Inicial: ");
            escreve_sol(sol, &k);


            // Trepa colinas
            custo = trepa_colinas(sol, grafo, totalV, &k, num_iter);

            // Escreve resultados da repeticao k
            printf("\nRepeticao %d:", i+1);
            escreve_sol(sol, &k);

            printf("Custo final: %2d\n", custo);

            mbf += custo;
          if (i == 0 || best_custo < custo) {
                best_custo = custo;
                substitui(best, sol, k);

            }
        }
            // Escreve resultados globais
            printf("\n=================================\n");
            printf("        Resultados globais: \n");
            printf(" =================================\n");

            printf("\nMBF: %f\n", mbf /i);
            printf("Melhor solucao encontrada:");
            escreve_sol(best, &k);
            printf("Custo final: %2d\n", best_custo);


            free(grafo);
            free(sol);
            free(best);

    }
    return 0;
}
