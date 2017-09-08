const int L = ...
const int N = ...

int idx;
int st[N], en[N];
int depth[N], a[N];
int parent[N][L];
map<int, int> id;
vector<int> graph[N];

void dfs(int u) {
	a[idx] = u;
	st[u] = idx++;
	for (int v : graph[u]) {
		if (v != parent[u][0]) {
			parent[v][0] = u;
			depth[v] = 1 + depth[u];
			dfs(v);
		}
	}
	a[idx] = u;
	en[u] = idx++;
}

void build(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < L; ++j) {
			parent[i][j] = -1;
		}
		depth[i] = 0;
	} 
	dfs(0);
	for (int j = 1; j < L; ++j) {
		for (int i = 0; i < n; ++i) {
			if (parent[i][j - 1] != -1) {
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
			}
		}
	}
}

int get_lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	for (int i = L - 1; i >= 0; --i) {
		if (depth[u] - (1 << i) >= depth[v]) {
			u = parent[u][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = L - 1; i >= 0; --i) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

int ans[N], S;

struct query {
	int id, lca, l, r;
	query() {}
	bool operator < (const query &other) const {
		if (l / S == other.l / S) {
			return r < other.r;
		} else {
			return l / S < other.l / S;
		}
	}
} queries[N];

void update(int u, int &res) {
	//update node u and res
}

void mos_on_tree(int n, int m) {
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		int lca = get_lca(u, v);
		if (st[u] > st[v]) {
			swap(u, v);
		}
		queries[i].lca = lca;
		queries[i].id = i;
		if (u == lca) {
			queries[i].l = st[u];
			queries[i].r = st[v];
		} else {
			queries[i].l = en[u];
			queries[i].r = st[v];
		}
	}
	S = sqrt(2 * n);
	int prev_l = 0, prev_r = -1, res = 0;
	sort(queries, queries + m);
	for (int i = 0; i < m; ++i) {
		int l = queries[i].l, r = queries[i].r;
		while (prev_l < l) update(a[prev_l++], res);
		while (prev_l > l) update(a[--prev_l], res);
		while (prev_r < r) update(a[++prev_r], res);
		while (prev_r > r) update(a[prev_r--], res);
		int u = a[prev_l], v = a[prev_r];
		if (queries[i].lca != u and queries[i].lca != v) { 
			update(queries[i].lca, res);
		}
		ans[queries[i].id] = res;
		if (queries[i].lca != u and queries[i].lca != v) { 
			update(queries[i].lca, res);
		}
	}	
	for (int i = 0; i < m; ++i) {
		printf("%d\n", ans[i]);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	idx = 0;
	build(n);
	mos_on_tree(n, m);
	return 0;
}
