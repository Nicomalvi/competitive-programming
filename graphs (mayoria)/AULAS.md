# Aulas

## Enunciado
Los docentes de Intro se organizaron para tomar el parcial en n aulas distintas, pero debido a una confusión en la distribución de los alumnos ahora las aulas están sobrecargadas. Puntualmente, en el aula i se sentaron ai estudiantes, cuando en realidad la misma está pensada únicamente para una cantidad bi.

Se quiere descubrir si es posible reorganizar a los alumnos para que cada aula tenga exactamente bi estudiantes, teniendo en cuenta que no es posible mover alumnos entre ciertas aulas. Puntualmente, se conocen los pares de aulas (p,q) tales que es posible mover a los alumnos del aula p al aula q. Como el parcial está por empezar, cada alumno puede hacer a lo sumo un movimiento. Es decir, un alumno no puede ir del aula p1 a la p2 y luego a la p3.
#### Input

La primera línea de la entrada tiene dos enteros n y m (1≤n≤100, 0≤m≤200) indicando la cantidad de aulas y la cantidad de pares de aulas tales que es posible mover alumnos entre ellas.

La siguiente línea tiene los n valores a1,a2,…,an (0≤ai≤100).

La siguiente, los n valores b1,b2,…,bn (0≤bi≤100).

Finalmente hay m líneas conteniendo cada una dos enteros p y q (1≤p,q≤n, p≠q) indicando que es válido mover alumnos tanto del aula p hacia la q como de la q hacia la p.
#### Output

Si es imposible reorganizar a los alumnos se debe devolver "NO".

Caso contrario, se debe devolver "YES" junto a n lineas adicionales, cada una con n enteros. El j-ésimo número en la i-ésima fila debe indicar cuántos estudiantes del aula i deben moverse al aula j (el i-ésimo número de la i-ésima fila debe indicar cuántos tienen que quedarse en esa aula).

Si hay varias respuestas posibles, cualquiera es válida.

### Example
Input

4 4

1 2 6 3

3 5 3 1

1 2

2 3

3 4

4 2

Output

YES

1 0 0 0 

2 0 0 0 

0 5 1 0 

0 0 2 1 

Input

2 0

1 2

2 1

Output

NO

## Resumen de la solución
El problema lo modelo como una red de flujo: Se divide cada aula en un nodo de donde salen alumnos y otro donde llegan.

Cada aula i tiene una fuente con capacidad ai, mientras que cada aula j tiene un sumidero con capacidad bj. Las aulas que permiten movimientos entre ellas ganan aristas, y existen aristas de aulas hacia ellas mismas para representar a los alumnos que se quedan quietos.

Cada unidad de flujo representa un alumno. Si el flujo máximo es igual a la cantidad total de alumnos, entonces existe una redistribución válida.

## Complejidad de la solución
- Complejidad temporal: El grafo tiene V = 2n + 2 nodos y E = O(n + m) aristas. Usando Ford-Fulkerson con BFS, la complejidad es O(V * E^2), es decir O(n * (n + m)^2).
- Complejidad espacial: Se utilizan matrices de capacidad y flujo de tamaño |V| x |V|, espacio O(n^2).