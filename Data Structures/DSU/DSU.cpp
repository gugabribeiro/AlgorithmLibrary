#include <bits/stdc++.h>

using namespace std;

struct DisjointSets {
  vector<int> id, length;

  DisjointSets(int n) {
    id.resize(n);
    length.resize(n);
    
    for (int i = 0; i < n; ++i) {
      id[i] = i;
      length[i] = 1;
    }
  }

  int find_set(int x) {
    if (id[x] == x) {
      return x;
    } else {
      return id[x] = find_set(id[x]);
    }
  }

  bool union_set(int x, int y) {
    x = find_set(x), y = find_set(y);
    if (x != y) {
      if (length[x] > length[y]) {
        id[y] = x;
        length[x] += length[y];
      } else {
        id[x] = y;
        length[y] += length[x];
      }
      return true;
    }
    return false;
  }

  bool is_same_set(int x, int y) {
    return find_set(x) == find_set(y);
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  DisjointSets banks(n);
  while (m--) {
    char c; int u, v;
    scanf(" %c %d %d", &c, &u, &v);
    --u, --v;
    if (c == 'C') {
      printf("%c\n", banks.is_same_set(u, v) ? 'S' : 'N');
    } else {
      banks.union_set(u, v);
    }
  }
  return 0;
}
