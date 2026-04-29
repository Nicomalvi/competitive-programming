# Piezas

## Enunciado
León tiene n piezas robóticas diferentes que tiene que unir que están numeradas del 1 al n. Cada pieza i tiene un número asignado ai. Para unir dos piezas, tiene que pagar un costo. El costo de unir dos piezas x e y es de ax+ay pesos. Sin embargo, León tiene un contacto que le consigue ofertas especiales, por las que puede unir la pieza x e y a un precio w. No es necesario que León use estas ofertas especiales. Si hay un par de piezas x e y que tienen una oferta especial asociada, él puede unir las dos piezas pagando ax+ay pesos por ellas igualmente.

León quisiera que todas las piezas queden conectadas. Es decir, que entre dos piezas cualesquiera, al menos haya un camino de piezas unidas que las conecte. También le gustaría gastar lo mínimo posible. ¿Podrás ayudarlo con esta tarea?

Input

La primera línea contiene dos enteros n y m (1<=n<=210^5, 0<=m<=210^5) — el número de piezas y el número de ofertas especiales, respectivamente.

La segunda línea contiene n enteros a1,a2,...,an (1<=ai<=10^12) — los números asignados a las piezas.

A continuación, siguen m líneas, cada una con tres enteros x, y y w (1<=x,y<=n, 1<=w<=10^12, x!=y) que representan una oferta especial: se puede unir la pieza x con la pieza y con un costo de w monedas.

Output

Imprimí un entero — el número mínimo de pesos que debe pagar León para hacer que las piezas queden todas conectadas.

### Example
Input

3 2

1 3 3

2 3 5

2 1 1

Output

5

Input

4 0

1 3 3 7

Output

16

Input

5 4

1 2 3 4 5

1 2 8

1 3 10

1 4 7

1 5 15

Output

18

## Resumen de la solución
La idea general es simple, lo único complejo es decidir cómo implementarla: En vez de considerar toda combinación de aristas posibles, conecto todos los nodos con el nodo más barato que haya. Luego, conecto también los nodos que son parte de promos más baratas que las aristas normales.
Ahora que tengo un grafo conexo donde sé que existe la solución óptima, ejecuto finalmente el algoritmo de Kruskal para obtener el Árbol Generador Mínimo, que por definición minimiza el costo total de conexión.
## Complejidad de la solución
- Complejidad temporal: Construyo O(n+m) aristas (n conexiones al nodo más barato, m promociones útiles) y luego las ordeno con qsort, lo cual cuesta O((n+m)log(n+m)). El algoritmo de Kruskal recorre esas aristas en tiempo lineal amortizado, complejidad final O((n+m)log(n+m)). 
- Complejidad espacial: Guardo las aristas que conectan todo nodo con el más barato + las m promos, O(n+m).