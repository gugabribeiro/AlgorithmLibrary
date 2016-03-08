#include <bits/stdc++.h>

using namespace std;

/** Be careful, this structure was implemented
*** considering elements with id of 1 to n
**/
struct DisjointSets {
  const static int MAXN = 112345; //Ajust if necessary

  int n, numberOfSets;
  int id[MAXN];
  int cnt[MAXN];

  DisjointSets() {}

  //O(n)
  DisjointSets(int _n) {
    n = numberOfSets = _n;
    for (int i = 1; i <= n; i++) {
      id[i] = i;
      cnt[i] = 1;
    }
  }

  //O(log n) this is a very, very improbable worst case
  int findSet(int x) {
    if (id[x] == x)
      return x;
    return id[x] = findSet(id[x]);
  }

  //O(log n) by using findSet operation
  bool unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);

    if (x != y) {
      if (cnt[x] > cnt[y]) {
        id[y] = x;
        cnt[x] += cnt[y];
      } else {
        id[x] = y;
        cnt[y] += cnt[x];
      }
      numberOfSets--;
      return true;
    }
    return false;
  }
};

int main(){
  return 0;
}
