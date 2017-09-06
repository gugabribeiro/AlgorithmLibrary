const int N = ...
const int L = ...

typedef pair<int, int> edge;

int n; //number of vertices
int depth[N];
int parent[N][L], dist[N][L];

vector<edge> graph[N]; 

void dfs(int u) {
  for (edge e : graph[u]) {
    int v = e.first;
    if (v != parent[u][0]) {
      depth[v] = 1 + depth[u];
      dist[v][0] = e.second;
      parent[v][0] = u;
      dfs(v);
    }
  }
}

pair<int, int> get(int u, int v) {
  int cur_dist = 0;
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  for (int log = L - 1; log >= 0; --log) {
    if (depth[u] - (1 << log) >= depth[v]) {
      cur_dist += dist[u][log]; 
      u = parent[u][log];
    }
  }
  if (u == v) {
    return {u, cur_dist};
  } 
  for (int log = L - 1; log >= 0; --log) {
    if (parent[u][log] != parent[v][log]) {
      cur_dist += dist[u][log] + dist[v][log];
      u = parent[u][log];
      v = parent[v][log];
    }
  }
  return {parent[u][0], cur_dist + dist[u][0] + dist[v][0]};
}

void build(int root) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < L; ++j) {
      dist[i][j] = 0;
      parent[i][j] = -1;
    }
  }
  depth[root] = 0;
  dfs(root);
  for (int log = 1; log < L; ++log) {
    for (int i = 0; i < n; ++i) {
      if (parent[i][log - 1] != -1) {
        parent[i][log] = parent[parent[i][log - 1]][log - 1];
        //this is just a example of how to use the sparse table to store some other infos
        dist[i][log] = dist[i][log - 1] + dist[parent[i][log - 1]][log - 1];
      }
    }
  }
}
