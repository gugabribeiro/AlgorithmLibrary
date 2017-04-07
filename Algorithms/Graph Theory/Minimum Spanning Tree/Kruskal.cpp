struct DSU {
  int n;
  vector<int> id, sz;

  void init() {
    for (int i = 0; i < n; i++) {
      id[i] = i;
      sz[i] = 1;
    }
  }

  DSU() {}
  DSU(int n_): 
    n(n_) {
      id.resize(n);
      sz.resize(n);
      init();
    }

  int find_set(int x) {
    if (id[x] == x) {
      return x;
    }
    return id[x] = find_set(id[x]);
  }

  bool same_set(int x, int y) {
    return (find_set(x) == find_set(y));
  }

  bool union_set(int x, int y) {
    x = find_set(x), y = find_set(y);
    
    if (x != y) {
      if (sz[x] > sz[y]) {
        id[y] = x;
        sz[x] += sz[y];
      } else {
        id[x] = y;
        sz[y] += sz[x];
      }
      return true;
    }
    return false;
  }
};

struct edge {
  int u, v, cost;
  
  edge() {}
  edge(int u_, int v_, int cost_):
    u(u_), v(v_), cost(cost_) {}
  
  bool operator < (const edge& other) const {
    return cost < other.cost;
  }
};

struct Kruskal {
  static vector<edge> mst(int n, vector<edge>& edges) {
    DSU dsu(n);
    vector<edge> tree;
    sort(edges.begin(), edges.end());

    for (const edge& e : edges) {
      if (dsu.union_set(e.u, e.v)) {
        tree.push_back(e);
      }
    }
    return tree;
  }
};