//O(n)
vector<int> z_function(const string &s) {
  int n = int(s.size()); vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1; 
    }
  }
  return z;
}

//O(n + m)
vector<int> string_matching(const string &s, const string &t) {
  int sz = int(t.size());
  string sum = t + '$' + s;
  vector<int> res, z_array = z_function(sum);
  for (int i = 0; i < z_array.size(); i++) {
    if (z_array[i] == sz) {
      res.push_back(i - sz - 1);
    }
  }
  return res;
}

//O(n ^ 2)
int distinct_substrings(const string &s) {
  string t;
  int n = int(s.size()), ans = 0;
  for (int i = 0; i < n; i++) {
    t += s[i];
    int max_pref = 0;
    for (int z : z_function(t)) {
      max_pref = max(max_pref, z);
    }
    ans += (i + 1) - max_pref;
  }
  return ans;
}

//O(n)
string string_period(const string &s) {
  int sz = s.size(), len = s.size();
  vector<int> z = z_function(s);
  for (int i = 0; i < sz; i++) {
    if (i + z[i] == sz and !(sz % i)) {
      len = i; 
    }
  }
  return s.substr(sz - len);
}
