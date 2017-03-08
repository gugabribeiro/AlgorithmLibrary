#include <bits/stdc++.h>

const int N = 12;

using namespace std;

int problem[N];

bool check(double people, double percent) {
  double c_people = 0;
  while (round(c_people) <= percent) {
    if (round(c_people) == percent) {
      return true;
    } else {
      c_people += people;
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> problem[i];
  }

  for (int j = 1; j <= 100; j++) {
    bool valid = true;
    for (int i = 0; i < n; i++) {
      valid &= check(j / 100.0, problem[i]);
    }
    if (valid) {
      printf("%d\n", j);
      return 0;
    }
  }

  return 0;
}
