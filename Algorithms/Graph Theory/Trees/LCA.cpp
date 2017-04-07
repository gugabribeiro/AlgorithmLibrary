//O(n * log n)
//http://www.spoj.com/problems/LCA/

#include <bits/stdc++.h>

using namespace std;

//const int INF = 1e9;
const int LOG = 20;
const int N = 100010;

typedef pair<int, int> edge;

int level[N];
//int rmq[N][LOG];
int parent[N][LOG];
vector<edge> graph[N];

void dfs(int u, int p) {
  for (const edge& e : graph[u]) {
    int v = e.first;
    int w = e.second;

    if (v != p) {
      //rmq[v][0] = w;
      parent[v][0] = u;
      level[v] = level[u] + 1;

      dfs(v, u);
    }
  }
}

void build_lca(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; (1 << j) < n; j++) {
      //rmq[i][j] = INF;
      parent[i][j] = -1;
    }
  }

  dfs(0, -1);

  for (int j = 1; (1 << j) < n; j++) {
    for (int i = 0; i < n; i++) {
      if (parent[i][j - 1] != -1) {
        parent[i][j] = parent[parent[i][j - 1]][j - 1];
        //rmq[i][j] = min(rmq[i][j], rmq[parent[i][j - 1]][j - 1]);
      }
    }
  }
}

int get_lca(int u, int v) {
  int lg = 1;//, res = INF;

  if (level[u] < level[v]) {
    swap(u, v);
  }

  while ((1 << lg) <= level[u]) {
    ++lg;
  }
  --lg;

  for (int i = lg; i >= 0; i--) {
    if (level[u] - (1 << i) >= level[v]) {
      //res = min(res, rmq[u][i]);
      u = parent[u][i];
    }
  }

  if (u == v) {
    //return res;
    return u;
  }

  for (int i = lg; i >= 0; i--) {
    if (parent[u][i] != -1 and parent[u][i] != parent[v][i]) {
      //res = min(res, min(rmq[u][i], rmq[v][i]));
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  //return min(res, min(rmq[u][0], rmq[v][0]));
  return parent[u][0];
}

int main() {
  int t;
  scanf("%d", &t);
  
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
      graph[i].clear();

      int m;
      scanf("%d", &m);
      
      while (m--) {
        int u;
        scanf("%d", &u);
        --u;

        graph[u].push_back({i, 0});
        graph[i].push_back({u, 0});
      }
    }

    printf("Case %d:\n", tc);
      
    build_lca(n);

    int q;
    scanf("%d", &q);
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      printf("%d\n", get_lca(u - 1, v - 1) + 1);
    }
  }

  return 0;
} 