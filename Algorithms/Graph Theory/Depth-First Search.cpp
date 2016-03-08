#include <bits/stdc++.h>

const int MAXN = 10010;

using namespace std;

vector<int> graph[MAXN];
bool mark[MAXN];

void dfs(int u){
  if(mark[u]){
    return;
  }else{
    mark[u] = true;
    for(int i = 0; i < (int)graph[u].size(); i++){
      int v = graph[u][i];
      dfs(v);
    }
  }
}

int main(){
  return 0;
}
