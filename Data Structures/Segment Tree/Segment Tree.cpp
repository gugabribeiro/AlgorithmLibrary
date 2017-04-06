struct SegmentTree {
  struct Node {
    int value; //node attributes

    Node() {}
    Node(int value_): 
      value(value_) {}

    //merge operator
    Node operator + (const Node& other) {
      return Node(value + other.value);
    }
  };

  int n;
  Node neutral = Node(0); // neutral element
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

  SegmentTree() {}
  SegmentTree(int n_, const vector<int>& base):
    n(n_) {
      tree.resize(4 * n);
      build(base, 0, 0, n - 1);
    }

  Node query(int id, int left, int right, int from, int to) {
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

  void update(int id, int left, int right, int pos, int value) {
    if (left == right) {
      tree[id].value = value;
    } else {
      int mid = (left + right) / 2;
      if (pos <= mid) {
        update(2 * id + 1, left, mid, pos, value);
      } else {
        update(2 * id + 2, mid + 1, right, pos, value);
      }
      tree[id] = tree[2 * id + 1] + tree[2 * id + 2];
    }
  }

  void update(int pos, int value) {
    update(0, 0, n - 1, pos, value);
  }
};