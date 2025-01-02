#include <iostream>

int get_change(int m) {
  int steps = 0;
  while(m-10>=0){
    steps++;
    m-=10;
  }
  while(m-5 >=0){
    steps++;
    m-=5;
  }
  while(m-1 >= 0){
    steps++;
    m-=1;
  }
  return steps;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
