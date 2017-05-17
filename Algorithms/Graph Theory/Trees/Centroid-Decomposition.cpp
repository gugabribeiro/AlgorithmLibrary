#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

vector<int> tree[N];
int centroid_parent[N];
vector<int> centroid_tree[N];

int sub_size[N];
bool is_centroid[N];

int dfs(int u, int p) {
  sub_size[u] = 1;
  for (int v : tree[u]) {
    if (v != p and !is_centroid[v]) {
      sub_size[u] += dfs(v, u);
    }
  }
  return sub_size[u];
}

int get_centroid(int u, int p, int tree_size) {
  int heavy_child = -1;
  is_centroid[u] = true;
  for (int v : tree[u]) {
    if (v != p and !is_centroid[v]) {
      if (2 * sub_size[v] > tree_size) {
        is_centroid[u] = false;
      }
      if (heavy_child == -1 or sub_size[v] > sub_size[heavy_child]) {
        heavy_child = v;
      }
    }
  }
  if (is_centroid[u] and 2 * (tree_size - sub_size[u]) <= tree_size) {
    return u;
  } else {
    return get_centroid(heavy_child, u, tree_size);
  }
}

int get_centroid(int u) {
  memset(sub_size, 0, sizeof sub_size);
  int tree_size = dfs(u, u);
  int centroid = get_centroid(u, u, tree_size);
  is_centroid[centroid] = true;
  return centroid;
}

int decompose_tree(int root) {
  int centroid = get_centroid(root);
  for (int v : tree[centroid]) {
    if (!is_centroid[v]) {
      int sub_centroid = decompose_tree(v);
      centroid_tree[centroid].push_back(sub_centroid);
      centroid_tree[sub_centroid].push_back(centroid);
      centroid_parent[sub_centroid] = centroid;
    }
  }
  return centroid;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  memset(centroid_parent, -1, sizeof centroid_parent);
  int root = decompose_tree(0);
  for (int i = 0; i < n; ++i) {
    printf("%d ", 1 + centroid_parent[i]);
  }
  return 0;
}
