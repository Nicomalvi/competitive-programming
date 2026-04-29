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

long long cant_a = 0;
long long cant_b = 0;

void dfs(int v, struct Node* lista[], int visitado[], int nivel) {
    visitado[v] = 1;
    // en grafo bipartito cambiar profundidad = cambiar conjunto
    if (nivel % 2 == 0) {
        cant_a++;
    } else {
        cant_b++;
    }

    struct Node* temp = lista[v];
    while (temp != NULL) {
        int vecino = temp->value;
        if (!visitado[vecino]) {
            dfs(vecino, lista, visitado, nivel + 1);
        }
        temp = temp->next;
    }
}

int main() {
    int cantidad_nodos;
    scanf("%d", &cantidad_nodos);

    struct Node* lista[cantidad_nodos + 1];
    for (int i = 1; i <= cantidad_nodos; i++) {
        lista[i] = NULL;
    }

    for (int i = 0; i < cantidad_nodos - 1; i++) {
        int nodo1, nodo2;
        scanf("%d %d", &nodo1, &nodo2);
        agregar(&lista[nodo1], nodo2);
        agregar(&lista[nodo2], nodo1);
    }

    int visitado[cantidad_nodos + 1];
    for (int i = 1; i <= cantidad_nodos; i++) {
        visitado[i] = 0;
    }

    cant_a = 0;
    cant_b = 0;

    dfs(1, lista, visitado, 0);

    long long aristas_posibles = cant_a * cant_b;
    int aristas_actuales = cantidad_nodos - 1;
    long long res = aristas_posibles - aristas_actuales;

    printf("%lld\n", res);

    return 0;
}
