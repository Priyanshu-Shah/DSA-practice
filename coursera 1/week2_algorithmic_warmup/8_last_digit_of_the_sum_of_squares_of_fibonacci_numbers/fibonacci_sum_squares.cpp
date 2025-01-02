#include <iostream>

// int fibonacci_sum_squares_naive(long long n) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current * current;
//     }

//     return sum % 10;
// }

int fibonacci_sum_squares(long long n) {
    long long arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    long long sum = 1;
    for(long long i=2; i<n+1; i++){
        arr[i] = arr[i-1] + arr[i-2];
        sum += (arr[i])*(arr[i]);
    }
    if(n==0){
        sum = 0;
    }
    std::cout << sum << '\n';
    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
