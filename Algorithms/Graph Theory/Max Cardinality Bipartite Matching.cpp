#include <bits/stdc++.h>

const int MAXN = 1010;

using namespace std;

vector<int> graph[MAXN];

int augment(int v) {

}

int main() {
	int n, e;

	scanf("%d %d", &n, &e);

	while (e--) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	memset(match, -1, sizeof match);

	for (int i = 0; i < v; i++) {
		memset(mark, false, sizeof mark);

		
	}

	return 0;
}