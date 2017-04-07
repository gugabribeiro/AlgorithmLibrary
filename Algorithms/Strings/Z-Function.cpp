#include <bits/stdc++.h>

using namespace std;

//O(n ^ 2)
vector<int> z_funcion_trivial(string& s) {
  int n = int(s.size());
  vector<int> z(n);

  for (int i = 1; i < n; i++) 
    while (i + z[i] < n and s[z[i]] == s[i + z[i]]) 
      ++z[i];

  return z;
}

//O(n)
vector<int> z_function(string& s) {
  int n = int(s.size());
  vector<int> z(n);

  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n and s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1; 
  }

  return z;
}

vector<int> string_matching(string& s, string& t) {
  int sz = int(t.size());
  string sum = t + '$' + s;

  vector<int> res;
  vector<int> z = z_function(sum);
    
  for (int i = 0; i < z.size(); i++)
    if (z[i] == sz) 
      res.push_back(i - sz - 1);

  return res;
}

int distinct_substrings(string& s) {
  string t;
  int n = int(s.size()), ans = 0;
  
  for (int i = 0; i < n; i++) {
    t += s[i];

    int max_pref = 0;
    for (int z : z_function(t))
      max_pref = max(max_pref, z);

    ans += (i + 1) - max_pref;
  }

  return ans;
}

string string_period(string& s) {
  int sz = int(s.size()), len;
  vector<int> z = z_function(s);

  len = sz;
  for (int i = 0; i < sz; i++) 
    if (i + z[i] == sz) {
      if (!(sz % i))
        len = i; 
    }

  return s.substr(sz - len);
}

int main() {
  string s;
  while (cin >> s) 
    cout << string_period(s) << endl;

  return 0;
}