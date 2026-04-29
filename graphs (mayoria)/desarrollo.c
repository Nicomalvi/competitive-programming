#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    long long* res = (long long*)malloc(n * sizeof(long long));

    long long** grafo = (long long**)malloc(n * sizeof(long long*));
    for (int i = 0; i < n; i++) {
        grafo[i] = (long long*)malloc(n * sizeof(long long));
    }

    // inicializo grafo
    for(int i = 0; i<n; i++){//-------------------------------------- O(V^2)
        for(int j = 0; j<n; j++){
            long long costo;
            scanf("%lld", &costo);
            grafo[i][j] = costo;
            res[0] = res[0] + costo;
        }
    }
 
    int orden_eliminar[n];

    for(int i = 0; i<n; i++){//-------------------------------------- O(V)
        int orden;
        scanf("%d", &orden);
        orden_eliminar[n-1-i]=orden-1;
    }
    // voy haciendo floyd warshall mientras armo el grafo
    int visitado[n];
    for (int i = 0; i < n; i++){//-------------------------------------- O(V)
        visitado[i] = 0; 
    }
 
    for (int i = 0; i < n; i++){//-------------------------------------- O(V)
        res[i]=0;
        int orden = orden_eliminar[i];
        visitado[orden] = 1;

        for (int j = 0; j < n; j++) {//-------------------------------------- O(V)
            for (int k = 0; k < n; k++) {//-------------------------------------- O(V) --->> termina siendo V^3
                if (grafo[j][k] > grafo[j][orden] + grafo[orden][k]) {
                    grafo[j][k] = grafo[j][orden] + grafo[orden][k];
                }
                // orden es el que deberia eliminar pero lo estoy agregando
                if(visitado[j]&&visitado[k]){
                    // solo sumo distancias entre nodos que ya fueron agregados al grafo
                    res[i] = res[i] + grafo[j][k];
                }
                
            }
        }
    }
 
    for (int i = 0; i < n; i++) {//-------------------------------------- O(V)
        printf("%lld ", res[n-1-i]);
    }
   return 0;
}