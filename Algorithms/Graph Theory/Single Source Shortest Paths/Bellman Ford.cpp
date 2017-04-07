const int INF = 1e9;

typedef pair<int, int> edge;
typedef vector<edge> adjacency;

struct BellmanFord {
  vector<adjacency> graph;

  static vector<int> sssp(int n, int source, vector<adjacency>& graph) {
    vector<int> dist(n, INF);
    dist[source] = 0;

    for (int r = 0; r < n - 1; r++) {
      for (int i = 0; i < n; i++) {
        for (edge& e : graph[i]) {
          dist[e.first] = min(dist[e.first], dist[i] + e.second);
        }
      }
    }
    return dist;
  }

  static bool hasNegativeCycle(int n, vector<adjacency>& graph) {
    vector<int> dist = sssp(n, 1, graph);

    for (int i = 0; i < n; i++) {
      for (edge& e : graph[i]) {
        if (dist[e.first] > dist[i] + e.second) {
          return true;
        }
      }
    }
    return false;
  }
};