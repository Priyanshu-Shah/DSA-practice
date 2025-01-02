#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    long long arr[n+1] = {0};
    arr[0] = 0;
    arr[1] = 1;
    for(long long i=2; i<n+1; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    long long current = arr[n];
    std::cout<< current <<'\n';
    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
