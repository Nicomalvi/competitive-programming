# Blanco y negro

## Enunciado
You have a sequence of integers. You can paint each of the integers black or white, or leave it unpainted. The black integers must appear in ascending order and the white integers must appear in descending order. The ascending/descending order must be strict, that is, two integers painted with the same color cannot be equal. Paint the sequence so as to minimize the number of unpainted integers.
Input

The input contains several test cases, each one described in exactly two lines. The first line contains an integer N indicating the number of elements in the sequence (1 ≤ N ≤ 200). The second line contains N integers Xi separated by single spaces, representing the sequence to paint (1 ≤ Xi ≤ 106 for 1 ≤ i ≤ N ). The last line of the input contains a single −1 and should not be processed as a test case.
Output

For each test case output a single line with an integer representing the minimum number of unpainted elements of the sequence, when the sequence is painted optimally following the rules described above.

### Example
Input:

8

1 4 2 3 3 2 4 1

12

7 8 1 2 4 6 3 5 2 1 8 7

-1

Output:

0

2

## Resumen de la solución
Reescribo el enunciado: dada una lista de enteros, quiero minimizar la cantidad de elementos que no pertenecen a dos subsecuencias, una estrictamente creciente (negros) y otra estrictamente decreciente (blancos), sin solaparse.

Mi solución utiliza programación dinámica con memorización. En cada posición de la lista de entrada puedo decidir:

- pintar el número de negro (si mantiene el orden creciente),
- pintarlo de blanco (si mantiene el orden decreciente),
- no pintarlo.

El estado del DP se define como (i, UN, UB), donde:

- i es la posición actual en la lista,
- UN es el último valor usado en la subsecuencia creciente,
- UB es el último valor usado en la subsecuencia decreciente.

El resultado del estado es la mínima cantidad de elementos no pintados a partir de esa posición.

Surge un problema: los valores originales pueden ser muy grandes (hasta 10^6), lo que haría inviable la tabla de memorización. Para solucionarlo, tengo que comprimir la lista, reemplazando cada valor por su posición relativa en el orden de los elementos distintos. Los valores pasan a estar en el rango [1, k], con k≤200, y la tabla mem[i][UN][UB] termina siendo manejable.

Finalmente, el algoritmo explora todas las decisiones posibles usando memorización y se queda con la que minimiza la cantidad de elementos no pintados.

## Complejidad de la solución
- Complejidad temporal: Hay O(n * k * k) estados, con k<=n. Cada estado se calcula 1 vez, entonces O(n^3)
- Complejidad espacial: La matriz de memorización tiene dimensiones [n][k][k], nuevamente ya que n<=k resulta una complejidad O(n^3)