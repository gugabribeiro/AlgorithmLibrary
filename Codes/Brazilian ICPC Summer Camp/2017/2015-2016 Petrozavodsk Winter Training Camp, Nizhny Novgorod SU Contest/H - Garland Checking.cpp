#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef pair<int, int> ii;

int next_color;
bool mark[N];
int color_size[2 * N];
int loop[N], color[N];
vector<int> graph[N];
vector<ii> passed;

void coloring(int u, int p, int c) {
  color_size[color[u]]--;
  color_size[c]++;

  for (int v : graph[u])
    if (v != p and color[v] == color[u])
      coloring(v, u, c);

  color[u] = c;
}

void parallel_dfs(int u, int v) {
  stack<int> dfs[2];

  dfs[0].push(u); dfs[1].push(v);
  mark[u] = mark[v] = true;

  bool flag = true;
  while (flag) {
    for (int i = 0; i < 2; i++) {
      if (dfs[i].empty()) {
        flag = false;
        continue;
      }

      int u = dfs[i].top();
      mark[u] = true;
      passed.push_back({u, i});

      while (loop[u] < graph[u].size() and (mark[graph[u][loop[u]]] or color[graph[u][loop[u]]] != color[u]))
        loop[u]++;

      if (loop[u] >= graph[u].size())
        dfs[i].pop();
      else {
        dfs[i].push(graph[u][loop[u]]);
      }
    }
  }

  int small = dfs[0].empty() ? 0 : 1;
  for (const ii& i : passed) {
    int u = i.first;
    if (i.second == small) {
      color_size[color[u]]--;
      color[u] = next_color;
      color_size[next_color]++;
    }

    mark[u] = loop[u] = 0;
  }

  dfs[0] = stack<int>();
  dfs[1] = stack<int>();
  passed.clear();
}

int main() {
  int n, id = 0, dfs_id = 0; 
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    color[i] = i;
    color_size[i] = 1;
  }

  next_color = n;

  while (true) {
    char ch;
    scanf(" %c", &ch);

    if (ch == 'E') 
      break;

    int u, v;
    scanf("%d %d", &u, &v);

    if (ch == 'C') {
      if (color_size[color[u]] > color_size[color[v]])
        swap(u, v);

      coloring(u, -1, color[v]);

      graph[u].push_back(v);
      graph[v].push_back(u);
    } else if (ch == 'D') {
      ++next_color; 
      parallel_dfs(u, v);
    } else {  
      printf("%s\n", (color[u] == color[v]) ? "YES" : "NO");
      fflush(stdout);
    }
  }

  return 0;
}