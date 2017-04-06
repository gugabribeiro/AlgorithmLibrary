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