#include <bits/stdc++.h>

using namespace std;

const int N = 100010; 
const int S = sqrt(N);

struct query {
  int id, x;
  int l, r;
  query() {}
} queries[N];

int a[N];
int cnt[N];
int ans[N];

void update(int pos, int val) {
  cnt[a[pos]] += val;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", &queries[i].x, &queries[i].l, &queries[i].r);
    --queries[i].l;
    --queries[i].r;
    queries[i].id = i;
  }

  [1, 1]
  [2, 9]

  sort(queries, queries + q, [&](const query& a, const query& b) {
    if (a.l / S != b.l / S) 
      return a.l / S < b.l / S;
    return a.r < b.r;
  });

  int L = 0, R = -1;
  for (int i = 0; i < q; i++) {
    int l = queries[i].l;
    int r = queries[i].r;
    int x = queries[i].x;

    while (R < r)
      update(++R, 1);

    while (L < l) 
      update(L++, -1);

    while (L > l)
      update(--L, 1); 

    while (R > r) 
      update(R--, -1);

    ans[queries[i].id] = cnt[x];
  }

  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);

  return 0;
} 