template <typename T>
struct sparse_table {
    int n;
    vector <int> logs;
    vector <vector <T> > table;

    T merge(const T &a, const T &b) {
        return max(a, b);
    }

    sparse_table(const vector <T> &base) {
        n = base.size();
        logs = vector <int> (n + 1);
        for (int i = 2; i <= n; ++i) {
            logs[i] = logs[i / 2] + 1;
        }
        table = vector <vector <T> > (logs[n] + 1, vector <T> (n));
        for (int i = 0; i < n; ++i) {
            table[0][i] = base[i];
        }
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                table[j][i] = merge(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int k = logs[r - l + 1];
        return merge(table[k][l], table[k][r - (1 << k) + 1]);
    }
};
