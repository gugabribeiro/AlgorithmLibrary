#include <bits/stdc++.h>

const int N = 10010;

using namespace std;

int n, cnt;
int num[N], low[N];

typedef pair<int, int> edge;

vector<int> graph[N];
vector<vector<int>> components;
stack<edge> pilha;

void dfs(int u, int p) {
  num[u] = low[u] = ++cnt;
  int children = 0;

  for (int v : graph[u]) {
    if (num[v] == -1) {
      ++children;
      pilha.push({u, v});

      dfs(v, u);

      low[u] = min(low[u], low[v]);

      if ((p == -1 and children > 1) or
          (p != -1 and low[v] >= num[u])) {
        vector<int> component;

        while (!pilha.empty()) {
          int x = pilha.top().first; 
          int y = pilha.top().second;

          component.push_back(x);
          component.push_back(y);

          pilha.pop();

          if (x == u and y == v)
            break;
        }

        sort(component.begin(), component.end());
        component.resize(distance(component.begin(), unique(component.begin(), component.end())));
          
        components.push_back(component);
      }
    } else if (v != p and num[v] < low[u]) {
      low[u] = num[v];
      pilha.push({u, v});
    }
  } 
}

void dfsUtil(int n) {
  components.clear();
  pilha = stack<edge>();

  for (int i = 1; i <= n; i++)
    num[i] = low[i] = -1;

  cnt = 0;

  for (int i = 1; i <= n; i++) {
    if (num[i] == -1) {
      dfs(i, -1);

      vector<int> component;

      while (!pilha.empty()) {
        component.push_back(pilha.top().first);
        component.push_back(pilha.top().second);
        pilha.pop();
      }

      sort(component.begin(), component.end());
      component.resize(distance(component.begin(), unique(component.begin(), component.end())));

      components.push_back(component);
    }
  }
}

int main() {
  return 0;
}