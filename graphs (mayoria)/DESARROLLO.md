# Desarrollo

## Enunciado
Tomás quiere estudiar cómo fue cambiando el nivel de conectividad de la Ciudad de Buenos Aires a lo largo del tiempo. Para ello, armó un digrafo G donde los n nodos denotan las esquinas de la ciudad, y donde los ejes se corresponden con calles dirigidas que unen estas esquinas. Para estas esquinas conoce el orden cronológico en el que fueron agregadas al trazado de la ciudad.

Para estudiar la conectividad de la ciudad se propone la siguiente tarea: va a ir eliminando las esquinas del grafo en el orden opuesto al que fueron creadas, y cada vez que borra una va a calcular la suma de todas las distancias entre todos los pares de esquinas que todavía están en el mapa. De esta forma, estudiando como aumenta este valor cree poder entender cuáles esquinas fueron las más importantes para aumentar la conectividad de la ciudad entera.

Debemos ayudar a Tomás a completar la tarea que propuso.
#### Input

La primera línea contiene un entero n (1≤n≤500) indicando el número de esquinas de la ciudad.

Las siguientes n líneas contienen n enteros cada una. El j-esimo entero en la línea i indica la longitud de la calle que une a i con j. Esta longitud es a lo sumo 100000. La última línea tiene n números distintos, e indican el orden cronológico invertido en el cual fueron agregadas las esquinas. Es decir, la primera esquina de esta lista es la última que fue creada, y por lo tanto la primera que va a quitar Tomás.
#### Output

Se deben imprimir n enteros. El i-esimo de estos debe indicar la suma de las distancias de los nodos que quedan tras eliminar del grafo las últimas i−1 esquinas que fueron creadas.

### Example
Input

1
0
1

Output

0 

Input

2
0 5
4 0
1 2

Output

9 0 

Input

4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3

Output

17 23 404 0 
## Resumen de la solución
La idea de la solución se basa en cómo funciona el algoritmo de Floyd-Warshall: Definimos caminoMinimo(i,j,k) como la función que devuelve el camino mínimo de i a j, utilizando los vértices de 1 a k. Luego:

caminoMinimo(i,j,k) = min(caminoMinimo(i,j,k-1), caminoMinimo(i,k,k-1)+caminoMinimo(k,j,k-1))
caminoMinimo(i,j,0) = pesoArista(i,j)

El algoritmo calcula todos los caminos mínimos aumentando progresivamente el conjunto de nodos intermedios: primero con k = 1, luego k = 2, y así hasta k = n.

La clave del problema es aprovechar esta propiedad; en lugar de ir eliminando nodos (lo que obligaría a recalcular toda distancia desde cero), invierto el proceso: se agregan los nodos en el orden inverso de eliminación.

De esta forma, cada vez que agrego un nodo k, puedo usarlo como nuevo intermediario y actualizar las distancias como hace Floyd-Warshall. En cada paso simplemente hay que sumar las distancias entre los nodos que ya fueron agregados.

Finalmente el problema se resuelve con 1 ejecución de un Floyd-Warshall modificado. Si quisiera calcular todos los caminos mínimos mientras voy sacando nodos, necesitaria |V| ejecuciones del algoritmo.

## Complejidad de la solución
- Complejidad temporal: El grafo tiene V = 2n + 2 nodos y E = O(n + m) aristas. Usando Ford-Fulkerson con BFS, la complejidad es O(V * E^2), lo que da O(n * (n + m)^2).
- Complejidad espacial: Se utilizan matrices de capacidad y flujo de tamaño V x V, lo que requiere O(n^2) espacio.