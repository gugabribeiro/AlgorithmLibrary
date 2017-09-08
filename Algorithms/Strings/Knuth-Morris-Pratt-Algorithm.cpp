vector<int> prefix_function(const string &s) {
  int n = s.size();
  vector<int> back(n + 1); back[0] = -1;
  int i = 0, j = -1;
  while (i < n) {
    while (j >= 0 and s[i] != s[j]) {
      j = back[j];
    }
    ++i, ++j;
    back[i] = j;
  }
  return back;
}

vector<int> kmp(const string &s, const string &t) {
  int i = 0, j = 0, n = s.size(), m = t.size();
  vector<int> back = prefix_function(t), occur;
  while (i < n) {
    while (j >= 0 and s[i] != t[j]) {
      j = back[j];
    }
    ++i, ++j;
    if (j == m) {
      occur.push_back(i - j);
      j = back[j];
    }
  }
  return occur;
}
