#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
  const static int MAXN = 112345; //Adjust if necessary

  #define LOWBIT(i) (i & (-i));

  int n;
  int tree[MAXN];

  FenwickTree() {}

  FenwickTree(int _n) {
    n = _n;
    for (int i = 1; i <= n; i++)
      tree[i] = 0;
  }

  //O(log2 n)
  void update(int i, int val) {
    while (i <= n) {
      tree[i] += val;
      i += LOWBIT(i);
    }
  }

  //O(log2 n)
  int query(int i) {
    int ret = 0;
    while (i) {
      ret += tree[i];
      i -= LOWBIT(i);
    }
    return ret;
  }
};

int main(){
  return 0;
}
