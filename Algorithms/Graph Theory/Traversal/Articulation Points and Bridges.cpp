#include <bits/stdc++.h>

const int MAXN = 10010;

using namespace std;

typedef pair<int, int> ii;

vector<int> graph[MAXN];
vector<ii> bridge;

int num[MAXN], low[MAXN];
int root, cnt, rootChildren;

bool point[MAXN];

void dfs(int u, int p){
  for(int i = 0; i < (int)graph[u].size(); i++){
    int v = graph[u][i];

    if(num[v] == -1){
      if(u == root){
        rootChildren++;
      }

      dfs(v, u);

      if(low[v] >= num[u])
        point[u] = true;
      if(low[v] > num[u])
        bridge.push_back({u, v});

      low[u] = min(low[u], low[v]);
    }else if(v != p){
      low[u] = min(low[u], num[v]);
    }
  }
}

void articulationPointsAndBridges(int n){
  cnt = 1;
  for(int i = 0; i < n; i++){
    if(!num[i]){
      root = i, rootChildren = 0;
      dfs(i, i);
      point[i] = (rootChildren > 1);
    }
  }
}

int main(){
  return 0;
}
