#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

typedef long long lint;
typedef long double ldouble;
typedef complex<ldouble> doublex;

const ldouble PI = acos(ldouble(-1.0));

struct Polynom {
  static void fft(vector<doublex> &poly, bool inverse) {
    int len = poly.size();

    for (int i = 0; i < len; ++i) {
      int j = 0, k = i, log = log2(len) - 1;
      
      while (k) {
        if (k & 1) {
          j += 1 << log;
        }
        k >>= 1;
        --log;
      }

      if (i < j) {
        swap(poly[i], poly[j]); 
      }
    }

    for (int i = 1; i <= log2(len); ++i) {
      int m = 1 << i;
      ldouble angle = 2 * PI * (inverse ? -1 : 1) / m;
      doublex unity_root = doublex(cos(angle), sin(angle));

      for (int j = 0; j < len; j += m) {
        doublex omega = 1;

        for (int k = 0; k < m / 2; ++k) {
          doublex t = omega * poly[j + k + m / 2];
          doublex u = poly[j + k];

          poly[j + k] = u + t;
          poly[j + k + m / 2] = u - t;
          omega = omega * unity_root;
        }
      }
    }

    if (inverse) {
      for (int i = 0; i < len; ++i) {
        poly[i] /= len;
      }
    }
  }

  static vector<doublex> convolution(const vector<doublex> &a, const vector<doublex> &b) {
    int n = a.size(), m = b.size();
    int len = 1 << ((int) ceil(log2(max(n, m) + 1)) + 1);

    vector<doublex> fa(len, 0), fb(len, 0);

    for (int i = 0; i < n; ++i) {
      fa[i] = a[i];
    }

    for (int i = 0; i < m; ++i) {
      fb[i] = b[i];
    }

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < len; ++i) {
      fa[i] *= fb[i];
    }

    fft(fa, true);

    return fa;
  }

  static vector<doublex> multiply(const vector<doublex> &a, const vector<doublex> &b) {
    int n = a.size(), m = b.size();
    int len = 1 << ((int) ceil(log2(max(n, m) + 1)) + 1);

    vector<doublex> fa(len, 0), fb(len, 0);

    for (int i = 0; i < n; ++i) {
      fa[i] = a[i];
    }

    for (int i = 0; i < m; ++i) {
      fb[i] = b[i];
    }

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < len; ++i) {
      fa[i] *= fb[i];
    }

    fft(fa, true);
    
    return fa;
  }
};

int main() {
  return 0;
}
