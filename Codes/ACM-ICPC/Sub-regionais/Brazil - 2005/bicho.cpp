#include <bits/stdc++.h>

const int N = 101;

using namespace std;

int group[N];

int main() {
  int wild = 0;
  for (int i = 1; i < N; i++) {
    group[i % 100] = wild;
    if (i % 4 == 0) {
      wild++;
    }
  }

  double v; int n, m;
  while (scanf("%lf %d %d", &v, &n, &m), v > 0) {
    int equal = 0;
    for (int i = 0; i < 7; i++) {
      if (n % 10 != m % 10) {
        break;
      } else {
        n /= 10, m /= 10;
        equal++;
      }
    }

    double ans = 0.0;
    if (equal >= 4) {
      ans = v * 3000;
    } else if (equal == 3) {
      ans = v * 500;
    } else if (equal == 2) {
      ans = v * 50;
    } else if (group[n % 100] == group[m % 100]) {
      ans = v * 16;
    }

    printf("%.2lf\n", ans);
  }

  return 0;
} 
