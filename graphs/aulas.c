#include <stdio.h>

#define A 0
#define B 1
#define C 2
#define MAX_NODES 300
#define O 1000000000

long n;
long e;
long capacity[MAX_NODES][MAX_NODES];
long flow[MAX_NODES][MAX_NODES];
long color[MAX_NODES];
long pred[MAX_NODES];

// implementaciones comunes BFS, ford fulkerson

long min(long x, long y) {
  return x < y ? x : y;
}

long head, tail;
long q[MAX_NODES + 2];

void enqueue(long x) {
  q[tail] = x;
  tail++;
  color[x] = B;
}

long dequeue() {
  long x = q[head];
  head++;
  color[x] = C;
  return x;
}

long bfs(long start, long target) {
  long u, v;
  for (u = 0; u < n; u++) {
    color[u] = A;
  }
  head = tail = 0;
  enqueue(start);
  pred[start] = -1;
  while (head != tail) {
    u = dequeue();
    for (v = 0; v < n; v++) {
      if (color[v] == A && capacity[u][v] - flow[u][v] > 0) {
        enqueue(v);
        pred[v] = u;
      }
    }
  }
  return color[target] == C;
}

long fordFulkerson(long source, long sink) {
  long i, j, u;
  long max_flow = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      flow[i][j] = 0;
    }
  }

  while (bfs(source, sink)) {
    long increment = O;
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]);
    }
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      flow[pred[u]][u] += increment;
      flow[u][pred[u]] -= increment;
    }
    max_flow += increment;
  }
  return max_flow;
}


long main() {
    long m;
    long A_total;
    long B_total;
    scanf("%ld %ld ", &n, &m);

    long aulasA[n];
    long aulasB[n];

    for (long i = 0; i<n; i++){
        scanf("%ld", &aulasA[i]);
        A_total = A_total + aulasA[i];
    }
    for (long i = 0; i<n; i++){
        scanf("%ld", &aulasB[i]);
        B_total = B_total + aulasB[i];
    }
    for(long i = 1; i<=n; i++){
        capacity[0][i] = aulasA[i-1];
        capacity[i+n][2*n+1] = aulasB[i-1];
    }
    for(long i = 1; i<=n; i++){
        capacity[i][n+i] = 99999;
    }

    for (long i = 0; i<m; i++){
        long v,w;
        scanf("%ld %ld", &v, &w);
        capacity[v][w+n] = 99999;
        capacity[w][v+n] = 99999;
    }

    long n_original = n;
    n = 2*n + 2;
    long res = fordFulkerson(0, n-1);
    if(res!=A_total){
        printf("NO\n");
        return 0;
    }
    if(B_total!=A_total){
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for(long i=1;i<=n_original;i++){
            for(long j=1;j<=n_original;j++){
                printf("%ld ", flow[i][j+n_original]);
            }
            printf("\n");
    }
    return 0;
    //aaaa
}