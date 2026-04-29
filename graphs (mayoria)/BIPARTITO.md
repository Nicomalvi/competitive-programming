# Bipartito

## Enunciado
Igna y Martín continúan sus aventuras! Como todos en TDA saben, a los JTPs les gustan los grafos bipartitos, especialmente los árboles.

Un grafo bipartito es un grafo cuyos vértices se pueden dividir en 2 conjuntos de tal manera que para cada arista (u,v) que pertenece al grafo, u y v pertenecen a diferentes conjuntos. Podés encontrar una definición más formal de un grafo bipartito en la sección de notas a continuación.

Los JTPs le dieron a Igna y Martín un árbol que consiste en n nodos y les pidieron que agregaran aristas al mismo de tal manera que el grafo siga siendo bipartito. Además, después de agregar estas aristas, el grafo debe ser simple (no debe contener loops, ni aristas múltiples). ¿Cuál es el número máximo de aristas que pueden agregar?

Un loop es una arista que conecta a un nodo consigo mismo. Un grafo no contiene aristas múltiples cuando para cada par de nodos no hay más de una arista entre ellos. Un ciclo y un loop no son lo mismo.

#### Input

La primera línea de entrada contiene un entero n — el número de nodos en el árbol (1≤n≤105).
Las siguientes n−1 líneas contienen enteros u y v (1≤u,v≤n, u≠v) — la descripción de las aristas del árbol.
Se garantiza que el grafo dado es un árbol.

#### Output

Imprimir un número entero — el número máximo de aristas que Igna y Martín pueden agregar al árbol mientras cumplan con las condiciones.

### Example
Input

3

1 2

1 3

Output

0

Input

5

1 2

2 3

3 4

4 5

Output

2

En el primer caso de prueba, la única arista que se puede agregar de tal manera que el grafo no contenga bucles ni aristas múltiples es (2,3), pero agregar esta arista haría que el grafo deje de ser bipartito, por lo que la respuesta es 0.

En el segundo caso de prueba, Igna y Martín pueden agregar las aristas (1,4) y (2,5).

## Resumen de la solución
La solución es simple si tomo en cuenta el hecho de que el input es un árbol, que siempre es bipartito: Al ejecutar un DFS modificado sé que por cada nivel de profunidad estaré alternando entre los conjuntos A y B del grafo bipartito, entonces puedo llevar la cuenta de cuántos nodos hay en cada conjunto. 
Finalmente, en un grafo bipartito la cantidad máxima de aristas que puede haber la consigo conectado todos los nodos de A con todos los nodos de B, entonces la respuesta es |Nodos A| * |Nodos B| - |Aristas ya existentes|.

## Complejidad de la solución
- Complejidad temporal: Construyo la lista de adyacencia en O(n) y luego hago un DFS que recorre cada nodo y arista una sola vez, en total: O(n)
- Complejidad espacial: Un árbol tiene n−1 aristas. Al construir la lista de adyacencia guardo cada arista dos veces, por lo que tengo 2(n−1) referencias. Además, utilizo un arreglo de visitados de tamaño n. En total: O(n)