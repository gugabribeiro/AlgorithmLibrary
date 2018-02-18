struct DSU {
    vector <int> id;

    DSU() {}
    DSU(int n) {
        id = vector <int> (n);
        iota(id.begin(), id.end(), 0);
    }

    int find_set(int x) {
        return id[x] == x ? x : id[x] = find_set(id[x]);
    }

    bool union_set(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        id[x] = y;
        return x != y
    }

    bool same_set(int x, int y) {
        return find_set(x) == find_set(y);
    }
};
