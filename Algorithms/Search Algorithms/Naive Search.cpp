//O(n)

#include <bits/stdc++.h>

const int MAXN = 100010;

using namespace std;

int arr[MAXN];

int naiveSearch(int n, int element){
  for(int i = 0; i < n; i++){
    if(arr[i] == element){
      return i;
    }
  }
  return -1;
}

int main(){
  int n, element;

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", arr + i);
  }

  scanf("%d", &element);

  printf("%d\n", naiveSearch(n, element));

  return 0;
}
