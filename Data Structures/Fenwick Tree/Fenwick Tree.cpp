template <typename T>
struct fenwick_tree {
    int size;
    vector <T> tree;

    fenwick_tree(int _size) {
        size = _size;
        tree = vector <T> (size, T());
    }

    T get(int at) {
        T accum = T();
        for (; at >= 0; at = (at & (at + 1)) - 1) {
            accum += tree[at];
        }
        return accum;
    }

    void push(int at, const T &delta) {
        for (; at < size; at = (at | (at + 1))) {
            tree[at] += delta;
        }
    }
};
