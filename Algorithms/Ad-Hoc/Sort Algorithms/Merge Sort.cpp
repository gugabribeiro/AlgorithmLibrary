#include <bits/stdc++.h>

using namespace std;

long long merge_sort(vector<int> &array, int from, int to) {
  if (from >= to) {
    return 0;
  } else {
    int mid = (from + to) / 2;
    
    long long inv = merge_sort(array, from, mid) +
                    merge_sort(array, mid + 1, to);
    
    int len = to - from + 1, i = from, j = mid + 1, k = 0;
    vector<int> sorted_array(len);

    while (k < len) {
      if (i <= mid and j <= to) {
        if (array[i] < array[j]) {
          sorted_array[k] = array[i];
          ++i;
        } else {
          inv += (mid - i + 1);
          sorted_array[k] = array[j];
          ++j;
        }
      } else if (i <= mid) {
        sorted_array[k] = array[i];
        ++i;
      } else {
        sorted_array[k] = array[j];
        ++j;
      }
      ++k;
    }

    for (int i = from; i <= to; ++i) {
      array[i] = sorted_array[i - from];
    }

    return inv;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> array(n);
  for (auto &i : array) {
    scanf("%d", &i);
  }
  return !printf("%lld\n", merge_sort(array, 0, array.size() - 1));
}
