#include <bits/stdc++.h>

const int N = 1001;
const int INF = INT_MAX / 3;

using namespace std;

typedef pair<int, int> edge;

vector<edge> graph[N];
int dist[N];

void bellmanFord(int s, int n) {
  for (int i = 1; i <= s; i++) {
    dist[i] = INF;
  }
  dist[s] = 0;
  
  for (int r = 0; r < n - 1; r++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < graph[i].size(); j++) {
        int v = graph[i][j].first;
        int w = graph[i][j].second;
        dist[v] = min(dist[v], dist[i] + w);
      }
    }
  }
}

bool hasNegativeCycle(int n) {
  bellmanFord(1, n);
  
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < graph[i].size(); i++) {
      int v = graph[i][j].first;
      int w = graph[i][j].second;
      if (dist[v] > dist[u] + w) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  return 0;
}
