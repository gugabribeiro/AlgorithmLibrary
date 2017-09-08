const int N = ...

vector<int> graph[N];
int id; bool marked[N];

int num[N], low[N];
vector<int> cut_points, passed;
vector<pair<int, int>> bridges;
vector<vector<int>> components;

void dfs(int u, int p) {
  marked[u] = true;
  low[u] = num[u] = ++id;
  passed.push_back(u);
  int children = 0; 
  bool cut_point = false;
  for (int v : graph[u]) {
    if (v != p) {
      if (marked[v]) {
        low[u] = min(low[u], num[v]);
      } else {
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        cut_point |= (low[v] >= num[u]);
        if (low[v] > num[u]) {
          bridges.push_back({u, v});
        }
        ++children;
      }
    }
  }
  if (p == -1) {
    cut_point = (children >= 2);
  }
  if (cut_point) {
    cut_points.push_back(u);
  }
  if (low[u] == num[u]) {
    vector<int> component;
    while (true) {
      int v = passed.back(); 
      passed.pop_back();
      component.push_back(v);
      if (v == u) {
        break;
      }
    }
    components.push_back(component);
  }
}

void build(int n) {
  fill(low, low + n, -1);
  fill(num, num + n, -1);
  for (int i = 0; i < n; ++i) {
    if (num[i] == -1) {
      passed.clear();
      dfs(i, -1);
    }
  }
}
