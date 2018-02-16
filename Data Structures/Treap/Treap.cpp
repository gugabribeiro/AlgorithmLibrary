template <typename T>
struct Treap {
    struct TreapNode {
        T key;
        int priority, size;
        TreapNode *left, *right;
        TreapNode(const T &_key = T()):
            key(_key), priority(rand()), size(1),
            left(NULL), right(NULL) {}
    };

    typedef TreapNode * Node;

    int size;
    Node root;

    Treap() {
        size = 0;
        root = NULL;
        srand(time(NULL));
    }

    int get_size() {
        return size;
    }

    int get_size(Node node) {
        return node ? node->size : 0;
    }

    void update(Node node) {
        if (node) {
            node->size = 1 + get_size(node->left) + get_size(node->right);
        }
    }

    void split(Node node, Node &left, Node &right, T key) {
        if (!node) {
            left = right = NULL;
        } else if (key <= node->key) {
            split(node->left, left, node->left, key);
            right = node;
        } else {
            split(node->right, node->right, right, key);
            left = node;
        }
        update(node);
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
        update(node);
    }

    void insert(const T &key) {
        Node new_node = new TreapNode(key);
        insert(root, new_node);
        ++size;
    }

    void insert(Node &node, Node new_node) {
        if (!node) {
            node = new_node;
        } else if (new_node->priority > node->priority) {
            split(node, new_node->left, new_node->right, new_node->key);
            node = new_node;
        } else {
            insert(new_node->key < node->key ? node->left : node->right, new_node);
        }
        update(node);
    }

    bool erase(const T &key) {
        return erase(root, key);
    }

    bool erase(Node &node, const T &key) {
        bool erased;
        if (!node) {
            erased = false;
        } else if (node->key == key) {
            merge(node, node->left, node->right);
            --size;
            erased = true;
        } else {
            erased = erase(key < node->key ? node->left : node->right, key);
        }
        update(node);
        return erased;
    }

    T operator [] (int at) {
        if (at < 0 or at >= size) { return T(); }
        return get_node(root, at);
    }

    T get_node(Node node, int at, int pos = 0) {
        int cur_pos = pos + get_size(node->left);
        if (at == cur_pos) {
            return node->key;
        } else if (at < cur_pos) {
            return get_node(node->left, at, pos);
        } else {
            return get_node(node->right, at, ++cur_pos);
        }
    }
};
