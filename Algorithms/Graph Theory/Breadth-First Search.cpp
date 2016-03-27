#include <bits/stdc++.h>

const int MAXN = 10010;
const int INF = INT_MAX / 3;

using namespace std;

int p;
vector<int> graph[MAXN];
int dist[MAXN];

void bfs(int s, int n){
  queue<int> q;

  for(int i = 1; i <= n; i++){
    dist[i] = INF;
  }

  dist[s] = 0;
  q.push(s);

  while(!q.empty()){
    s = q.front();
    q.pop();

    for(int i = 0; i < (int)graph[s].size(); i++){
      int v = graph[s][i];
      if(dist[v] > dist[u] + p){
        dist[v] = dist[s] + p;
        q.push(v);
      }
    }
  }
}

int main(){
  return 0;
}
