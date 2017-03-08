#include <bits/stdc++.h>

using namespace std;

//O(V ^ 2 * E)
struct Dinitz {
  const static int INF = (int)1e9;
  const static int N = 510;
  
  struct edge {
    int to, rev, cap, flow;
    edge(int to, int rev, int cap, int flow):
      to(to), rev(rev), cap(cap), flow(flow) {}
  };
  
  vector<edge> graph[N];
  int dist[N], pos[N];
  int sink, source, n;
  
  Dinitz(int source_, int sink_, int n_):
    source(source_), sink(sink_), n(n_) {}

  void addEdge(int u, int v, int uv, int vu = 0) {
    edge a = {v, (int) graph[v].size(), uv, 0};
    edge b = {u, (int) graph[u].size(), vu, 0};

    graph[u].push_back(a);
    graph[v].push_back(b);
  }

  void clear() {
    for (int i = 0; i < n; i++)
      graph[i].clear();
  }
  
  bool bfs() {
    queue<int> q;
    for (int i = 0; i < n; i++)
      dist[i] = -1;

    q.push(source);
    dist[source] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int i = 0; i < graph[u].size(); i++) {
        edge e = graph[u][i];

        if (dist[e.to] == -1 && e.cap > e.flow) {
          dist[e.to] = dist[u] + 1;
          q.push(e.to);
        }
      }
    }

    return dist[sink] != -1;
  }
  
  int dfs(int u, int minEdge) {
    if (!minEdge) 
      return 0;

    if (u == sink) 
      return minEdge;

    for (; pos[u] < graph[u].size(); pos[u]++) {
      edge &e = graph[u][pos[u]];

      if (dist[u] + 1 == dist[e.to]) {
        int flow = dfs(e.to, min(minEdge, e.cap - e.flow));

        if (flow) {
          e.flow += flow;
          graph[e.to][e.rev].flow -= flow;
          return flow;
        }
      }
    }

    return 0;
  }
  
  long long getMaxFlow() {
    long long maxFlow = 0;

    while (bfs()) {
      for (int i = 0; i < n; i++)
        pos[i] = 0;

      while (int flow = dfs(source, INF))
        maxFlow += (long long)flow; 
    }

    return maxFlow;
  }
};

int main() {
  return 0;
}