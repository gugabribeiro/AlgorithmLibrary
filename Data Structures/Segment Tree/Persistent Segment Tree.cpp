struct PersistentSegmentTree {
  struct Node {
    int len, maxOnes, prefOnes, sufOnes;
    Node* left; Node* right;

    Node() {}
    Node(int value):
      len(1), maxOnes(value), prefOnes(value), sufOnes(value),
      left(NULL), right(NULL) {}

    Node operator + (const Node& other) {
      Node res;
      res.len = len + other.len;
      res.maxOnes = max({maxOnes, other.maxOnes, sufOnes + other.prefOnes});
      res.prefOnes = (prefOnes == len) ? len + other.prefOnes : prefOnes;
      res.sufOnes = (other.sufOnes == other.len) ? other.len + sufOnes : other.sufOnes;
      return res;
    }
  };

  int n;
  Node* neutral = new Node(0);
  vector<Node*> roots;

  Node* build(int left, int right) {
    Node* newNode = new Node(0);
    if (left != right) {
      int mid = (left + right) / 2;
      newNode->left = build(left, mid);
      newNode->right = build(mid + 1, right);
    }
    return newNode;
  }

  PersistentSegmentTree() {}
  PersistentSegmentTree(int n_): 
    n(n_) {
      roots.resize(n + 1); //main root + root for every tree
      roots[0] = build(0, n - 1);
    }

  Node query(Node* node, int left, int right, int from, int to) {
    if (right < from or left > to) {
      return *neutral;
    } else if (left >= from and right <= to) {
      return *node;
    } else {
      int mid = (left + right) / 2;
      return query(node->left, left, mid, from, to) + query(node->right, mid + 1, right, from, to);
    }
  }

  Node query(int tree_id, int from, int to) {
    return query(roots[tree_id], 0, n - 1, from, to);
  }

  Node* update(Node* node, int left, int right, int pos) {
    Node* newNode = new Node(1);
    if (left != right) {
      int mid = (left + right) / 2;
      if (pos <= mid) {
        newNode->left = update(node->left, left, mid, pos);
        newNode->right = node->right;
      } else {
        newNode->left = node->left;
        newNode->right = update(node->right, mid + 1, right, pos);
      }
      Node aux = (*newNode->left) + (*newNode->right);
      newNode->len = aux.len; newNode->maxOnes = aux.maxOnes;
      newNode->prefOnes = aux.prefOnes; newNode->sufOnes = aux.sufOnes;
    }
    return newNode;
  }

  void update(int tree_id, int pos) {
    roots[tree_id] = update(roots[tree_id - 1], 0, n - 1, pos);
  }
};