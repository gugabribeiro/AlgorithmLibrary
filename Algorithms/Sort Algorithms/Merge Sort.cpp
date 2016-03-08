//O(n log2(n))

#include <bits/stdc++.h>

const int MAXN = 1010;

using namespace std;

int arr[MAXN], aux[MAXN];

void mergeSort(int left, int right) {
  if (left != right) {
    int mid = (left + right) >> 1;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    int k = left,
        j = mid + 1;

    for (int i = left; i <= mid; i++) {
      while (j <= right && arr[j] < arr[i])
        aux[k++] = arr[j++];
      aux[k++] = arr[i];
    }

    while (j <= right)
      aux[k++] = arr[j++];

    for (int i = left; i <= right; i++)
      arr[i] = aux[i];
  }
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", arr + i);

  mergeSort(0, n - 1);

  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", arr[i]);
  }

  putchar('\n');

  return 0;
}
