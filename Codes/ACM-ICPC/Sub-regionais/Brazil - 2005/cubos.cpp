#include <bits/stdc++.h>

const int N = 1000;
const int S = 6;

using namespace std;

int cubes[N][S];
int other[] = {5, 3, 4, 1, 2, 0};

bool compare(int x, int y) {
  int index = 0;
  int auxA[S], auxB[S];
  for (int i = 0; i < 3; i++) {
    if (i == 0 || i == other[0]) {
      auxA[4] = cubes[x][0];
      auxA[5] = cubes[x][other[0]];
    } else {
      auxA[index] = cubes[x][i];
      auxA[index + 2] = cubes[x][other[i]];
      index++;
    }
  }
  for (int up = 0; up < S; up++) {
    index = 0;
    for (int i = 0; i < 3; i++) {
      if (i == up || i == other[up]) {
        auxB[4] = cubes[y][up];
        auxB[5] = cubes[y][other[up]];
      } else {
        auxB[index] = cubes[y][i];
        auxB[index + 2] = cubes[y][other[i]];
        index++;
      }
    }
    for (int r = 0; r < 4; r++) {
      bool areEqual = true;
      for (int k = 0; k < S; k++) {
        if (auxA[k] != auxB[k]) {
          areEqual = false;
          break;
        }
      }
      if (areEqual) {
        return true;
      }
      for (int k = 0; k < 3; k++) {
        swap(auxB[k], auxB[(k + 1) % 4]);
      }
    }
  }

  return false;
}

int main() {
  int n;

  while (scanf("%d", &n), n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < S; j++) {
        scanf("%d", &cubes[i][j]);
      }
      bool diff = true;
      for (int j = 0; j < i; j++) {
        if (compare(j, i)) {
          diff = false;
          break;
        }
      }
      res += diff;
    }

    printf("%d\n", res);
  }
  return 0;
}
