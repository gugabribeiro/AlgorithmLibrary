template <typename T>
struct SegmentTree {
    int size;
    vector <T> tree;

    SegmentTree() {}
    SegmentTree(vector <T> &base) {
        size = base.size();
        tree = vector <T> (4 * size);
        build(0, 0, size - 1, base);
    }

    //Must be implemented
    T combine(const T &left, const T &right) {
        return left + right;
    }

    void build(int id, int left, int right, vector <T> &base) {
        if (left == right) {
            tree[id] = base[left];
        } else {
            int mid = (left + right) / 2;
            build(2 * id + 1, left, mid, base);
            build(2 * id + 2, mid + 1, right, base);
            tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
        }
    }

    void update(int at, T value) {
        update(0, 0, size - 1, at, value);
    }

    void update(int id, int left, int right, int at, T value) {
        if (left == right) {
            tree[id] = value;
        } else {
            int mid = (left + right) / 2;
            if (at <= mid) {
                update(2 * id + 1, left, mid, at, value);
            } else {
                update(2 * id + 2, mid + 1, right, at, value);
            }
            tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
        }
    }

    T query(int from, int to) {
        return query(0, 0, size - 1, from, to);
    }

    T query(int id, int left, int right, int from, int to) {
        if (right < from or left > to) {
            return T();
        } else if (left >= from and right <= to) {
            return tree[id];
        } else {
            int mid = (left + right) / 2;
            return combine(query(2 * id + 1, left, mid, from, to),
                           query(2 * id + 2, mid + 1, right, from, to));
        }
    }
};
