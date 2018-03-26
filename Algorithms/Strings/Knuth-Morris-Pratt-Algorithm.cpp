struct KMP {
    static vector <int> prefix_function(const vector <int> &T) {
        int i = 0, j, n = T.size();
        vector <int> back(n + 1);
        back[0] = j = -1;
        while (i < n) {
            while (j >= 0 and T[i] != T[j]) { j = back[j]; }
            ++i;
            ++j;
            back[i] = j;
        }
        return back;
    }

    static vector <int> matching(const vector <int> &S, const vector <int> &T) {
        int i = 0, j = 0, n = S.size(), m = T.size();
        vector <int> back = prefix_function(T), at;
        while (i < n) {
            while (j >= 0 and S[i] != T[j]) { j = back[j]; }
            ++i;
            ++j;
            if (j == m) {
                at.push_back(i - j);
                j = back[j];
            }
        }
        return at;
    }
};
