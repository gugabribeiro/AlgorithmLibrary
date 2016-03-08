//O(n²)

#include <bits/stdc++.h>

const int MAXN = 1010;

using namespace std;

int arr[MAXN];

void insertionSort(int n) {
  for (int i = 1; i < n; i++) {
    int choosen = arr[i];
    int j = i - 1;

    while (j >= 0 && chosen < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = chosen;
  }
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", arr + i);

  insertionSort(n);

  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", arr[i]);
  }

  putchar('\n');

  return 0;
}
