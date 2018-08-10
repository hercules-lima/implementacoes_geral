#include <stdio.h>
#include <limits.h>

#define V 20

int distanciaminima(int distancia[], bool definespt[])
{
   int min = INT_MAX, menorindice;

   for (int v = 0; v < V; v++)
     if (definespt[v] == false && distancia[v] <= min)
         min = distancia[v], menorindice = v;

   return menorindice;
}

int printSolution(int distancia[], int n)
{
   printf("Vertice   Distancia do Inicio\n");
   for (int i = 0; i < V; i++)
      printf("%d         %d\n", i, distancia[i]);
}

void dijkstra(int grafo[V][V], int src)
{
     int distancia[V];

     bool definespt[V];

     for (int i = 0; i < V; i++)
        distancia[i] = INT_MAX, definespt[i] = false;

     distancia[src] = 0;

     for (int count = 0; count < V-1; count++)
     {

       int u = distanciaminima(distancia, definespt);

       definespt[u] = true;

       for (int v = 0; v < V; v++)

         if (!definespt[v] && grafo[u][v] && distancia[u] != INT_MAX
                                       && distancia[u]+grafo[u][v] < distancia[v])
            distancia[v] = distancia[u] + grafo[u][v];
     }

     printSolution(distancia, V);
}

int main()
{
   int grafo[V][V] = {{0, 0, 2, 0, 0, 0, 6, 7, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 4, 0, 0, 0, 0, 0, 8, 0}
                     };

    dijkstra(grafo, 0);

    return 0;
}
