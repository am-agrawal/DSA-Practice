// Here we have an array of integers
// And we need to partition it in at most K size in such way that we get max sum
// Example => [1, 15, 7, 9, 2, 5, 10] & K = 3
// [1, 15, 7 | 9 | 2, 5, 10] => [15, 15, 15 | 9 | 10, 10, 10]
// Sum => 84

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxSum(int i, int n, int k, vector<int>& nums, vector<int>&dp) {
  if(i == n) return 0;

  if(dp[i] != -1) return dp[i];

  int maxNum = INT_MIN, maxi = INT_MIN, len = 0;
  for(int j = i; j < min(i+k, n); j++) {
    len++;
    maxNum = max(maxNum, nums[j]);
    int sum = (maxNum * len) + maxSum(j+1, n, k, nums, dp);
    maxi = max(maxi, sum);
  }

  return dp[i] = maxi;
}

// Tabulation
int maxSum(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int> dp(n+1, 0);

  for(int i = n-1; i >= 0; i--) {
    int maxNum = INT_MIN, maxi = INT_MIN, len = 0;
    for (int j = i; j < min(i + k, n); j++) {
      len++;
      maxNum = max(maxNum, nums[j]);
      int sum = (maxNum * len) + dp[j + 1];
      maxi = max(maxi, sum);
    }

    dp[i] = maxi;
  }

  return dp[0];
}

int main() {
  vector<int> nums = {1, 15, 7, 9, 2, 5, 10};
  int n = nums.size();
  int k = 3;

// Memoization
  // vector<int> dp(n, -1);
  // cout << maxSum(0, n, k, nums, dp) << endl;

// Tabulation
  cout << maxSum(nums, k) << endl;

  return 0;
}