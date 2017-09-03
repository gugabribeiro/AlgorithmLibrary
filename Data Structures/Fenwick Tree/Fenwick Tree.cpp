struct FenwickTree {
  int n;
  vector<int> tree;

  FenwickTree() {}
  FenwickTree(int n_) {
    n = 1 + _n;
    tree.resize(n);
  }

  int query(int i) {
    int res = 0;
    while (i) {
      res += tree[i];
      i -= i & -i;
    } 
    return res;
  }

  int query(int from, int to) {
    return query(to) - query(from - 1);
  }

  void update(int i, int value) {
    while (i < n) {
      tree[i] += value;
      i += i & -i;
    }
  }
};
