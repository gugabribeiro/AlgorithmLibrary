//O(n²)

#include <bits/stdc++.h>

const int MAXN = 1010;

using namespace std;

int arr[MAXN];

void selectionSort(int n) {
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = i; j < n; j++)
      if (arr[j] < arr[k])
        k = j;
    if (k != i)
      swap(arr[i], arr[k]);
  }
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", arr + i);

  selectionSort(n);

  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", arr[i]);
  }

  putchar('\n');

  return 0;
}
