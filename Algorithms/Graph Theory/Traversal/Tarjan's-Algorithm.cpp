const int N = ...

int low[N], id;
bool marked[N];
vector<int> passed;
vector<int> graph[N];
vector<vector<int>> components;

void dfs(int u) {
  low[u] = ++id;
  marked[u] = true;
  passed.push_back(u);
  bool is_root = true;
  for (int v : graph[u]) {
    if (!marked[v]) {
      dfs(v);
    }
    if (low[u] > low[v]) {
      low[u] = low[v];
      is_root = false;
    }
  }
  if (is_root) {
    vector<int> component;
    while (true) {
      int v = passed.back();
      passed.pop_back();
      component.push_back(v);
      low[v] = INT_MAX;
      if (v == u) {
        break;
      }
    }
    components.push_back(component);
  }
}

void tarjan(int n) {
  for (int i = 0; i < n; ++i) {
    if (!marked[i]) {
      dfs(i);
    }
  }
}
