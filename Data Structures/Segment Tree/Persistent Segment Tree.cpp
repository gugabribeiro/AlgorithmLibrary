template <typename T>
struct PersistentSegmentTree {
    struct Node {
        T value;
        Node *left, *right;
        Node(T _value = T(), Node *_left = NULL, Node *_right = NULL):
            value(_value), left(_left), right(_right) {}
    };

    int size;
    vector <Node *> roots;

    PersistentSegmentTree(vector <T> &base) {
        size = base.size();
        roots.push_back(build(0, size - 1, base));
    }

    T combine(const T &left_value, const T &right_value) {
        return left_value + right_value;
    }

    Node *build(int left, int right, vector <T> &base) {
        Node *new_node = new Node();
        if (left == right) {
            new_node->value = base[left];
        } else {
            int mid = (left + right) / 2;
            new_node->left  = build(left, mid, base);
            new_node->right = build(mid + 1, right, base);
            new_node->value = combine(new_node->left->value, new_node->right->value);
        }
        return new_node;
    }

    T query(int root_id, int from, int to) {
        return query(roots[root_id], 0, size - 1, from, to);
    }

    T query(Node *node, int left, int right, int from, int to) {
        if (right < from or left > to) {
            return T();
        } else if (left >= from and right <= to) {
            return node->value;
        } else {
            int mid = (left + right) / 2;
            return combine(query(node->left, left, mid, from, to),
                           query(node->right, mid + 1, right, from, to));
        }
    }

    void update(int at, const T &value) {
        roots.push_back(update(roots.back(), 0, size - 1, at, value));
    }

    Node *update(Node *node, int left, int right, int at, const T &value) {
        Node *new_node = new Node();
        if (left == right) {
            new_node->value = value;
        } else {
            int mid = (left + right) / 2;
            if (at <= mid) {
                new_node->left  = update(node->left, left, mid, at, value);
                new_node->right = node->right;
            } else {
                new_node->left  = node->left;
                new_node->right = update(node->right, mid + 1, right, at, value);
            }
            new_node->value = combine(new_node->left->value, new_node->right->value);
        }
        return new_node;
    }
};
