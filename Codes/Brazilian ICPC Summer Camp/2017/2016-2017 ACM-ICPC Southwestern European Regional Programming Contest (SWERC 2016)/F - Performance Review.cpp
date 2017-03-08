#include <bits/stdc++.h>

const int N = 100001;

using namespace std;

typedef long long lint;

int ord[2 * N];
int fst[N], lst[N];
int r[N], cnt; 
lint bit[N];
lint t[N], ans[N];
vector<int> graph[N];

void put(int i, lint v) {
  while (i < N) {
    bit[i] += v;
    i += i & -i;
  }
}

lint get(int i) {
  lint res = 0;
  while (i) {
    res += bit[i];
    i -= i & -i;
  }
  return res;
}

void dfs(int u, int p) {
  ord[cnt++] = u;
  for (int v : graph[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  ord[cnt++] = u;
}

int main() {
  int n, root;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    int m;
    scanf("%d %d %lld", &m, &r[i], &t[i]);

    if (m != -1) {
      graph[m].push_back(i);
      graph[i].push_back(m);
    } else {
      root = i;
    }
  }

  cnt = 1;
  dfs(root, -1);

  for (int i = 1; i < cnt; i++) {
    put(i, t[ord[i]]);
    
    if (!fst[ord[i]]) {
      fst[ord[i]] = i;
    } else {
      lst[ord[i]] = i;
    }
  }

  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", fst[i], lst[i]);
    printf("%lld\n", (get(lst[i] - 1) - get(fst[i])) / 2);
  }

  return 0;
}

/*
5
4 4 80
1 1 40
-1 10 60
3 5 50
4 8 70

2
-1 10 10
1 11 1
*/