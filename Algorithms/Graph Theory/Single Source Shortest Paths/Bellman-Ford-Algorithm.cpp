const int N = ...
const int INF = ...

typedef pair<int, int> edge;

vector<edge> graph[N];

vector<int> bellman_ford(int n, int source) {
  vector<int> dist(n, INF);
  dist[source] = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int u = 0; u < n; ++u) {
      for (edge e : graph[u]) {
        int v = e.first, w = e.second;
        dist[v] = min(dist[v], dist[u] + w);
      }
    }
  }
  return dist;
}

//negative_cycle(n, bellman_ford(n, source));
bool negative_cycle(int n, vector<int> &dist) {
  for (int u = 0; u < n; ++u) {
    for (edge e : graph[u]) {
      int v = e.first, w = e.second;
      if (dist[v] > dist[u] + w) {
        return true;
      }
    }
  }
  return false;
}
