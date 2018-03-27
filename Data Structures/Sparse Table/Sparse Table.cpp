template <typename T>
struct sparse_table {
    #define LOG(len) ((int)floor(log((double)len) / log(2.0)))

    int n, m;
    vector <vector <T> > table;

    //Must be implemented according to the problem
    T merge(const T &a, const T &b) {
        return __gcd(a, b);
    }

    sparse_table(const vector <T> &base) {
        n = base.size();
        m = LOG(n) + 1;
        table = vector <vector <T> > (n, vector <T> (m));
        for (int i = 0; i < n; ++i) {
            table[i][0] = base[i];
        }
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int k = LOG(r - l + 1);
        return merge(table[l][k], table[r - (1 << k) + 1][k]);
    }
};
