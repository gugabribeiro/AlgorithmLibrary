struct Hash {
  #define valueOf(ch) (ch) //change if needed

  int n;
  lint BASE, MOD, INV;
  lint *data, *base, *inv;

  lint modPow(lint a, lint b) {
    lint res = 1;
    while (b > 0) {
      if (b & 1) res = res * a % MOD;
      a = a * a % MOD;
      b >>= 1;
    }
    return res;
  }

  Hash(char *s, int _n, lint _base, lint _mod) {
    n = _n;

    MOD = _mod;
    BASE = _base;
    INV = modPow(BASE, MOD - 2);

    data = new lint[n + 1];
    base = new lint[n + 1];
    inv  = new lint[n + 1];

    data[0] = valueOf(s[0]);
    base[0] = inv[0] = 1;

    for (int i = 1; i < n; i++) {
      base[i] = base[i - 1] * BASE % MOD;
      inv[i] = inv[i - 1] * INV % MOD;
      data[i] = (data[i - 1] + valueOf(s[i]) * base[i]) % MOD;
    }
  }

  lint slice(int l, int r) {
    return (((data[r] - (l == 0 ? 0 : data[l - 1])) % MOD) + MOD) * inv[l] % MOD;
  }
};

