//O(n²)

#include <bits/stdc++.h>

const int MAXN = 1010;

using namespace std;

int arr[MAXN];

void bubbleSort(int n) {
  for (int i = n - 1; i > 0; i--)
    for (int j = 0; j < i; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", arr + i);

  bubbleSort(n);

  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", arr[i]);
  }

  putchar('\n');

  return 0;
}
