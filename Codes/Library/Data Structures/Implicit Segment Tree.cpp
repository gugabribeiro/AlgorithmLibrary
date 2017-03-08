#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

struct Node {
  Node *left;
  Node *right;
  lint value;

  Node() {}
  Node(lint value_): 
    left(NULL), right(NULL), value(value_) {}
};

lint get(Node* node) {
  if (!node)
    return 0;
  return node->value;
}

lint query(Node* node, int lo, int hi, int i, int j) {
    if (!node)
    return 0;
  else if (hi < i or lo > j)
    return 0;
  else if (lo >= i and hi <= j)
    return node->value;  
  else {
    int md = (lo + hi) / 2;
    return max(query(node->left, lo, md, i, j), 
               query(node->right, md + 1, hi, i, j));
  }
}

Node* update(Node* node, int lo, int hi, int p, lint value) {
  if (!node)
    node = new Node();
  if (lo == hi)
    node->value += value;
  else {
    int md = (lo + hi) / 2;

    if (p <= md)
      node->left = update(node->left, lo, md, p, value);
    else
      node->right = update(node->right, md + 1, hi, p, value);

    node->value = max(get(node->left), get(node->right));
  }

  return node;
}

struct ring {
  int a, b, h;
  ring() {}

  bool operator < (const ring& other) const {
    if (b == other.b)
      return a < other.a;
    return b < other.b;
  }
} rings[N];

const int MAX = 1e9;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d %d %d", &rings[i].a, &rings[i].b, &rings[i].h);

  sort(rings, rings + n);   

  lint ans = 0;
  Node* root = new Node();
  for (int i = 0; i < n; i++) {
    lint res = query(root, 0, MAX, rings[i].a + 1, rings[i].b) + rings[i].h;
    ans = max(ans, res);
    update(root, 0, MAX, rings[i].b, res);
  }

  printf("%lld\n", ans);

  return 0;
}