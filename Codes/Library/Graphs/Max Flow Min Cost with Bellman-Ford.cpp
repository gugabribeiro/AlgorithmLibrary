#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

//O(min(E ^ 2 * V ^ 2, E * V * FLOW))
struct MinCostFlow {
  static const int N = 110;
  static const int INF = 1e9; 

  struct edge {
    int to, rev, flow, cap, cost;
    edge(int to_, int rev_, int cap_, int flow_, int cost_):
      to(to_), rev(rev_), cap(cap_), flow(flow_), cost(cost_) {}
  };

  int n;
  int dist[N], curflow[N];
  bool inqueue[N];
  int prevnode[N], queue[N];
  int prevedge[N];
  vector<edge> graph[N];

  MinCostFlow(int n_):
    n(n_) {}

  void addEdge(int u, int v, int cap, int cost) {
    edge a = edge(v, graph[v].size(), cap, 0, cost);
    edge b = edge(u, graph[u].size(), 0,   0, -cost);

    graph[u].push_back(a);
    graph[v].push_back(b);
  }

  void clear() {
    for (int i = 0; i < n; i++)
      graph[i].clear();
  }

  void bellmanFord(int s) {
    for (int i = 0; i < n; i++) {
      dist[i] = INF;
      inqueue[i] = false;
      queue[i] = 0;
    }

    dist[s] = 0;
    curflow[s] = INF;

    int qtop = 0;
    queue[qtop++] = s;

    for (int qh = 0; (qh - qtop) % n != 0; qh++) {
      int u = queue[qh % n];
      inqueue[u] = false;

      for (int i = 0; i < graph[u].size(); i++) {
        edge& e = graph[u][i];

        if (e.flow >= e.cap)
          continue;

        int v = e.to;
        if (dist[v] > dist[u] + e.cost) {
          dist[v] = dist[u] + e.cost;
          prevnode[v] = u;
          prevedge[v] = i;

          curflow[v] = min(curflow[u], e.cap - e.flow);
          if (!inqueue[v]) {
            inqueue[v] = true;
            queue[qtop++ % n] = v;
          }
        }
      }
    }
  }

  pair<int, int> minCostFlow(int source, int sink, int maxFlow) {
    int flow = 0, flowCost = 0;

    for (int i = 0; i < n; i++)
      dist[i] = curflow[i] = prevnode[i] = prevnode[i] = 0;

    while (flow < maxFlow) {
      bellmanFord(source);

      if (dist[sink] == INF)
        break;

      int dflow = min(curflow[sink], maxFlow - flow);
      flow += dflow;

      for (int v = sink; v != source; v = prevnode[v]) {
        edge& e = graph[prevnode[v]][prevedge[v]];
        e.flow += dflow;
        graph[v][e.rev].flow -= dflow;
        flowCost += dflow * e.cost;
      }
    } 

    return {flow, flowCost};
  }
};

int main() {

  return 0;
}