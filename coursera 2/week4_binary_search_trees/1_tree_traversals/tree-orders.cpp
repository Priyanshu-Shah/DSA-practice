#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

  void in_order_r(int n, vector<int> &result){
    if(n == -1){
      return;
    }
    in_order_r(left[n], result);
    result.push_back(key[n]);
    in_order_r(right[n], result);
  }

  void pre_order_r(int n, vector<int> &result){
    if(n == -1){
      return;
    }
    result.push_back(key[n]);
    pre_order_r(left[n], result);
    pre_order_r(right[n], result);
  }

  void post_order_r(int n, vector<int> &result){
    if(n == -1){
      return;
    }
    post_order_r(left[n], result);
    post_order_r(right[n], result);
    result.push_back(key[n]);
  }

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    vector<int> result;
    in_order_r(0,result);
    return result;
  }

  vector <int> pre_order() {
    vector<int> result;    
    pre_order_r(0,result);
    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    post_order_r(0, result);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main (){
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

