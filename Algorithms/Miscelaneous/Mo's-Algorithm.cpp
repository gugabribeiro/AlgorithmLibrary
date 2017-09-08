const int N = ...

int S; //square root factor

struct query {
  int id, l, r;
  query() {}
  bool operator < (const query &other) const {
    if (l / S == other.l / S) {
      return r < other.r;
    } else {
      return l / S < other.l / S;
    }
  }
} queries[N];

void update(int pos, int &res) {
  //update position
} 

vector<int> mos(int n, int m) {
  vector<int> ans(m);
  S = sqrt(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &queries[i].l, &queries[i].r); //0 indexed
    queries[i].id = i;
  }
  sort(queries, queries + m);
  int prev_l = 0, prev_r = -1, res = 0;
  for (int i = 0; i < m; ++i) {
    int l = queries[i].l, r = queries[i].r;
    while (prev_r < r) update(++prev_r, res);
    while (prev_l < l) update(prev_l++, res);
    while (prev_l > l) update(--prev_l, res);
    while (prev_r > r) update(prev_r--, res);
    ans[queries[i].id] = res;
  }
  return ans;
}
