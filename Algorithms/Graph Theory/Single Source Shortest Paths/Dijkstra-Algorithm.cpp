const int N = ...
const int INF = ...

typedef pair<int, int> edge;

vector<edge> graph[N];

vector<int> dijkstra(int n, int source) {
  vector<int> dist(n, INF);
  priority_queue<edge, vector<edge>, greater<edge>> q;
  dist[source] = 0;
  q.push({0, source});
  while (!q.empty()) {
    edge top = q.top(); q.pop();
    int u = top.second;
    if (top.first == dist[u]) {
      for (edge e : graph[u]) {
        int v = e.first, w = e.second;
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          q.push({v, dist[v]});
        }
      }
    }
  }
  return dist;
}
