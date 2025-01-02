#include <iostream>

long long lcm(long long a, long long b) {
  int c = 0;
  int d = 0;
  if(a>=b){
    c = a;
    d = b;
  }
  else{
    c = b;
    d = a;
  }
  for (long long l = 1; l <= d; l++){
    if (c*l % d == 0){
      return c*l;
    }
  }
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
