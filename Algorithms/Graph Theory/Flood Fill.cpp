#include <bits/stdc++.h>

const int MAXN = 1010;

using namespace std;

int R, C;
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
char grid[MAXN][MAXN];

int floodFill(int r, int c, char c1, char c2){
  if(r < 0 || r >= R || c < 0 || c >= C){
    return 0;
  }else if(grid[r][c] != c1){
    return 0;
  }else{
    int ret = 1;
    grid[r][c] = c2;
    for(int d = 0; d < 8; d++){
      ret += floodFill(r + dr[d], c + dc[d], c1, c2);
    }
    return ret;
  }
}

int main(){

  return 0;
}
