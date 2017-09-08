template<typename T>
struct DynamicSegmentTree {
  struct Node {
    T val;
    Node *left, *right;

    Node():
      val(T()), left(NULL), right(NULL) {}
    Node(long long _val):
      val(_val), left(NULL), right(NULL) {}
  };

  long long start, end;
  Node *root;

  DynamicSegmentTree(long long _start, long long _end):
    start(_start), end(_end) {
      root = new Node();
    }

  T get(Node *node) {
    if (!node)
      return T();
    return node->val;
  }

  T merge(T val_left, T val_right) {
    return max(val_left, val_right);
  }

  T query(Node *node, long long lo, long long hi, long long from, long long to) {
    if (!node or hi < from or lo > to) {
      return T();
    } else if (lo >= from and hi <= to) {
      return node->val;
    } else {
      int md = (lo + hi) / 2;
      return merge(query(node->left, lo, md, from, to),
                   query(node->right, md + 1, hi, from, to));
    }
  }

  Node *update(Node *node, long long lo, long long hi, long long pos, T val) {
    if (!node) {
      node = new Node();
    }
    if (lo == hi) {
      node->val = val;
    } else {
      int md = (lo + hi) / 2;
      if (pos <= md) {
        node->left = update(node->left, lo, md, pos, val);
      } else {
        node->right = update(node->right, md + 1, hi, pos, val);
      }
      node->val = merge(get(node->left), get(node->right));
    }
    return node;
  }

  //optional
  void update(long long pos, T val) {
    update(root, start, end, pos, val);
  }

  T query(long long from, long long to) {
    return query(root, start, end, from, to);
  }
};
