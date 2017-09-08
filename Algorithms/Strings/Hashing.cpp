//bases = 311 and 317
//mods = 100000123 and 100000223

struct Hash {
  long long base, mod, size;
  vector<long long> mult, hash;

  //if you prefer to use string instead of vector, change declaration of s
  Hash(long long _base, long long _mod, vector<int> &s) { 
    base = _base; mod = _mod; size = s.size();
    mult.resize(size); mult[0] = 1;
    hash.resize(size); hash[0] = s[0] + 1;
    for (int i = 1; i < size; ++i) {
      mult[i] =  (mult[i - 1] * base) % mod;
      hash[i] = ((hash[i - 1] * base) % mod + s[i] + 1) % mod;
    }
  }

  long long slice(int l, int r) {
    if (!l) {
      return hash[r];
    } else {
      return (hash[r] - (hash[l - 1] * mult[r - l + 1]) % mod + mod) % mod;
    }
  }
};

