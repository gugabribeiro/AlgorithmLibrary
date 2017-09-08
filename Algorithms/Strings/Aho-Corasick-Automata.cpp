//remember to run build_fail after put all string in aho corasick automata
struct AhoCorasick {
  int states, n, sigma;
  vector<vector<int>> trie;
  vector<int> out, fail;

  AhoCorasick() {}
  AhoCorasick(int _n, int _sigma) {
    states = 0;
    n = _n; sigma = _sigma;
    trie.resize(n);
    for (int i = 0; i < n; ++i) {
      trie[i].resize(sigma, -1);
    }
    out.resize(n, 0);
    fail.resize(n, -1);
  }

  void add(const string &s, int id) {
    int cur_state = 0;
    for (int i = 0; i < s.size(); ++i) {
      int ch = s[i] - 'a';
      if (trie[cur_state][ch] == -1) {
        trie[cur_state][ch] = ++states;
      }
      cur_state = trie[cur_state][ch];
    }
    out[cur_state] |= (1 << id);
  }

  void build_fail() {
    queue<int> q;
    for (int i = 0; i < sigma; ++i) {
      if (trie[0][i] == -1) {
        trie[0][i] = 0;
      } else {
        fail[trie[0][i]] = 0;
        q.push(trie[0][i]);
      }
    }
    while (!q.empty()) {
      int state = q.front();
      q.pop();
      for (int i = 0; i < sigma; ++i) {
        if (trie[state][i] != -1) {
          int failure = fail[state];
          while (trie[failure][i] == -1) {
            failure = fail[failure];
          }
          failure = trie[failure][i];
          fail[trie[state][i]] = failure;
          out[trie[state][i]] |= out[failure];
          q.push(trie[state][i]);
        }
      }
    }
  }

  int next_state(int state, int ch) {
    while (trie[state][ch] == -1) {
      state = fail[state];
    }
    return trie[state][ch];
  }
};
