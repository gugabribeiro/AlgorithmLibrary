#include <bits/stdc++.h>

const int MAXN = 10010;

using namespace std;

vector<int> graph[MAXN];
int color[MAXN];

bool isBipartite(int u, int n){
  queue<int> q;

  for(int i = 0; i < n; i++){
    color[i] = -1;
  }

  color[u] = 0;
  q.push(u);

  while(!q.empty()){
    u = q.front();
    q.pop();

    for(int i = 0; i < (int)graph[u].size(); i++){
      int v = graph[u][i];

      if(color[v] == -1){
        color[v] = !color[u];
        q.push(v);
      }else if(color[v] == color[u]){
        return false;
      }
    }
  }
  return true;
}

int main(){
  return 0;
}
