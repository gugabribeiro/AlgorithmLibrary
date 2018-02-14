template <typename T>
struct DynamicSegmentTree {
    struct Node {
        T value;
        Node *left, *right;

        Node(T _value = T(), Node *_left = NULL, Node *_right = NULL):
            value(T()), left(_left), right(_right) {}
    };

    typedef long long ll;

    ll left_limit, right_limit;
    Node *root;

    DynamicSegmentTree(ll _left_limit, ll _right_limit):
        left_limit(_left_limit), right_limit(_right_limit) {
            root = new Node();
    }

    T get_value(Node *node) {
        if (!node) { return T(); }
        return node->value;
    }

    //Must be implemented
    T combine(const T &left_value, const T &right_value) {
        return left_value + right_value;
    }

    T query(ll from, ll to) {
        return query(root, left_limit, right_limit, from, to);
    }

    T query(Node *node, ll left, ll right, ll from, ll to) {
        if (!node or right < from or left > to) {
            return T();
        } else if (left >= from and right <= to) {
            return node->value;
        } else {
            ll mid = left + (right - left) / 2;
            return combine(query(node->left, left, mid, from, to),
                           query(node->right, mid + 1, right, from, to));
        }
    }

    void update(ll at, T value) {
        root = update(root, left_limit, right_limit, at, value);
    }

    Node *update(Node *node, ll left, ll right, ll at, T value) {
        if (!node) { node = new Node(); }
        if (left == right) {
            node->value = value;
        } else {
            ll mid = left + (right - left) / 2;
            if (at <= mid) {
                node->left = update(node->left, left, mid, at, value);
            } else {
                node->right = update(node->right, mid + 1, right, at, value);
            }
            node->value = combine(get_value(node->left), get_value(node->right));
        }
        return node;
    }
};
