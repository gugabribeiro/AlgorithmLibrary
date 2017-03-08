#include <bits/stdc++.h>

using namespace std;

int n, m;
int x1, x2, y1, y2;

bool check(int x, int y) {
  if (x < x1 or x > x2) {
    return false;
  }
  if (y < y1 or y > y2) {
    return false;
  }
  return true;
}

typedef pair<int, int> cell;

queue<cell> cells;

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cells.push({i, j});
    }
  }

  int sum_x = 0, sum_y = 0;
  while (1) {
    cell c = cells.front();
    cells.pop();

    int x = c.first, y = c.second;
    if (!valid(x, y)) {
      continue;
    }

    cout << x + sum_x
  }

  return 0;
}
