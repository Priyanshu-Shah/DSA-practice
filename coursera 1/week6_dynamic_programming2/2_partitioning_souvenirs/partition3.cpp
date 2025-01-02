#include <iostream>
#include <vector>

using namespace std;

bool partition3(vector<int> &A, int n) {
  int sum = 0;
  for(int i=0; i<n; i++){
    sum += A[i];
  }
  if(sum%3!=0){
    return false;
  }
  int target = sum/3;
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (target+1, vector<int> (target+1,false)));
  dp[0][0][0] = true;
  for(int i=1; i<n+1; i++){
    int num = A[i-1];
    for(int j=target; j>=0; j--){
      for(int k=target; k>=0; k--){
        if(j>=num && dp[i-1][j-num][k]){
          dp[i][j][k] = true;
        }
        if(k >= num && dp[i - 1][j][k - num]){
          dp[i][j][k] = true;
        }
        if(dp[i - 1][j][k]){
          dp[i][j][k] = true;
        }
      }
    }
  }
  return dp[n][target][target];
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    cin >> A[i];
  }
  cout << partition3(A, n) << '\n';
  return 0;
}


// #include <iostream>
// #include <vector>
// #include <numeric>
// using namespace std;

// bool canPartitionIntoThreeSubsets(const vector<int>& nums) {
//     int total_sum = accumulate(nums.begin(), nums.end(), 0);
//     if (total_sum % 3 != 0) return false;

//     int target = total_sum / 3;
//     int n = nums.size();
//     vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(target + 1, vector<bool>(target + 1, false)));
//     dp[0][0][0] = true;

//     for (int i = 1; i <= n; ++i) {
//         int current = nums[i - 1];
//         for (int j = target; j >= 0; --j) {
//             for (int k = target; k >= 0; --k) {
//                 if (j >= current && dp[i - 1][j - current][k]) {
//                     dp[i][j][k] = true;
//                 }
//                 if (k >= current && dp[i - 1][j][k - current]) {
//                     dp[i][j][k] = true;
//                 }
//                 if (dp[i - 1][j][k]) {
//                     dp[i][j][k] = true;
//                 }
//             }
//         }
//     }
//     return dp[n][target][target];
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//     }
//     cout << (canPartitionIntoThreeSubsets(nums) ? 1 : 0) << endl;
//     return 0;
// }
