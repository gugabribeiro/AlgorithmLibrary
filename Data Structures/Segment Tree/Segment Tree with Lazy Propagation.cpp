struct LazySegmentTree {
  struct Node {
    int value, lazy; //node attributes

    Node() {}
    Node(int value_):
      value(value_), lazy(0) {}

    Node operator + (const Node& other) {
      return Node(value + other.value);
    }
  };

  int n;
  Node neutral = Node(0); //neutral element
  vector<Node> tree;

  void build(const vector<int>& base, int id, int left, int right) {
    if (left == right) {
      tree[id].value = base[left];
    } else {
      int mid = (left + right) / 2;
      build(base, 2 * id + 1, left, mid);
      build(base, 2 * id + 2, mid + 1, right);
      tree[id] = tree[2 * id + 1] + tree[2 * id + 2];
    }
  }

  LazySegmentTree() {}
  LazySegmentTree(int n_, const vector<int>& base):
    n(n_) {
      tree.resize(4 * n);
      build(base, 0, 0, n - 1);
    }

  //pay attention to this procedure
  void doLazy(int id, int left, int right) {
    if (tree[id].lazy) { 
      tree[id].value += (right - left + 1) * tree[id].lazy;
      if (left != right) {
        tree[2 * id + 1].lazy += tree[id].lazy;
        tree[2 * id + 2].lazy += tree[id].lazy;
      }
      tree[id].lazy = 0;
    }
  }

  Node query(int id, int left, int right, int from, int to) {
    doLazy(id, left, right);
    if (right < from or left > to) {
      return neutral;
    } else if (left >= from and right <= to) {
      return tree[id];
    } else {
      int mid = (left + right) / 2;
      return query(2 * id + 1, left, mid, from, to) + 
             query(2 * id + 2, mid + 1, right, from, to);
    }
  }

  Node query(int from, int to) {
    return query(0, 0, n - 1, from, to);
  }

  void update(int id, int left, int right, int from, int to, int value) {
    doLazy(id, left, right);
    if (right < from or left > to) {
      return;
    } else if (left >= from and right <= to) {
      tree[id].lazy += value;
      doLazy(id, left, right);
    } else {
      int mid = (left + right) / 2;
      update(2 * id + 1, left, mid, from, to, value);
      update(2 * id + 2, mid + 1, right, from, to, value);
      tree[id] = tree[2 * id + 1] + tree[2 * id + 2];
    }
  }

  void update(int from, int to, int value) {
    update(0, 0, n - 1, from, to, value);
  }
};