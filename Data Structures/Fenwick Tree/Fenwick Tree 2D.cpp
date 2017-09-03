struct FencwickTree2D {
  int n, m;
  vector<vector<int>> tree;

  FencwickTree2D() {}
  FencwickTree2D(int _n, int _m) {
    n = 1 + _n; m = 1 + _m;
    tree.assign(n, vector<int>(m, 0));
  }

  int query(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= i & -i) {
      for (int j = y; j; j -= j & -j) {
        res += tree[i][j];
      }
    }
    return res;
  }

  int query(int x_l, int y_l, int x_h, int y_h) {
    return query(x_h, y_h) - query(x_h, y_l - 1) - 
           query(x_l - 1, y_h) + query(x_l - 1, y_l - 1);
  }

  void update(int x, int y, int value) {
    for (int i = x; i < n; i += i & -i) {
      for (int j = y; j < m; j += j & -j) {
        tree[i][j] += value;
      }
    }
  }
};
