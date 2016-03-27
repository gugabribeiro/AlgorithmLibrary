#include <bits/stdc++.h>

const int MAXN = 10010;
const int INF = (int)1e8;

using namespace std;

typedef pair<int, int> edge;

vector<edge> graph[MAXN];
int dist[MAXN];

void dijkstra(int s, int n){
  priority_queue<edge, vector<edge>, greater<edge> > pq;
  edge e;

  for(int i = 1; i <= n; i++){
    dist[i] = INF;
  }

  dist[s] = 0;
  pq.push({0, s});

  while(!pq.empty()){
    e = pq.top();
    pq.pop();

    if(dist[e.second] == e.first){
      int u = e.second;
      for(int i = 0; i < (int)graph[u].size(); i++){
        int v = graph[u][i].first;
        int w = graph[u][i].second;
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pq.push({dist[v], v})
        }
      }
    }
  }
}

int main(){

  return 0;
}
