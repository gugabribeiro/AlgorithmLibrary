#include <bits/stdc++.h>
 
const int N = 10000;
const int LOG = 20;
 
using namespace std;
 
int depth[N];
int parent[N][LOG];
vector<int> tree[N];
 
void dfs(int u, int p) {
  for (int i = 0; i < tree[u].size(); i++) {
    int v = tree[u][i];
    if (v != p) {
      depth[v] = depth[u] + 1;
      parent[v][0] = u;
      dfs(v, u);
    }
  }
}
 
void build(int n) {
  memset(parent, -1, sizeof parent);
  dfs(0, 0);
  for (int j = 1; (1 << j) < n; j++) {
    for (int i = 0; i < n; i++) {
      if (parent[i][j - 1] != -1) {
        parent[i][j] = parent[parent[i][j - 1]][j - 1];
      }
    }
  }
}
 
int getLCA(int u, int v) {
  int l = 1;
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  while (depth[u] >= (1 << l)) {
    l++;
  }
  l--;
  for (int i = l; i >= 0; i--) {
    if (depth[u] - (1 << i) >= depth[v]) {
      u = parent[u][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = l; i >= 0; i--) {
    if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  return parent[u][0];
}
 
int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      tree[i].clear();
      int k;
      scanf("%d", &k);
      while (k--) {
        int u;
        scanf("%d", &u); u--;
        tree[i].push_back(u);
        tree[u].push_back(i);
      }
    }
    build(n);
    int q;
    scanf("%d", &q);
    printf("Case %d:\n", tc);
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      printf("%d\n", getLCA(u - 1, v - 1) + 1);
    }
  }
  return 0;
}
