#include <bits/stdc++.h>

const int N = 500;

using namespace std;

bool mark[N];
int match[N];
vector<int> graph[N];

int alternate(int u) {
  if (mark[u]) {
    return 0;
  }
  mark[u] = true;
  for (int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (match[v] == -1 || alternate(match[v])) {
      match[v] = u;
      return 1;
    }
  }
  return 0;
}

int main() {
  int v, e;
  scanf("%d %d", &v, &e);
  while (e--) {
    int x, y;
    scanf("%d %d", &x, &y);
    graph[x].push_back(y);
  }
  int mcbm = 0;
  memset(match, -1, sizeof match);
  for (int i = 0; i < v; i++) {
    memset(mark, false, sizeof mark);
    mcbm += alternate(i);
  }
  printf("%d\n", mcbm);
  return 0;
}
