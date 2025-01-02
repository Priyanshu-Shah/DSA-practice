#include <iostream>
#include <vector>

using std::vector;

int find_max(int n, vector<double> val){
  int max_in = 0;
  for(int i=0; i<n; i++){
    if(val[i] > val[max_in]){
      max_in = i;
    }
  }
  return max_in;
}

int max_weight(int max_in, int n, vector<double> val, int capacity, vector<int> weights, vector<int> values){
  int weight_to_take = std::min(weights[max_in], capacity);
  return weight_to_take;
}

void remove_item(int n, vector<double> val, int max_in, vector<int> weights, vector<int> values){
  val[max_in] = 0;
  weights[max_in] = 0;
  values[max_in] = 0;
}

double get_optimal_value(int capacity, vector<int>& weights, vector<int>& values, int n) {
  double value = 0.0;
  vector<double> val(n);

  for(int i=0; i<n; i++){
    val[i] = (double)values[i] / weights[i];
  }

  while(capacity > 0){
    int max_in = find_max(n ,val);
    int max_w = max_weight(max_in, n, val, capacity, weights, values);
    capacity -= max_w;
    value += (max_w * values[max_in]);
    weights[max_in] = 0;
    val[max_in] = 0.0; 
    }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
