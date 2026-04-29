#include <stdio.h>
#include <stdlib.h>
 
//implementacion comun dijkstra
int V = 0;
int findminDistance(int dist[], int included[])
{
    int min = 100000000, min_index = 0;
 
    for (int v = 0; v < V; v++) {
        if (included[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
 
void DijkstrasAlgo(int** graph, int src, int dist[])
{
    int included[V];
 
    // modificacion: dist es parametro ahora-------------------------------------------------------------
    for (int i = 0; i < V; i++) {
        //dist[i] = 100000000;
        included[i] = 0;
    }
 
    dist[src] = 0;
 
    for (int count = 0; count < V - 1; count++) {
        int u = findminDistance(dist, included);
        included[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!included[v] && graph[u][v] != 100000000
                && dist[u] != 100000000
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}


struct Node {
    int nodo1;
    int nodo2;
    int costo;
    struct Node* next;
};

void agregar(struct Node** head, int nodo1, int nodo2, int costo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->nodo1 = nodo1;
    newNode->nodo2 = nodo2;
    newNode->costo = costo;
    newNode->next = *head;  
    *head = newNode;
}
 
int main() {
    // una arista (v,w) está en algún camino mínimo si:
    // d(s,v) + c(v,w) + d(w,t) == d(s,t)
    int cantidad_nodos, cantidad_ejes;
    scanf("%d %d", &cantidad_nodos, &cantidad_ejes);
    V = cantidad_nodos;
    //represento como una matriz de adyacencias
    int** grafo = (int**)malloc(cantidad_nodos * sizeof(int*));
    for (int i = 0; i < cantidad_nodos; i++) {
        grafo[i] = (int*)malloc(cantidad_nodos * sizeof(int));
        for (int j = 0; j < cantidad_nodos; j++) {
            grafo[i][j] = 100000000; //representa que no hay arista
        }
    }
    struct Node* lista_aristas = NULL;
    //conecto todas las esquinas
    for (int i = 0; i < cantidad_ejes; i++) {
        int nodo1, nodo2, costo;
        scanf("%d %d %d", &nodo1, &nodo2, &costo);
        costo = costo*2;
        // me quedo con la mejor arista si hay múltiples entre los mismos nodos
        if (costo <= grafo[nodo1][nodo2]) {
            grafo[nodo1][nodo2] = costo;
            grafo[nodo2][nodo1] = costo;
            agregar(&lista_aristas, nodo1, nodo2, costo);
        }
    }
 
    int* distancias = (int*)malloc(cantidad_nodos * sizeof(int));
    int* distancias_ult = (int*)malloc(cantidad_nodos * sizeof(int));
    for (int i = 0; i < V; i++) {
        distancias[i] = 100000000;
        distancias_ult[i] = 100000000;
    }
 
    int res = 0;

    DijkstrasAlgo(grafo, 0, distancias);
    DijkstrasAlgo(grafo, cantidad_nodos-1, distancias_ult);
    
 
    //paso por todas las aristas y chequeo si son st-eficientes
    //s = 0, t = n-1
    while(lista_aristas!=NULL){
        int v = lista_aristas->nodo1;
        int w = lista_aristas->nodo2;
        int dsv = distancias[v];                //d(s,v)
        int dsw = distancias[w];                //d(s,w)
        int cvw = lista_aristas->costo;         //costo arista (v,w)
        int dvt = distancias_ult[v];            //d(v,t)
        int dwt = distancias_ult[w];            //d(w,t)
        int dst = distancias[cantidad_nodos-1]; //costo arista (s,t)

        int camino_por_vw = 0;
        int camino_por_wv= 0;

        camino_por_vw = dsv + cvw + dwt;
        camino_por_wv = dsw + cvw + dvt;

        if(camino_por_vw == dst || camino_por_wv == dst){
            res = res + cvw;
        }

        lista_aristas = lista_aristas->next;
    }
 
   if(cantidad_nodos == 1){
    res = grafo[0][0];
   }
    printf("%d", res);
    for (int i = 0; i < cantidad_nodos; i++) {
        free(grafo[i]);
    }
    free(grafo);
    free(distancias);
    free(distancias_ult);
    return 0;
}