#include <stdio.h>
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    int leftArr[n1], rightArr[n2];
 
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
 
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      
        int mid = left + (right - left) / 2;
 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
 
        merge(arr, left, mid, right);
    }
}
 
int DMM (int cantidad_vacas, int cantidad_establos, int* establos){
    int minima_dist = 1;
    int maxima_dist = establos[cantidad_establos-1] - establos[0];
    int mejor_distancia = 1;
    while(minima_dist<=maxima_dist){
        int distancia_media = (minima_dist + maxima_dist) / 2;

        // coloco la primer vaca en el primer establo y luego greedy coloca las demás
        int ultimo_establo_asignado = establos[0];
        int vacas_puestas = 1;
        for(int i = 1; i<cantidad_establos; i++){
            if(establos[i] - ultimo_establo_asignado >= distancia_media){
                vacas_puestas++;
                ultimo_establo_asignado = establos[i];
            }
        }
 
        if (vacas_puestas>=cantidad_vacas){
                // pude posicionar las vacas a esta distancia, pruebo de vuelta mas lejos
                mejor_distancia = distancia_media;
                minima_dist = distancia_media + 1;
        } else {
                //no pude con esa distancia, buscare ejemplos menores
                maxima_dist = distancia_media - 1;
                }
    }
    return mejor_distancia;
}
 

int main() {
    int cantidad_tests;
    scanf("%d", &cantidad_tests);
 
    for(int i = 0; i<cantidad_tests; i++){ 
        int cantidad_vacas;
        int cantidad_establos;
 
        scanf("%d %d", &cantidad_establos, &cantidad_vacas );
        
        int establos[cantidad_establos];
 
        for(int j = 0; j<cantidad_establos; j++){
 
            int x_establo;
            scanf("%d", &x_establo);
            establos[j] = x_establo;
        }
 
        mergeSort(establos, 0, cantidad_establos-1);
        printf("%d\n", DMM(cantidad_vacas, cantidad_establos, establos));
    }
    return 0;
} 