//O(log2 n) if array is sorted

#include <bits/stdc++.h>

const int MAXN = 100010;

using namespace std;

struct cell {
  int id, element;
  cell() {}
} arr[MAXN];

//QuickSort Algorithm O(n log2 n)
void quickSort(int left, int right) {
  if (left < right) {
    int pivot = left,
        pivotElement = arr[left].element;

    for (int i = left + 1; i <= right; i++)
      if (arr[i].element <= pivotElement) {
        pivot++;
        swap(arr[i], arr[pivot]);
      }

    swap(arr[pivot], arr[left]);

    quickSort(left, pivot - 1);
    quickSort(pivot + 1, right);
  }
}

/*
To Lower Bound Search:
if(arr[mid].element == element){
  int x = binarySearch(left, mid - 1, element);
  x == -1 ? mid : x;
*/

/*
To Upper Bound Search:
if(arr[mid].element == element){
  int x = binarySearch(mid + 1, right, element);
  x == -1 ? mid : x;
*/

int binarySearch(int left, int right, int element) {
  int mid = (left + right) >> 1;

  if (left > right)
    return -1;

  if (arr[mid].element == element)
    return arr[mid].id;
  else if (arr[mid].element < element)
    return binarySearch(mid + 1, right, element);
  else
    return binarySearch(left, mid - 1, element);
}

int main() {
  int n, element;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].element);
    arr[i].id = i;
  }

  //Sort the Array
  quickSort(0, n - 1);

  scanf("%d", &element);

  printf("%d\n", binarySearch(0, n - 1, element));

  return 0;
}
