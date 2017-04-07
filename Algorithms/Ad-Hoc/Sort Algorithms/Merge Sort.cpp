#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef long long lint;

int a[N], ax[N];

//Sorting array "a" and return the numbers of invertions of "a"
//The number of invertions is the number of indices 1 <= i, j <= n such that i < j and a[i] > a[j]
//This number can not fit in an integer of 32 bits
lint mergeSort(int lo, int hi) {
  if (lo >= hi)
    return 0;

  int md = (lo + hi) / 2;
  
  lint res = mergeSort(lo, md) + mergeSort(md + 1, hi);

  int k = lo, j = md + 1;
  for (int i = lo; i <= md; i++) {
    while (j <= hi and a[i] > a[j]) {
      ax[k++] = a[j++];
      res += lint(md - i + 1); //counting the number of inversions
    }
    ax[k++] = a[i];
  }

  while (j <= hi)
    ax[k++] = a[j++];

  for (int i = lo; i <= hi; i++)
    a[i] = ax[i];

  return res;
}

int main() {
  int n;
  
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    printf("%lld invertions\n", mergeSort(0, n - 1));
    for (int i = 0; i < n; i++)
      printf("%d ", a[i]);
    printf("\n");
  }

  return 0;
}
