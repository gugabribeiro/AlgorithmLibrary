#include <bits/stdc++.h>

const int W = 5;
const int N = 10001;

using namespace std;

struct task {
  int points;
  int begin, end;
  task() {}
  task(int points, int begin, int end):
    points(points), begin(begin), end(end) {}
};

int dp[N];
int nextOf[N];
vector<task> week[W];
string days[] = {"Seg", "Ter", "Qua", "Qui", "Sex"};

int dayOf(string sDay) {
  if (sDay == "Seg") {
    return 0;
  } else if (sDay == "Ter") {
    return 1;
  } else if (sDay == "Qua") {
    return 2;
  } else if (sDay == "Qui") {
    return 3;
  } else {
    return 4;
  }
}

int solve(int i, int j) {
  if (j == week[i].size()) {
    return 0;
  } else {
    int &res = dp[j];
    if (res == -1) {
      res = max(solve(i, j + 1), solve(i, nextOf[j]) + week[i][j].points);
    }
    return res;
  }
}

int binarySearch(int i, int j) {
  int res = week[i].size();
  int lo = j + 1, hi = week[i].size() - 1;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (week[i][j].end <= week[i][mid].begin) {
      hi = mid - 1;
      res = mid;
    } else {
      lo = mid + 1;
    }
  }
  return res;
}

bool compare(task a, task b) {
  if (a.begin == b.begin) {
    return a.end < b.end;
  } else {
    return a.begin < b.begin;
  }
}

int main() {
  int n;
  while (scanf("%d", &n), n) {
    while (n--) {
      char sDay[W];
      int points, hi, mi, hf, mf;
      scanf("%*d %d %s %d:%d %d:%d", &points, &sDay, &hi, &mi, &hf, &mf);
      week[dayOf(string(sDay))].push_back(task(points, hi * 60 + mi, hf * 60 + mf));
    }

    int res[W];
    int total = 0;
    for (int i = 0; i < W; i++) {
      sort(week[i].begin(), week[i].end(), compare);
      for (int j = 0; j < week[i].size(); j++) {
        nextOf[j] = binarySearch(i, j);
      }
      fill(dp, dp + week[i].size(), -1);
      res[i] = solve(i, 0);
      total += res[i];
    }

    printf("Total de pontos: %d\n", total);
    for (int i = 0; i < W; i++) {
      printf("%s: %d\n", days[i].c_str(), res[i]);
      week[i].clear();
    }
  }
  return 0;
}
