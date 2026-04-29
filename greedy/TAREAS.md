# Tareas

## Enunciado
#### Input

The first line consists of an integer T, the number of test cases. For each test case the first line consists of an integer N, the number of activities. Then the next N lines contains two integers m and n, the start and end time of each activity.
#### Output

For each test case find the maximum number of activities that you can do.

Constraints

1 ≤ T ≤10

1 ≤ N ≤ 100000

0 ≤ start < end ≤ 1000000 

### Example
Input

3

3

3 9

2 8

6 9

4

1 7

5 8

7 8

1 8

6

7 9

0 10

4 5

8 9

4 10

5 7

Output:

1

2

3

## Resumen de la solución
El problema pide, dada una serie de actividades con horario de inicio y fin, devolver la cantidad máxima de actividades que se pueden hacer sin que se superpongan.

Primero ordeno las actividades por hora de finalización (merge sort modificado), así puedo considerar primero las actividades que terminan antes.

Luego recorro las actividades en ese orden. Para cada actividad, si su hora de inicio es mayor o igual al fin de la última actividad seleccionada, "elijo hacerla" y actualizo el último fin. Si no, la descarto.

Este procedimiento es un algoritmo greedy: en cada paso se elige la actividad compatible que termina más temprano, lo que maximiza la cantidad total de actividades que se pueden realizar.

## Complejidad de la solución
- Complejidad temporal: Merge sort de las actividades + recorrer la lista, O(n log n + n) = O(n log n)
- Complejidad espacial: Guardo la lista de actividades y el merge sort usa arrays aux., O(n)