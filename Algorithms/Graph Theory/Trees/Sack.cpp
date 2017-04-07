//O(n log n)
//http://codeforces.com/contest/600/problem/E

#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

const int N = 100010;

int sz[N];
int son[N];
lint color[N];
vector<int> graph[N];

void dfs(int u, int p) {
  sz[u] = 1;
  son[u] = -1;

  int max_sz = 0;
  for (int v : graph[u])
    if (v != p) {
      dfs(v, u);

      sz[u] += sz[v];
      if (sz[v] > max_sz) {
        max_sz = sz[v];
        son[u] = v;
      }
    }
}

int cnt[N];
lint ans[N];
int max_cnt[N];
vector<int>* vis[N];

void update(lint& val, int& freq, lint col) {
  if (freq < cnt[col]) {
    val = col, freq = cnt[col];
  } else if (freq == cnt[col]) {
    val += col;
  }
}

int solve(int u, int p, bool keep) {
  for (int v : graph[u]) {
    if (v != p and v != son[u]) {
      solve(v, u, false);
    }
  }

  if (son[u] == -1) {
    vis[u] = new vector<int>();
  } else {
    solve(son[u], u, true);
    vis[u] = vis[son[u]];

    ans[u] = ans[son[u]];
    max_cnt[u] = max_cnt[son[u]];
  }

  vis[u]->push_back(u);
  ++cnt[color[u]];

  update(ans[u], max_cnt[u], color[u]);

  for (int v : graph[u]) {
    if (v != p and v != son[u]) {
      for (int w : *vis[v]) {
        ++cnt[color[w]];
        update(ans[u], max_cnt[u], color[w]);
        vis[u]->push_back(w);
      }
    }
  }

  if (!keep) {
    for (int v : *vis[u]) {
      --cnt[color[v]];
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    scanf("%lld", &color[i]);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  dfs(1, -1);
  solve(1, -1, false);

  for (int i = 1; i <= n; i++)
    printf("%lld ", ans[i]);
  printf("\n");

  return 0;
}