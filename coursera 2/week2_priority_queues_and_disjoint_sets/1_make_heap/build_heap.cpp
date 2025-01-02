#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  void SiftDown(int i){
    int minIndex = i;
    int l = 2*i + 1; //because array has 0 based indexing 
    if(l < data_.size() && data_[l] < data_[minIndex]){
      minIndex = l;
    }
    int r = 2*i + 2; 
    if(r<data_.size() && data_[r] < data_[minIndex]){
      minIndex = r;
    }
    if(minIndex != i){
      swap(data_[i], data_[minIndex]);
      swaps_.push_back(make_pair(i, minIndex));
      SiftDown(minIndex);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    int n = data_.size();
    for(int i = (n/2)-1; i >= 0; i--){
      SiftDown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
