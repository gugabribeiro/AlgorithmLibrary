//O(n log2(n))

#include <bits/stdc++.h>

const int MAXN = 1010;

using namespace std;

int arr[MAXN];

void quickSort(int left, int right) {
  if (left < right) {
    int pivot = left,
        pivotElement = arr[left];

    for (int i = left + 1; i <= right; i++) {
      if (arr[i] <= pivotElement) {
        pivot++;
        swap(arr[i], arr[pivot]);
      }
    }

    swap(arr[pivot], arr[left]);

    quickSort(left, pivot - 1);
    quickSort(pivot + 1, right);
  }
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", arr + i);

  quickSort(0, n - 1);

  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", arr[i]);
  }

  putchar('\n');

  return 0;
}
