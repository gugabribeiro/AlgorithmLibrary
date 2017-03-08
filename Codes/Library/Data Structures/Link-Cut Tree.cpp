#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node left, right, parent;
  bool revert;

  Node() {}

  bool isRoot() {
    return parent == NULL or (parent.left != this and parent.right != this);    
  }

  void push() {

  }
};

int main() {

  return 0;
}