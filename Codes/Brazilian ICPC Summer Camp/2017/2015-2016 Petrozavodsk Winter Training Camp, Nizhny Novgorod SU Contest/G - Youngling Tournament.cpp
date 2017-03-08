#include <bits/stdc++.h>

#define debug(x) cout << x << endl

const int N = 200001;

using namespace std;

typedef long long lint;

int pos[N];
set<lint> sums;
map<lint, int> id;
lint bit[N], f[N], value[N];

void put(int i, lint v) {
  while (i < N) {
    bit[i] += v;
    i += i & -i;
  }
}

lint get(int i) {
  lint res = 0;
  while (i) {
    res += bit[i];
    i -= i & -i;
  }
  return res;
}

int solve() {
  int ans = 0;
  lint sum = 0, cnt = 10;
  
  while (cnt--) {
    it = sums.lower_bound(sum);

    if (it == sums.end()) {
      break;
    } else {
      lint i = *it;
      lint pref_sum = get();
    }
  }
  
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%lld", &f[i]);
    sums.insert(f[i]);
  }

  int m;
  scanf("%d", &m);

  for (int i = 0; i < m; i++) {
    scanf("%d %lld", &pos[i], &value[i]);
    sums.insert(value[i]);
  }

  int id_ = 0;
  for (auto i : sums) {
    id[i] = ++id_;
    put(id_, i);
  }

  for (int i = 0; i < m; i++) {
    printf("%d\n", solve());

    put(id[f[pos[i]]], -f[pos[i]]); //remove
    sums.erase(f[pos[i]]);
    
    f[pos[i]] = value[i];
    put(id[f[pos[i]]],  f[pos[i]]); //add
    sums.insert(f[pos[i]]);
  }

  printf("%d\n", solve());

  return 0;
}