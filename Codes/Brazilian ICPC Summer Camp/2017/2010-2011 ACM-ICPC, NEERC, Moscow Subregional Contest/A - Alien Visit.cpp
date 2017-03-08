#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const double PI = acos(-1);

double c[N];

int main() {
  int n; double r;
  cin >> n >> r;

  double area = n * r * r * PI;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  sort(c, c + n);
  for (int i = 1; i < n; i++) {
    double d = c[i] - c[i - 1];
    if (d < 2 * r) {
      d /= 2;
      double sector = acos(d / r) * r * r - d * sqrt(r * r - d * d);
      area -= 2 * sector;
    }
  }

  cout << fixed << setprecision(10);
  cout << area << endl;

  return 0;
}
