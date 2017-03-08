#include <bits/stdc++.h>

using namespace std;

const int N = 210;
const int M = 510;

char line[N];
char path[M];
int cost[N][N];
bool mark[N][N];

int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 1; i < 2 * n; i += 2) {
    scanf("%s", line);
    
    for (int j = 1, k = 0; k < m; k++, j += 2)
      cost[i][j] = (line[k] - '0');
  }

  scanf("%s", path);
  
  int x = 0, y = 0;
  int dir = 0, ans = 0;
  int len = strlen(path);

  for (int i = 0; i < len; i++) {
    if (path[i] == 'M') 
      for (int j = 0; j < 2; j++) {
        x += X[dir];
        y += Y[dir];

        for (int k = 0; k < 4; k++) {
          int new_x = x + X[k];
          int new_y = y + Y[k];

          if (new_x < 0 or new_y < 0) 
            continue;

          ans += (cost[new_x][new_y] / (1 + mark[new_x][new_y]));
          mark[new_x][new_y] = true;
        }
      }
    else if (path[i] == 'L') 
      dir = ((dir - 1) + 4) % 4;
    else
      dir = (dir + 1) % 4;
  }
  
  printf("%d\n", ans);

  return 0;
}