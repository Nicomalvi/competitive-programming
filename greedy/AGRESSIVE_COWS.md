# Agressive Cows

## Enunciado
Farmer John has built a new long barn, with N (2 ≤ N ≤ 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 ≤ xi ≤ 1,000,000,000).

His C (2 ≤ C ≤ N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
#### Input

t – the number of test cases, then t test cases follows.

    Line 1: Two space-separated integers: N and C
    Lines 2..N+1: Line i+1 contains an integer stall location, xi

#### Output

For each test case output one integer: the largest minimum distance.

### Example
Input:
1
5 3
1
2
8
4
9

Output:
3
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.

## Resumen de la solución
Tengo N establos con posiciones dadas y C vacas. Quiero maximizar la distancia mínima entre cualquier par de vacas ubicadas en distintos establos.

Primero ordeno los establos por posición, luego hago una búsqueda binaria sobre la distancia mínima posible entre vacas:

Defino un rango de distancias posibles entre distMin = 1 y distMax = establos[n-1] - establos[0].
En cada iteración parto este rango en dos, calculando una distancia media: distMedia = (distMin + distMax) / 2
Recorro los establos de izquierda a derecha colocando vacas de forma greedy: pongo la primera en el primer establo y cada siguiente en el primer establo que esté al menos a esa distancia del último usado.

Con esto verifico si puedo ubicar todas las vacas:

- Si puedo, significa que esta distancia funciona, así que descarto la mitad inferior del rango y sigo buscando en la mitad superior (distMin = distMedia + 1).
- Si no puedo, significa que la distancia es demasiado grande, así que descarto la mitad superior (distMax = distMedia - 1).

Al finalizar (cuando el rango se achique completamente y distnMin >= distMax), la mejor distancia guardada es la máxima distancia mínima posible.

## Complejidad de la solución
- Complejidad temporal: Merge sort inicial + recorrida greedy lineal de los establos por cada paso de la busqueda binaria en distancias, O(n log n + n log k), donde k es la distancia máxima entre establos. 
- Complejidad espacial: Uso array auxiliar para el merge sort, O(n) 