#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int min(int a, int b){
    return (a < b) ? a : b;
}
 
#define MAXN 200 
int mem[MAXN+1][MAXN+1][MAXN+1];
 
int achicar(int* lista, int* res, int n){
	// comprime los valores manteniendo el orden relativo
    // por ejemplo [1, 900, 3, 5, 99999999] pasa a ser [1,4,2,3,5]

    // en el enunciado los elementos posibles van del 0 al 10^6, mientras que la lista de entrada tiene como mucho 200 elementos
    int k = 0;
    int ordenada[MAXN];
    for(int j = 0; j < n; j++){
        ordenada[j] = lista[j];
    }
 
    qsort(ordenada, n, sizeof(int), cmp);

    // elimino duplicados, solo necesito valores únicos para poder mapear
    for(int j = 0; j < n; j++){
        if(j == 0 || ordenada[j] != ordenada[j-1]){
            ordenada[k++] = ordenada[j];
        }
    }

    //mapeo de ids aca 
    for(int j = 0; j < n; j++){
        int left = 0, right = k-1;
        int id = 0;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(ordenada[mid] == lista[j]){
                id = mid +1;
                break;
            }
            else if(ordenada[mid] < lista[j]){
                left = mid +1;
            }
            else{
                right = mid -1;
            }
        }
        res[j] = id;
    }
    return k; //cantidad de elementos que son diferentes
 
}
 
 
int BN(int* enteros, int i, int ultimo_negro, int ultimo_blanco, int tamano){
	//enteros ya es una lista "comprimida"

	// caso base: no quedan elementos
    if(i == tamano){
        return 0;
    }
    
	// memorización: ya resolví este estado (i, ultimo_negro, ultimo_blanco)
    if (mem[i][ultimo_negro][ultimo_blanco] != -1) {
        return mem[i][ultimo_negro][ultimo_blanco];
    }
 
    int res;
    
    // pruebo todas las decisiones posibles, elijo la que minimiza no pintados
    if(enteros[i] > ultimo_negro && enteros[i] < ultimo_blanco){ 
        // caso 1: puedo pintar de blanco, negro o no pintar
        int negro = BN(enteros, i+1, enteros[i], ultimo_blanco, tamano);
        int blanco = BN(enteros, i+1, ultimo_negro, enteros[i], tamano);
        int nada = BN(enteros, i+1, ultimo_negro, ultimo_blanco, tamano) + 1;
 
        res = min(min(negro, blanco), nada);
    }
    else if(enteros[i] > ultimo_negro){ 
        // caso 2: puedo pintar de negro o no pintar
        int negro = BN(enteros, i+1, enteros[i], ultimo_blanco, tamano);
        int nada = BN(enteros, i+1, ultimo_negro, ultimo_blanco, tamano) + 1;
 
        res = min(negro, nada);
    }
    else if(enteros[i] < ultimo_blanco){ 
        // caso 3: puedo pintar de blanco o no pintar
        int blanco = BN(enteros, i+1, ultimo_negro, enteros[i], tamano);
        int nada = BN(enteros, i+1, ultimo_negro, ultimo_blanco, tamano) + 1;
 
        res = min(blanco, nada);
    }
    else {
        // caso 4: no puedo pintar este numero
        res = BN(enteros, i+1, ultimo_negro, ultimo_blanco, tamano) + 1;
    }
 
    mem[i][ultimo_negro][ultimo_blanco] = res;
    return res;
}
 
int main(){
    int n;
    while(1){
        scanf("%d", &n);
        if(n < 1){
            break;
        }
 
        int enteros_orig[MAXN];
        int enteros_res[MAXN];
        for(int j = 0; j < n; j++){
            scanf("%d", &enteros_orig[j]);
        }
 
        // comprimo lista entrada
        int k = achicar(enteros_orig, enteros_res, n);
		
        // lleno matriz mem con -1s para representar pasos no calculados
        for(int i=0; i<=n; i++) {
            for(int u=0; u<=k+1; u++) {
                for(int b=0; b<=k+1; b++) {
                    mem[i][u][b] = -1;
                }
            }
        }

        int res = BN(enteros_res, 0, 0, k+1, n);
        printf("%d\n", res);
    }
    return 0;
}