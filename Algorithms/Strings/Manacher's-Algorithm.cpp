vector<vector<int>> manacher(vector<int> &s) {
  int n = s.size();
  vector<vector<int>> p(2, vector<int>(n, 0));
  for (int j = 0, l = 0, r = 0; j < 2; ++j, l = 0, r = 0) {
    for (int i = 0; i < n; ++i) {
      if (i < r) {
        p[j][i] = min(r - i + !j, p[j][l + r - i + !j]);
      }
      int cur_l = i - p[j][i], cur_r = i + p[j][i] - !j;
      while (cur_l - 1 >= 0 and cur_r + 1 < n and s[cur_l - 1] == s[cur_r + 1]) {
        p[j][i]++, --cur_l, ++cur_r;
      }
      if (cur_r > r) {
        l = cur_l, r = cur_r;
      }
    }
  }
  return p;
}
