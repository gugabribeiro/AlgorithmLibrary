struct ImplicitSegmentTree {
  struct Node {
    lint value;
    Node* left; Node* right;

    Node(): 
      value(0), left(NULL), right(NULL) {}
    Node(lint value_):
      value(value_), left(NULL), right(NULL) {}
  };

  lint start, end;
  Node* root;

  ImplicitSegmentTree(lint start_, lint end_):
    start(start_), end(end_) {
      root = new Node();
    }

  lint get(Node* node) {
    if (!node) {
      return 0;
    }
    return node->value;
  }

  lint merge(lint val_left, lint val_right) {
    return max(val_left, val_right);
  }

  lint query(Node* node, int left, int right, int from, int to) {
    if (!node or right < from or left > to) {
      return 0;
    } else if (left >= from and right <= to) {
      return node->value;
    } else {
      int mid = (left + right) / 2;
      return merge(query(node->left, left, mid, from, to), 
                   query(node->right, mid + 1, right, from, to));
    }
  }

  lint query(int from, int to) {
    return query(root, start, end, from, to);
  }

  Node* update(Node* node, int left, int right, int pos, lint value) {
    if (!node) {
      node = new Node();
    } 
    if (left == right) {
      node->value = value;
    } else {
      int mid = (left + right) / 2;
      if (pos <= mid) {
        node->left = update(node->left, left, mid, pos, value);
      } else {
        node->right = update(node->right, mid + 1, right, pos, value);
      }
      node->value = merge(get(node->left), get(node->right));
    }
    return node;
  }

  void update(int pos, lint value) {
    update(root, start, end, pos, value);
  }
};