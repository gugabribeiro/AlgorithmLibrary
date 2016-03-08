#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//Segment tree Node
struct Node {
  ll value, lazy;
  Node() {}
  Node(ll _value, ll _lazy):
    value(_value), lazy(_lazy) {}

  void merge(const Node &l, const Node &r) {
    value = l.value + r.value;
  }
}

struct SegmentTree {
  const static int MAXN = 112345; //Adjust if necessary

  #define LEFT(i)  ((i << 1) + 1)
  #define RIGHT(i) ((i << 1) + 2)
  #define MID(left, right) ((left + right) >> 1)

  Node tree[MAXN << 2];
  int arr[MAXN];

  SegmentTree() {}

  SegmentTree(int n, int *_arr) {
    n = n; arr = _arr;
    buildTree(0, 0, n - 1);
  }

  void buildTree(int i, int left, int right) {
    if (left == right) {
      tree[i].value = arr[left];
      tree[i].lazy = 0;
    } else {
      int mid = MID(left, right);

      buildTree(LEFT(i), left, mid);
      buildTree(RIGHT(i), mid + 1, right);

      tree[i].merge(tree[LEFT(i)], tree[RIGHT(i)]);
    }
  }

  void doLazy(int i, int left, int right) {
    if (tree[i].lazy) {
      tree[i].value += (right - left + 1) * tree[i].lazy;
      if (left != right) {
        tree[LEFT(i)].lazy += tree[i].lazy
        tree[RIGHT(i)].lazy += tree[i].lazy;
      }
      tree[i].lazy = 0;
    }
  }

  void update (int i, int left, int right, int x, int y, ll val) {
    doLazy(i, left, right);

    if(right < x || left > y){
      return;
    }else if(left >= x && right <= y){
      tree[i].lazy += val;
      doLazy(i, left, right);
    }else{
      int mid = MID(left, right);

      update(LEFT(i), left, mid, x, y, val);
      update(RIGHT(i), mid + 1, right, x, y, val);

      tree[i].merge(tree[LEFT(i)], tree[RIGHT(i)]);
    }
  }

  ll query(int i, int left, int right, int x, int y) {
    doLazy(i, left, right);

    if (right < x || left > y)
      return 0;
    else if(left >= x && right <= y){
      return tree[i].value;
    else {
      int mid = MID(left, right);

      return query(LEFT(i), left, mid, x, y) +
             query(RIGHT(i), mid + 1, right, x, y);
    }
  }
};

int main(){
  return 0;
}
