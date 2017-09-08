const int N = ...

vector<int> graph[N];
int sz[N], best_son[N];

void dfs(int u, int p) {
  sz[u] = 1; best_son[u] = -1;
  int max_sz = 0;
  for (int v : graph[u]) {
    if (v != p) {
      dfs(v, u);
      if (sz[v] > max_sz) {
        max_sz = sz[v];
        best_son[u] = v;
      }
      sz[u] += sz[v];
    }
  }
}

vector<int> *vis[N];

void update(int u) {
  //do something to update values of vertex u 
}

int sack(int u, int p, bool keep = false) {
  for (int v : graph[u]) {
    if (v != p and v != best_son[u]) {
      sack(v, u, false);
    }
  }
  if (best_son[u] == -1) {
    vis[u] = new vector<int>();
  } else {
    sack(best_son[u], u, true);
    vis[u] = vis[best_son[u]];
  }
  vis[u]->push_back(u);
  update(u);
  for (int v : graph[u]) {
    if (v != p and v != best_son[u]) {
      for (int w : *vis[v]) {
        update(w);
        vis[u]->push_back(w);
      }
    }
  }
  //at this time, vis[u] has all nodes of the subtree rooted in u
  if (!keep) {
    for (int v : *vis[u]) {
      //remove information about all subtree nodes
    }
  }
}
