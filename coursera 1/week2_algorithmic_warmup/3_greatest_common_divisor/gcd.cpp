#include <iostream>

long long gcd(long long a, long long b) {
  while(b!=0){
    long long temp = b;
    b = a%b;
    a = temp;
  }
  return a;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
