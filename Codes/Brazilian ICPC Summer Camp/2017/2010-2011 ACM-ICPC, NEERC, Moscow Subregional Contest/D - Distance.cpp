#include <bits/stdc++.h>

const int N = 100001;
const int INF = 2e9;

using namespace std;

typedef pair<int, int> edge;

int start[N];
int color[N], dist[N];
vector<edge> graph[N];
vector<pair<int, edge>> edges;

void dijkstra(int n) {
  priority_queue<edge, vector<edge>, greater<edge>> pq;

  for (int i = 1; i <= n; i++) {
    if (color[i]) {
      pq.push({0, i});
    } else {
      dist[i] = INF;
    }
  }

  while (!pq.empty()) {
    edge t = pq.top();
    pq.pop();

    if (dist[t.second] == t.first) {
      int u = t.second;

      for (const auto &e : graph[u]) {
        int v = e.first, w = e.second;
        if (dist[u] + w < dist[v]) {
          color[v] = color[u];
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
        }
      }
    }
  }
}

int solve(int n) {
  int res = INF;

  dijkstra(n);
  for (const auto& e : edges) {
    int u = e.second.first, v = e.second.second;

    if (color[u] != color[v]) {
      res = min(res, dist[u] + e.first + dist[v]);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);

  int n, p, m;
  cin >> p >> n >> m;

  for (int i = 1; i <= p; i++) {
    cin >> start[i];

    if (color[start[i]]) {
      cout << 0 << endl;
      return 0;
    } else {
      color[start[i]] = i;
    }
  }

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;

    edges.push_back({w, {u, v}});

    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  cout << solve(n) * 3 << endl;

  return 0;
}
