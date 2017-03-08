#include <bits/stdc++.h>

const int N = 201;

using namespace std;

int degree[N];
string subject[N];
int semester_of[N];
map<string, int> id;
vector<int> graph[N];
vector<int> rev_graph[N];
vector<string> semesters[N];

vector<int> KahnsAlgorithm(int n) {
  vector<int> topsort;
  priority_queue<int, vector<int>, greater<int> > q;

  for (int i = 0; i < n; i++) {
    if (!degree[i]) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.top();
    q.pop();
    topsort.push_back(u);
    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      degree[v]--;
      if (!degree[v]) {
        q.push(v);
      }
    }
  }
  return topsort;
}

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m), n) {
    int idx = 0;

    while (n--) {
      string s;
      int q;
      cin >> s >> q;
      if (!id.count(s)) {
        id[s] = idx;
        subject[idx++] = s;
      }
      int u = id[s];
      degree[u] = q;
      while (q--) {
        string t;
        cin >> t;
        if (!id.count(t)) {
          id[t] = idx;
          subject[idx++] = t;
        }
        int v = id[t];
        graph[v].push_back(u);
        rev_graph[u].push_back(v);
      }
    }

    int semesters_cnt = 0;
    vector<int> topsort = KahnsAlgorithm(idx);

    for (int i = 0; i < topsort.size(); i++) {
      int u = topsort[i];
      semester_of[u] = 0;
      for (int j = 0; j < rev_graph[u].size(); j++) {
        int v = rev_graph[u][j];
        semester_of[u] = max(semester_of[u], semester_of[v] + 1);
      }
      while (semesters[semester_of[u]].size() == m) {
        semester_of[u]++;
      }
      semesters[semester_of[u]].push_back(subject[u]);
      semesters_cnt = max(semesters_cnt, semester_of[u]);
    }

    printf("Formatura em %d semestres\n", semesters_cnt + 1);
    for (int i = 0; i <= semesters_cnt; i++) {
      printf("Semestre %d :", i + 1);
      sort(semesters[i].begin(), semesters[i].end());
      for (int j = 0; j < semesters[i].size(); j++) {
        printf(" %s", semesters[i][j].c_str());
      }
      putchar('\n');
    }

    id.clear();
    for (int i = 0; i <= semesters_cnt; i++) {
      semesters[i].clear();
    }
    for (int i = 0; i < idx; i++) {
      graph[i].clear();
      rev_graph[i].clear();
    }
  }
  return 0;
}
