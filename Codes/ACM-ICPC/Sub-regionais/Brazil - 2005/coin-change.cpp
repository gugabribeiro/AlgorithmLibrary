#include <bits/stdc++.h>

const int N = 251;

using namespace std;

typedef long long lint;

lint dp[N];
lint c[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%lld", &c[i]);
  }
  dp[0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 1; c[i] * j <= m; j++) {
      for (int k = 1; k <= n; k++) {
        if (k - c[i] * j >= 0) {
          dp[k] += dp[k - c[i] * j];
        }
      }
    }
  }
  printf("%lld\n", dp[n]);
  return 0;
}
