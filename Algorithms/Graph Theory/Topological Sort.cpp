#include <bits/stdc++.h>

const int MAXN = 10010;

using namespace std;

vector<int> graph[MAXN];
vector<int> ans;
bool mark[MAXN];

//Topological Sort in reverse order
void topSort(int u){
  if(mark[u]){
    return;
  }else{
    mark[u] = true;
    for(int i = 0; i < (int)graph[u].size(); i++){
      int v = graph[u][i];
      topSort(v);
    }
    ans.push_back(u);
  }
}

int main(){

  return 0;
}
