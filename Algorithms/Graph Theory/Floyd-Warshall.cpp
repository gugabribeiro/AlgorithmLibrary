#include <bits/stdc++.h>

using namespace std;

const int N = 301;

int mat[N][N];

void floydWarshall(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }
}

int main() {
  return 0;
}
