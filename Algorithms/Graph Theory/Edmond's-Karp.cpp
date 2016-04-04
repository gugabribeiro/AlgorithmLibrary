#include <bits/stdc++.h>

const int V = 1001;

const int INF = INT_MAX / 3;

using namespace std;

vector<int> graph[V]; 

int v;
bool mark[V];
int path[V];
int residualGraph[V][V];
int sink, source;

int augment(int u, int minEdge) {
  if (u == sink) { 
    return minEdge;
  } else {
    minEdge = augment(path[u], min(minEdge, residualGraph[path[u]][u]));
    residualGraph[path[u]][u] -= minEdge;
    residualGraph[u][path[u]] += minEdge;
    return minEdge;
  }
}

bool bfs() {
  queue<int> q;
  for (int i = 0; i < v; i++) {
    mark[i] = false;
    path[i] = -1;
  }
  mark[sink] = true;
  q.push(sink);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == source) {
      return true;
    } else {
      for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (residualGraph[u][v] > 0 && !mark[v]) {
          mark[v] = true;
          path[v] = u;
          q.push(v);
        }
      }
    }
  }
  return false;
}

int EdmondsKarp() {
  int maxFlow = 0;
  while (bfs()) {
    maxFlow += augment(source, INF);
  }
  return maxFlow;
}

int main() {
  int e;
  scanf("%d %d %d %d", &v, &e, &sink, &source);
  while (e--) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    residualGraph[x][y] = w;
    graph[x].push_back(y);
  }
  printf("%d\n", EdmondsKarp());
  return 0;
}
