#include <bits/stdc++.h>

const int N = 30010;

using namespace std;

typedef long long lint;

struct Edge {
  int u, v, resistence, i;
  lint cost;

  bool operator < (const Edge& other) const {
    if (resistence == other.resistence)
      return cost > other.cost;
    else
      return resistence > other.resistence;
  }
} e[N];

int pos;
map<int, int> id;

void add(int x) {
  if (!id.count(x))
    id[x] = ++pos;
}

int parent[N];

int find_set(int x) {
  if (parent[x] == x) 
    return x;
  return parent[x] = find_set(parent[x]);
}

bool union_set(int x, int y) {
  x = find_set(x), y = find_set(y);

  if (x != y) {
    parent[x] = y;
    return true;
  }

  return false;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int u, v, resistence;
    lint cost;
    scanf("%d %d %d %lld", &u, &v, &resistence, &cost);

    add(u), add(v);
    e[i] = {id[u], id[v], resistence, i + 1, cost};
  }

  lint ans = 0;
  sort(e, e + n); 

  for (int i = 1; i <= pos; i++)
    parent[i] = i;

  for (int i = 0; i < n; i++) {
    int u = e[i].u, v = e[i].v;
    lint cost = e[i].cost;

    if (union_set(u, v))
      ans += cost;
  }

  printf("%lld\n", ans);
  for (int i = n - 1; i >= 0; i--) {
    if (i != n - 1)
      printf(" ");
    printf("%d", e[i].i);
  }
  printf("\n");

  return 0;
}