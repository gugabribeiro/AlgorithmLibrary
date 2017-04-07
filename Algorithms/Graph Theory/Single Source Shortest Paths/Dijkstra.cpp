const int INF = 1e9;

typedef pair<int, int> edge;
typedef vector<edge> adjacency;

struct Dijkstra {
  static vector<int> sssp(int n, int source, vector<adjacency>& graph) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<int> dist(n, INF);

    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
      edge top = pq.top();
      pq.pop();

      int u = top.second;
      if (dist[u] == top.first) {
        for (const edge& e : graph[u]) {
          int v = e.first;
          int w = e.second;

          if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
          }
        }
      }
    }

    return dist;
  }
};