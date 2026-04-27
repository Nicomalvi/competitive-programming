#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct {
    int comienzo;
    int fin;
} Actividad;
 
void merge(Actividad arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    Actividad leftArr[n1], rightArr[n2];
 
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
 
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].fin <= rightArr[j].fin) {
            arr[k] = leftArr[i];
            i++;
        } else {
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
 
void mergeSort(Actividad arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
 
int actMaximas(Actividad acts[], int tamano){
    int count = 0;
    int ultFin = -1; // asumo tiempos >= 0

    // greedy: tomo cada actividad que no se superpone con la última elegida
    for(int i = 0; i < tamano; i++){
        if(acts[i].comienzo >= ultFin){
            count++;
            ultFin = acts[i].fin;
        }
    }

    return count;
}
 
int main(){
    int n;
    int res;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int cantidad_actividades;
 
        scanf("%d", &cantidad_actividades);
        Actividad actividades[cantidad_actividades];
 
        for(int j = 0; j<cantidad_actividades; j++){
            int comienzo;
            int fin;
 
            scanf("%d", &comienzo);
            scanf("%d", &fin);
            actividades[j].comienzo = comienzo;
            actividades[j].fin = fin;
        }
 
        mergeSort(actividades, 0, cantidad_actividades-1);
        res = actMaximas(actividades, cantidad_actividades);
        printf("%d\n", res);
    }
    return 0;
}