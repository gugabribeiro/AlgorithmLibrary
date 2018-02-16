template <typename T>
struct ImplicitTreap {
    struct TreapNode {
        T value;
        int priority, size;
        TreapNode *left, *right;
        TreapNode(const T &_value = T()):
            value(_value), priority(rand()), size(1),
            left(NULL), right(NULL) {}
    };

    typedef TreapNode * Node;

    int size;
    Node root;

    ImplicitTreap() {
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

    void split(Node node, Node &left, Node &right, int at, int pos = 0) {
        if (!node) {
            left = right = NULL;
            return;
        }
        int cur_pos = pos + get_size(node->left);
        if (at <= cur_pos) {
            split(node->left, left, node->left, at, pos);
            right = node;
        } else {
            split(node->right, node->right, right, at, ++cur_pos);
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

    void insert(const T &value) {
        insert(value, get_size());
    }

    void insert(const T &value, int at) {
        Node new_node = new TreapNode(value);
        Node left_tree, right_tree;
        split(root, left_tree, right_tree, at);
        merge(left_tree, left_tree, new_node);
        merge(root, left_tree, right_tree);
        ++size;
    }

    void erase(int at) {
        if (size) {
            Node left_tree, right_tree;
            split(root, left_tree, right_tree, at);
            Node erased;
            split(right_tree, erased, right_tree, 1);
            merge(root, left_tree, right_tree);
            free(erased);
            --size;
        }
    }

    T operator [] (int at) {
        if (at < 0 or at >= size) { return T(); }
        return get_node(root, at);
    }

    T get_node(Node node, int at, int pos = 0) {
        int cur_pos = pos + get_size(node->left);
        if (at == cur_pos) {
            return node->value;
        } else if (at < cur_pos) {
            return get_node(node->left, at, pos);
        } else {
            return get_node(node->right, at, ++cur_pos);
        }
    }
};
