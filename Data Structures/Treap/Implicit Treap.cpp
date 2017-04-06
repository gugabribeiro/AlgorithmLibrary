struct ImplicitTreap {
  struct TreapNode {
    int key, priority, size;
    TreapNode* left; TreapNode* right;

    TreapNode() {}
    TreapNode(int key_):
      key(key_), priority(rand()), size(1),
      left(NULL), right(NULL) {}
  };

  typedef TreapNode* Node;

  int getSize(Node node) {
    if (!node) {
      return 0;
    }
    return node->size;
  }

  void update(Node node) {
    if (node) {
      node->size = 1 + getSize(node->left) + getSize(node->right);
    }
  }

  void split(Node node, Node& left, Node& right, int key, int pos = 0) {
    if (!node) {
      left = right = NULL; 
      return;
    }
    int cur_pos = pos + getSize(node->left);
    if (key <= cur_pos) {
      split(node->left, left, node->left, key, add);
      right = node;
    } else {
      split(node->right, node->right, right, 1 + cur_pos);
      left = node;
    }
    update(node);
  }

  void merge(Node& node, Node left, Node right) {
    if (!left or !right) {
      node = left ? left : right;
    } else if (left->priority > right->priority) {
      merge(left->right, left->right, right);
      node = left;
    } else {
      merge(right->left, left, right->left);
      node = right;
    }
    update(node);
  }
};