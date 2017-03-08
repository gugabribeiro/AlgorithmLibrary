#include <bits/stdc++.h>

const int N = 100010;

using namespace std;

vector<int> tree[N];

int pos[N];
int parent[N], heavy[N];
int depth[N], pathRoot[N];

int dfs(int u) {
  int sz = 1;
  int maxSubtree = 0;

  for (int v : tree[u]) {
    if (v != parent[u]) {
      parent[v] = u;
      depth[v] = depth[u] + 1;

      int subtree = dfs(v);
      if (maxSubtree < subtree) {
        maxSubtree = subtree;
        heavy[u] = v;
      }
      sz += subtree;
    }
  }
  return sz;
}

void HeavyLight(int n) {
  for (int i = 0; i < n; i++) {
    pos[i] = parent[i] = depth[i] = pathRoot[i] = 0;
    heavy[i] = -1;
  }

  parent[0] = -1;
  dfs(0);

  for (int u = 0, p = 0; u < n; u++) {
    if (parent[u] == -1 or heavy[parent[u]] != u) {
      for (int v = u; v != -1; v = heavy[v]) {
        pathRoot[v] = u;
        pos[v] = p++;
      }
    }
  }
}

typedef long long lint;

lint st[4 * N];

void update(int id, int l, int r, int p, lint v) {
  if (l == r) {
    st[id] += v;
  } else {
    int md = (l + r) / 2;
    if (p <= md) {
      update(2 * id, l, md, p, v);
    } else {
      update(2 * id + 1, md + 1, r, p, v);
    }
    st[id] = max(st[2 * id], st[2 * id + 1]);
  }
}

lint query(int id, int l, int r, int i, int j) {
  if (r < i or l > j) {
    return 0;
  } else if (l >= i and r <= j) {
    return st[id];
  } else {
    int md = (l + r) / 2;
    return max(query(2 * id, l, md, i, j), query(2 * id + 1, md + 1, r, i, j));
  }
}

lint solve(int u, int v, int n) {
  lint res = 0;
  while (pathRoot[u] != pathRoot[v]) {
    if (depth[pathRoot[u]] > depth[pathRoot[v]]) {
      swap(u, v);
    }
    res = max(res, query(1, 0, n - 1, pos[pathRoot[v]], pos[v]));
    v = parent[pathRoot[v]];
  }
  if (depth[u] > depth[v]) {
    swap(u, v);
  }
  return max(res, query(1, 0, n - 1, pos[u], pos[v]));
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  HeavyLight(n);

  int q;
  scanf("%d", &q);
  while (q--) {
    char t; int u; lint v;
    scanf(" %c %d %lld", &t, &u, &v);

    if (t == 'I') {
      update(1, 0, n - 1, pos[u - 1], v);
    } else {
      printf("%lld\n", solve(u - 1, v - 1, n));
    }
  }

  return 0;
}