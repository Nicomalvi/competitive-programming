#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void agregar(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = *head;  
    *head = newNode;
}

void bfs(struct Node* lista[], int n, int res[]) {
    for (int i = 1; i <= n; i++) {
        res[i] = -1; 
    }
    res[1] = 0;  

    int cola[n];
    int c_inicio = 0, c_fin = 0;

    cola[c_fin++] = 1;  

    while (c_inicio < c_fin) {
        int actual = cola[c_inicio++];
        struct Node* temp = lista[actual];
        while (temp != NULL) {
            int vecino = temp->value;
            
            if (res[vecino] == -1) {  
                res[vecino] = res[actual] + 1;  
                cola[c_fin++] = vecino;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int cantidad_aulas;
    scanf("%d", &cantidad_aulas);
    int res[cantidad_aulas+1];

    // las aulas son los nodos de un grafo, las aristas las formas de viajar
    // en particular los atajos son una arista unidireccional
    // uso lista de adyacencia
    struct Node* lista[cantidad_aulas + 1];

    for (int i = 1; i <= cantidad_aulas; i++) {
        lista[i] = NULL;
    }

    // conecto todas las aulas
    // y los atajos
    for (int i = 1; i < cantidad_aulas+1; i++) {

        int atajo;
        scanf("%d", &atajo);
        agregar(&lista[i], atajo);

        if (i + 1 <= cantidad_aulas) {
            agregar(&lista[i], i + 1);
            agregar(&lista[i + 1], i);
        }


    }
    bfs(lista, cantidad_aulas, res);

    for(int i = 1; i< cantidad_aulas+1; i++){
        printf("%d ", res[i]);
        //coh 1 solo bfs tengo el camino mas corto desde 1 hasta todo i en res
    }
    return 0;
}
