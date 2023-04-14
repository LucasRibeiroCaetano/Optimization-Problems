#include "utils.h"
#include "funcao.h"

// Calcula a qualidade de uma solução
// Recebe:  A solução, a matriz de adjacências, e o total de vertices da solucao
// Devolve: O custo que é o número de ligações(arestas) que existem na solução

int calcula_fit(const int sol[], int **grafo, const int *k)
{
    int nAresta = 0,aux1 , aux2;

    for(int i = 0; i < *k; i++) {

        aux1 = sol[i];

        for (int j = i + 1; j < *k ; j++) {

            aux2 = sol[j];

            if (grafo[aux1-1][aux2-1] == 1)//Verifica se existe aresta formada entre 2 vertices da solucao
                nAresta++;
        }
    }

	return nAresta;
}
