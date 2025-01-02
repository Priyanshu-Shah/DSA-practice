#include <iostream>
#include <vector>
using std::vector;

// long long get_fibonacci_partial_sum_naive(long long from, long long to) {
//     long long sum = 0;

//     long long current = 0;
//     long long next  = 1;

//     for (long long i = 0; i <= to; ++i) {
//         if (i >= from) {
//             sum += current;
//         }

//         long long new_current = next;
//         next = next + current;
//         current = new_current;
//     }

//     return sum % 10;
// }

int get_fibonacci_partial_sum(long long from, long long to) {
    long long sum = 0;
    long long arr[to+1]={0};
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<to+1; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    for(int j=from; j<to+1; j++){
        sum += arr[j];
    }
    if(to = 0){
        sum = 0;
    }
    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
