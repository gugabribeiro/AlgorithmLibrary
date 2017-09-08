struct Treap {
  struct TreapNode {
    int key, priority;
    TreapNode *left, right;

    TreapNode() {}
    TreapNode(int _key): 
      key(_key), priority(rand()), 
      left(NULL), right(NULL) {}
  };

  typedef TreapNode * Node;

  void split(Node node, Node &left, Node &right, int key) {
    if (!node) {
      left = right = NULL;
    } else if (key < node->key) {
      split(node->left, left, node->left, key);
      right = node;
    } else {
      split(node->right, node->right, right, key);
      left = node;
    }
  }

  void merge(Node &node, Node left, Node right) {
    if (!left or !right) {
      node = left ? left : right;
    } else if (left->priority > right->priority) {
      merge(left->right, left->right, right);
      node = left;
    } else {
      merge(right->left, left, right->left);
      node = right;
    }
  }

  void insert(Node &node, Node newNode) {
    if (!node) {
      node = newNode;
    } else if (newNode->priority > node->priority) {
      split(node, node->left, node->right, newNode->key);
      node = newNode;
    } else {
      insert(newNode->key < node->key ? node->left : node->right, newNode);
    }
  }

  void erase(Node &node, int key) {
    if (!node) {
      return;
    } else if (node->key == key) {
      merge(node, node->left, node->right);
    } else {
      erase(key < node->key ? node->left : node->right, key);
    }
  }
};
