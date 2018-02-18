template <typename T>
struct TwoDFenwickTree {
    int height, width;
    vector <vector <T> > tree;

    TwoDFenwickTree(int _height, int _width) {
        height = _height;
        width  = _width;
        tree = vector <vector <T> > (height, vector <T> (width, T()));
    }

    T query(int x, int y) {
        T sol = T();
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = x; j >= 0; j = (i & (i + 1)) - 1) {
                sol += tree[i][j];
            }
        }
        return sol;
    }

    void update(int x, int y, T delta) {
        for (int i = x; i < height; i = (i | (i + 1))) {
            for (int j = y; i < width; j = (j | (j + 1))) {
                tree[i][j] += delta;
            }
        }
    }
};
