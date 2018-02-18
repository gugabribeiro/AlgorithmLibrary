template <typename T>
struct FenwickTree {
    int size;
    vector <T> tree;

    FenwickTree(int _size) {
        size = _size;
        tree = vector <T> (size, T());
    }

    T query(int i) {
        T sol = T();
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            sol += tree[i];
        }
        return sol;
    }

    void update(int i, T delta) {
        for (; i < size; i = (i | (i + 1))) {
            tree[i] += delta;
        }
    }
};
