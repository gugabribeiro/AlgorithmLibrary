#include <bits/stdc++.h>

using namespace std;

struct FenwickTree2D {
  const static int MAXN = 1234; //Ajust if necessary

  #define LOWBIT(i) (i & (-i))

  int tree[MAXN][MAXN];
  int n, m;

  FenwickTree2D() {}

  //O(n²)
  FenwickTree2D(int _n, int _m) {
    n = _n; m = _m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        tree[i][j] = 0;
  }

  //O(log² n * log² m)
  void update(int x, int y, int val) {
    for (int i = x; i <= n; i += LOWBIT(i))
      for (int j = y; j <= m; j += LOWBIT(j))
        tree[i][j] += val;
  }

  //O(log² n * log² m)
  int query(int x, int y, int val) {
    int ret = 0;
    for (int i = x; i > 0; i -= LOWBIT(i))
      for (int j = y; j > 0; j -= LOWBIT(j))
        ret += tree[i][j];
    return ret;
  }
};

int main() {
  return 0;
}
