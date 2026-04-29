#include <stdio.h>
#include <stdlib.h>

int find_root(int a, int raices[]){
    // devuelvo representante del conjunto al que pertenece "a"
    // sigo padres hasta la raiz, aplano el arbol
    while (raices[a] != a) {
        raices[a] = raices[raices[a]];
        a = raices[a];
    }
    return a;
}

void union_sets(int raices[], int rangos[], int a, int b){
    // si 2 conjuntos son diferentes...
    //      busco las raices para unir al arbol más chico con el más grande (según rangos)
    //      si tienen la misma raíz, aumento el rango
    int raizA = find_root(a, raices);
    int raizB = find_root(b, raices);

    if(raizA!=raizB){
        if(rangos[raizA]>rangos[raizB]){
            raices[raizB]=raizA;
        } else if (rangos[raizB]>rangos[raizA]){
            raices[raizA]=raizB;
        } else {
            raices[raizB] = raizA;
            rangos[raizA]++;
        }
    }
}
 
struct arista {
    int nodo1;
    int nodo2;
    long long costo;
};
 
int comparar_aristas(const void* a, const void* b) {
    // uso para ordenar aristas por costo, útil para Kruskal
    long long costo1 = ((struct arista*)a)->costo;
    long long costo2 = ((struct arista*)b)->costo;
    return (costo1 > costo2) - (costo1 < costo2);
}
 
int main() {
    int piezas;
    int promos;
    scanf("%d %d", &piezas, &promos);
    //conecto todos los nodos al nodo más barato (si no existe, promo esa arista siempre es la mejor opcion)
    //conecto todos los nodos con promo (si la promo es útil)
    //corro kruskal para conseguir AGM
 
    long long costos[piezas];
    struct arista aristas_validas[piezas + promos];
    int cant_aristas = 0;
 
    long long nodo_barato = 0;
    for (int i = 0; i < piezas; i++) {
        long long valor;
        scanf("%lld", &valor);
        costos[i] = valor;
        if(costos[i]<costos[nodo_barato]){
            nodo_barato = i;
        }
    }
 
    for (int i = 0; i<piezas; i++){
        if(i!=nodo_barato){
            // conecto todo notdo al mas barato
            aristas_validas[cant_aristas++] = (struct arista){nodo_barato, i, costos[i] + costos[nodo_barato]};
        }
    }
    
    for(int i = 0; i<promos; i++){
        int nodo1=-10;
        int nodo2=-10;
        long long precio_promo=-10;
        scanf("%d %d %lld", &nodo1, &nodo2, &precio_promo);

        // resto para que estén bien los índices del array
        nodo1--;
        nodo2--; 

        if(precio_promo<costos[nodo1] + costos[nodo2]){
            // si la promo conviene, creo esa arista
            aristas_validas[cant_aristas++] = (struct arista){nodo1, nodo2, precio_promo};
        }
    }
 
    // ordeno las aristas de menor a mayor y comienzo a agregarlas al AGM, teniendo en cuenta
    // costo y que no haya ciclos
 
    qsort(aristas_validas, cant_aristas, sizeof(struct arista), comparar_aristas);
 
    int rangos[piezas];
    int raices[piezas];
    long long costo_total = 0;
    
    for (int i = 0; i < piezas; i++){
        // inicializo cada nodo como su propio conjunto
        rangos[i] = 0;
        raices[i] = i; //todo nodo  es su propia raiz (nuevamente util para kruskal)
    }

    // kruskal
    int aristas_en_agm = 0;
    for (int i = 0; i < cant_aristas+1 && aristas_en_agm < piezas - 1; i++){
        int u = aristas_validas[i].nodo1;
        int v = aristas_validas[i].nodo2;
        int raizA = find_root(u, raices);
        int raizB = find_root(v, raices);

        if (raizA != raizB) { // si no estoy formando un ciclo...
            // uno los conj. , sumo el costo, nace una arista
            union_sets(raices, rangos, raizA, raizB);
            costo_total += aristas_validas[i].costo;
            aristas_en_agm++;
        }
    }
 
    printf("%lld ", costo_total);
    return 0;
}
