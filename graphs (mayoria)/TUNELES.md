# Tuneles

## Enunciado
En estos últimos años, Juli estuvo muy ocupado estudiando para exámenes y el concurso de Ay1. Ahora que ya se recibió quiere relajarse y recorrer todo Exactas tranquilo.

Exactas consta de n aulas numeradas del 1 al n. Juli comienza a caminar desde el aula número 1 (en particular, el aula 6 del Pabe II) y sigue alguna secuencia de aulas. Caminar desde el espacio número i hasta otro espacio j requiere |i−j| unidades de energía. La energía total gastada por Juli al visitar una secuencia de aulas e1=1,e2,…,ek es igual a ∑i=1k−1|ei−ei+1| unidades de energía.

Por supuesto, caminar sería aburrido si no hubiera atajos. Un atajo es un túnel oculto que permite a Juli caminar de un aula a otra requiriendo solo 1 unidad de energía. Hay exactamente n atajos en Exactas; el i-ésimo de ellos permite caminar desde el aula i hasta el aula ai (i≤ai≤ai+1) (pero no en la dirección opuesta), por lo tanto, hay exactamente un atajo que comienza en cada aula. Formalmente, si Juli elige una secuencia e1=1,e2,…,ek, entonces para cada 1≤i<k que satisface ei+1=aei y aei≠ei, Juli gastará solo 1 unidad de energía en lugar de |ei−ei+1| al caminar desde el aula ei hasta el aula ei+1. Por ejemplo, si Juli elige una secuencia e1=1,e2=ae1,e3=ae2,…,ek=aek−1, gastará exactamente k−1 unidades de energía total al recorrerlas.

Antes de emprender su aventura, Juli te pide que encuentres la cantidad mínima de energía requerida para alcanzar cada una de las intersecciones desde el aula inicial. Formalmente, para cada 1≤i≤n, Juli está interesado en encontrar la mínima energía total posible de alguna secuencia e1=1,e2,…,ek=i.
#### Input

La primera línea contiene un entero n (1≤n≤200,000) — el número de aulas en Exactas (cambian cada cuatri).

La segunda línea contiene n enteros a1,a2,…,an (i≤ai≤n, ai≤ai+1∀i<n), describiendo los atajos de Exactas, que permiten caminar desde el aula i hasta el aula ai usando solo 1 unidad de energía. Tené en cuenta que los atajos no permiten caminar en dirección opuesta (de ai a i).
#### Output

En la única línea, imprimí n enteros m1,m2,…,mn, donde mi denota la menor cantidad de energía total requerida para caminar desde el aula 1 hasta el aula i.

### Example
Input

3

2 2 3

Output

0 1 2 

Input

5

1 2 3 4 5

Output

0 1 2 3 4 

Input

7

4 4 4 4 7 7 7

Output

0 1 2 1 2 3 3 

Note

En el primer caso de muestra, las secuencias deseadas son:

1:(1); m1=0;
2:(1,2); m2=1;
3:(1,3); m3=|3−1|=2.

En el segundo caso de muestra, la secuencia para cualquier aula 1<i es siempre (1,i) y mi=|1−i|.
En el tercer caso de muestra, unas secuencias posibles son:

1:(1); m1=0;
2:(1,2); m2=|2−1|=1;
3:(1,4,3); m3=1+|4−3|=2;
4:(1,4); m4=1;
5:(1,4,5); m5=1+|4−5|=2;
6:(1,4,6); m6=1+|4−6|=3;
7:(1,4,5,7); m7=1+|4−5|+1=3

## Resumen de la solución
Por cómo se describe el problema la solución obvia es representar el sistema de aulas como un grafo con aristas de un mismo peso/valor:

- Llegar al aula j desde el aula i requiere | i - j | pasos, la misma cantidad de pasos que que el costo de llegar desde el nodo i hasta el j pasando por todo nodo intermmedio.
- La misma distancia requiere 1 solo paso si existe un "atajo", que simplemente sería crear la arista (i, j).

Así es como creo el grafo: todo aula se i se conecta con sus vecinos en ambas direcciones, es decir, creo las aristas (i, i-1), (i-1, i), (i, i+1), (i+1, i). Luego creo los atajos de las aulas i hasta las aulas j, agrego las aristas (i, j).

Una vez que tengo el grafo hecho, saber la distancia mínima desde el aula 1 hasta el resto de las aulas es correr cualquier algoritmo de camino mínimo partiendo desde el nodo 1, por lo que corro un BFS y ya obtengo todas las respuestas.

## Complejidad de la solución
- Complejidad temporal: Construyo la lista de adyacencia agregando para cada nodo sus dos vecinos y su atajo, en O(n). Luego ejecuto BFS, que recorre cada nodo y arista una sola vez, en total: O(n)
- Complejidad espacial: La lista de adyacencia tiene a lo sumo 3 aristas por nodo, y BFS utiliza estructuras auxiliares de tamaño n., en total: O(n)