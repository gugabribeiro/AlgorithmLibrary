#include <bits/stdc++.h>

const int MAXN = 10010;

using namespace std;

vector<int> graph[MAXN];
int dist[MAXN];

void bfs(int u, int n){
  queue<int> q;

  for(int i = 0; i < n; i++){
    dist[i] = -1;
  }

  dist[u] = 0;
  q.push(u);

  while(!q.empty()){
    u = q.front();
    q.pop();

    for(int i = 0; i < (int)graph[u].size(); i++){
      int v = graph[u][i];
      if(dist[v] == -1){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

int main(){
  return 0;
}
