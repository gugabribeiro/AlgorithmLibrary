#include <bits/stdc++.h>

const int V = 1001;
const int INF = INT_MAX / 3;

using namespace std;

int v;
int residualGraph[V][V];
bool mark[V];
int path[V];
int sink, source;

int augment(int u, int minEdge) {
  if (u == source) {
    return minEdge;
  } else {
    minEdge = augment(path[u], min(minEdge, residualGraph[u][path[u]]));
    residualGraph[u][path[u]] -= minEdge;
    residualGraph[path[u]][u] += minEdge;
    return minEdge;
  }
}

bool dfs(int u) {
  if (u == source) {
    return true;
  }
  if (mark[u]) {
    return false;
  }
  mark[u] = true;
  for (int i = 0; i < v; i++) {
    if (residualGraph[u][i] > 0 && dfs(i)) {
      path[u] = i;
      return true;
    }
  }
  return false;
}

int FordFulkerson() {
  int maxFlow = 0;
  
  while (true) {
    for (int i = 0; i < v; i++) {
      mark[i] = false;
      path[i] = -1;
    }
    if (!dfs(sink)) {
      return maxFlow;
    }
    maxFlow += augment(sink, INF);
  }
}

int main() {
  int e;
  scanf("%d %d %d %d", &v, &e, &sink, &source);
  
  while (e--) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    residualGraph[x][y] += w;
  }
  
  printf("%d\n", FordFulkerson());
  
  return 0;
}
