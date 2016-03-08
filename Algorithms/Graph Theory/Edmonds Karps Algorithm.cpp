#include <bits/stdc++.h>

const int MAXV = 1010;

using namespace std;

int s, t, f, max_flow;
int dist[MAXV], p[MAXV];
int mat[MAXV][MAXV];

void augment(int x, int min_edge) {
	if (x == t) 
		f = min_edge;
	else if (p[x] != -1) {
		augment(p[x], min(min_edge, mat[x][p[x]]));
		mat[x][p[x]] -= f;
		mat[p[x]][x] += f;
	}	
}

void bfs(int v) {
	max_flow = 0;

	while (true) {
		
	}
}

int main() {
	int v, e;

	cin >> v >> e;

	while (e--) {
		int x, y, w;

		cin >> x >> y >> w;

		mat[x][y] = w;
	}

	cin >> s >> t;

	bfs(v);

	cout << max_flow << endl;

	return 0;
}