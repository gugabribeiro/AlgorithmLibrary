struct FordFulkerson {
  const static int INF = 1e9;
  const static int N = 110;

  struct edge {
    int to, rev, cap, flow;
    edge(int to_, int rev_, int cap_, int flow_):
      to(to_), rev(rev_), cap(cap_), flow(flow_) {}
  };

  int source, sink, n;
  bool mark[N];
  vector<edge> graph[N];

  FordFulkerson(int n_): 
    n(n_) {}

  void addEdge(int u, int v, int uv, int vu = 0) {
    edge a = {v, (int) graph[v].size(), uv, 0};
    edge b = {u, (int) graph[u].size(), vu, 0};

    graph[u].push_back(a);
    graph[v].push_back(b);
  }

  int findPath(int u, int minEdge) {
    if (u == sink) {
      return minEdge;
    } else {
      mark[u] = true;
      for (edge& e : graph[u]) {
        if (!mark[e.to] and e.cap > e.flow) {
          int flow = findPath(e.to, min(minEdge, e.cap - e.flow));
          
          if (flow > 0) {
            e.flow += flow;
            graph[e.to][e.rev].flow -= flow;

            return flow;
          }
        }
      }
      return 0;
    }
  }

  int getMaxFlow(int source_, int sink_) {
    source = source_;
    sink = sink_;

    int maxflow = 0;

    while (true) {
      memset(mark, false, sizeof mark);
      int flow = findPath(source, INF);

      if (flow == 0)
        break;

      maxflow += flow;
    }

    return maxflow;
  }
};