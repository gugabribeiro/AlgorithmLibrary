const int N = ...
const int INF = ...

typedef pair<int, int> edge;

vector<edge> graph[N];

vector<int> spfa(int n, int source) {
  vector<int> dist(n, INF);
  queue<int> q;
  vector<bool> in_queue(n, false);
  dist[source] = 0;
  q.push(source);
  in_queue[source] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    in_queue[u] = false;
    for (edge e : graph[u]) {
      int v = e.first, w = e.second;
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        if (!in_queue[v]) {
          q.push(v);
          in_queue[v] = true;
        }
      }
    }
  }
  return dist;
}
