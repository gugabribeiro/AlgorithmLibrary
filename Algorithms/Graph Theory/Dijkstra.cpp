#include <bits/stdc++.h>

const int MAXN = 10010;
const int INF = (int)1e8;

using namespace std;

typedef pair<int, int> edge;

vector<edge> graph[MAXN];
int dist[MAXN];

void dijkstra(int n, int s){
  priority_queue<edge> pq;
  edge e;

  for(int i = 0; i < n; i++){
    dist[i] = INF;
  }

  dist[s] = 0;
  pq.push({0, s});

  while(!pq.empty()){
    e = pq.top();
    pq.pop();

    if(dist[e.second] < e.first){
      for(int i = 0; i < (int)graph[u].size(); i++){

      }
    }
  }
}

int main(){

  return 0;
}
