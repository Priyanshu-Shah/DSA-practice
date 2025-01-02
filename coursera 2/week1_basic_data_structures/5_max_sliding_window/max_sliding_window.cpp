#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> max_sliding_window_naive(vector<int> const & A, int w) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < A.size(); i++) {
        if(dq.empty() == false && dq.front() == i-w){
            dq.pop_front();
        }
        while(dq.empty() == false && A[dq.back()] <= A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=w-1){
            result.push_back(A[dq.front()]);
        }
    }

    return result;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    vector<int> answer = max_sliding_window_naive(A, w);
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
    
    return 0;
}
