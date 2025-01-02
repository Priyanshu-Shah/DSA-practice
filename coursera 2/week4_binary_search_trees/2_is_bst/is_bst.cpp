#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  long long key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool in_order(int n, const vector<Node> &tree, long long min_val, long long max_val){
  if(n == -1){
    return true;
  }
  if(tree[n].key <= min_val || tree[n].key >= max_val){
    return false;
  }
  return in_order(tree[n].left, tree, min_val, tree[n].key) && in_order(tree[n].right, tree, tree[n].key, max_val);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  if (tree.empty()) {
    return true;
  }
  long long max_val = numeric_limits<long long>::max();
  long long min_val = numeric_limits<long long>::min();
  return in_order(0, tree, min_val, max_val);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
