#include <iostream>

int get_fibonacci_last_digit_naive(long long n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (long long i = 2; i < n+1; ++i) {
        long long tmp = current;
        current = (previous+current)%10;
        previous = tmp;
    }

    return current % 10;
}

int main() {
    long long n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
