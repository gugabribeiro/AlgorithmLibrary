const int N = ...

int n; //number of vertices
int heavy[N], parent[N], depth[N];
int index_of[N], value[N], chain[N];

int dfs(int u) { 
  int sz = 1;
  int max_sz = heavy[u] = 0;
  
  for (edge e : graph[u]) {
    int v = e.first;
    if (v != parent[u]) {
      parent[v] = u;
      depth[v] = 1 + depth[u];
      value[v] = e.second;
      int sub_sz = dfs(v);
      if (sub_sz > max_sz) {
        max_sz = sub_sz;
        heavy[u] = v;
      }
      sz += sub_sz;
    }
  }

  return sz;
}

void hld(int u, int &index, int head) {
  index_of[u] = index++;
  update(0, 0, n - 1, index_of[u], value[u]); //remember to implement range ds
  chain[u] = head;
  if (heavy[u]) {
    hld(heavy[u], index, head);
  }
  for (edge e : graph[u]) {
    int v = e.first;
    if (v != heavy[u] and v != parent[u]) {
      hld(v, index, v);
    }
  }
}

int get(int u, int v) {
  int asw = 0;
  while (chain[u] != chain[v]) {
    if (depth[chain[u]] < depth[chain[v]]) 
      swap(u, v);
    asw = max(asw, query(0, 0, n - 1, index_of[chain[u]], index_of[u])); //remember to implement range ds
    u = parent[chain[u]];
    if (u == v) {
      return asw;
    }
  }
  return max(asw, query(0, 0, n - 1, min(index_of[u], index_of[v]) + 1, 
                                     max(index_of[u], index_of[v]))); //remember to implement range ds
}

void push(int u, int v, int cost) {
  if (parent[u] == v) {
    update(0, 0, n - 1, index_of[u], cost); //remember to implement range ds
  } else {
    update(0, 0, n - 1, index_of[v], cost); //remember to implement range ds
  }
}

void build(int root) {
  dfs(root);
  int index = 0;
  hld(root, index, root);
}
