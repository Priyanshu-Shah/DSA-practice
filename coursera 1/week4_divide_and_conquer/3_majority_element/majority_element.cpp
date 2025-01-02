#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int count(const vector<int> &a, int left, int right, int element) {
    int cnt = 0;
    for(int i = left; i < right; i++) {
        if(a[i] == element) {
            cnt++;
        }
    }
    return cnt;
}

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    
    int mid = left + ((right - left)/2);
    int left_majority = get_majority_element(a, left, mid);
    int right_majority = get_majority_element(a, mid, right);

    int left_count = count(a, left, right, left_majority);
    int right_count = count(a, left, right, right_majority);

    if (left_count > (right - left) / 2) {
        return left_majority;
    }
    if(right_count > (right - left) / 2){
        return right_majority;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }

    int majority_element = get_majority_element(a, 0, a.size());
    if (majority_element != -1) {
        int count_majority = count(a, 0, a.size(), majority_element);
        if (count_majority > a.size()/2) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    } else {
        std::cout << "0";
    }

    return 0;
}
