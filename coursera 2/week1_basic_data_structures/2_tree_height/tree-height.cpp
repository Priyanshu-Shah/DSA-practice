#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node;

class Node {
public:
    int key;
    vector<Node *> children;

    Node(int key) {
      this->key = key;
    }

    void Child(Node *child) {
      children.push_back(child);
    }
};

int main (){
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;

  vector<Node*> nodes(n);
  // for (int child_index = 0; child_index < n; child_index++) {
  //   int parent_index;
  //   cin >> parent_index;
  //   if (parent_index >= 0)
  //     nodes[child_index].setParent(&nodes[parent_index]);
  //   nodes[child_index].key = child_index;
  // }
  for(int i=0; i<n; i++){
    nodes[i] = new Node(i);
  }


  int root = -1;
  for(int childIndex = 0; childIndex < n; childIndex++){
    int parentIndex;
    cin >> parentIndex;
    if(parentIndex == -1){
      root = childIndex;
    }
    else{
      nodes[parentIndex]->Child(nodes[childIndex]);
    }
  }

  if(nodes[root] == nullptr){
    return 0;
  }
  queue<Node*> q;
  q.push(nodes[root]);
  int height = 0;
  while(q.empty() == false){
    int size = q.size();
    for(int i=0; i<size; i++){
      Node *current = q.front();
      q.pop();
      for(Node* child : current->children){
        q.push(child);
      }
    }
    height++;
  }

  cout << height << endl;

  for(int i=0; i<n; i++){
    delete nodes[i];
  }
  return 0;
}
