#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long lint;
 
const int N = 200100;
const int MOD = 99990001;

struct edge {
  int u, v, value;
} edges[N];

int lazy[N];
bool removed[N];
vector<ii> graph[N];
int component[N], id;

int add(int a, int b) {
  a %= MOD; b %= MOD;
  return (lint(a) + b) % MOD;
}

int mult(int a, int b) {
  a %= MOD; b %= MOD;
  return (lint(a) * b) % MOD;
}

bool mark[N];
int loop[N];
stack<int> dfs[2]; 
stack<int> path[2];

void parallel_dfs(int p) {
  int u = edges[p].u, v = edges[p].v;
  int smallest, min_vtx[] = {N, N};

  dfs[0] = stack<int>(); dfs[1] = stack<int>();
  path[0] = stack<int>(); path[1] = stack<int>();

  dfs[0].push(u);
  dfs[1].push(v);

  mark[u] = mark[v] = true;

  while (!dfs[0].empty() and !dfs[1].empty()) {
    for (int i = 0; i < 2; i++)
      if (dfs[i].empty()) { 
        continue;
    
      int u = dfs[i].top();

      mark[u] = true;
      min_vtx[i] = min(u, min_vtx[i]);

      while (loop[u] < graph[u].size()) {
        int v = graph[u][loop[u]].first;
        int edge_id = graph[u][loop[u]].second;

        if (!mark[v] and !removed[edge_id]) {
          path[i].push(edge_id);  
          dfs[i].push(v);

          break;
        }

        ++loop[u];
      }

      if (loop[u] >= graph[u].size())
        dfs[i].pop();
    }

    //return;
  }

  if (dfs[0].empty() and dfs[1].empty())
    smallest = min_vtx[0] < min_vtx[1] ? 0 : 1;
  else if (dfs[0].empty())
    smallest = 0;
  else
    smallest = 1;

  if (!path[smallest].empty())
    ++id;

  while (!path[smallest].empty()) {
    int e = path[smallest].top();
    path[smallest].pop();

    edges[e].value = add(edges[e].value, lazy[component[e]]);
    edges[e].value = mult(edges[e].value, edges[p].value);
    component[e] = id;

    loop[edges[e].u] = loop[edges[e].v] = 0;
    mark[edges[e].u] = mark[edges[e].v] = 0;
  }

  smallest ^= 1;

  if (!path[smallest].empty()) {
    int e = path[smallest].top();
    lazy[component[e]] = add(lazy[component[e]], edges[p].value);
  }

  while (!path[smallest].empty()) {
    int e = path[smallest].top();
    path[smallest].pop();

    loop[edges[e].u] = loop[edges[e].v] = 0;
    mark[edges[e].u] = mark[edges[e].v] = 0;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i < n; i++) {
    int u, v, value;
    scanf("%d %d %d", &u, &v, &value);

    graph[u].push_back({v, i});
    graph[v].push_back({u, i});

    edges[i] = {u, v, value};
  } 

  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);

    edges[p].value = add(edges[p].value, lazy[component[p]]);

    printf("%d\n", edges[p].value);
    fflush(stdout);

    removed[p] = true;
    parallel_dfs(p);
  }

  return 0;
} 