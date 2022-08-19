#include <iostream>
#include <vector>
using namespace std;

// Memoization
bool subsetSum(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
  if(target == 0) return true;
  if(i == 0) return nums[0] == target;

  if(dp[i][target] != -1) return dp[i][target];

  if(target >= nums[i])
    if (subsetSum(i - 1, target - nums[i], nums, dp))
      return dp[i][target] = 1;
  if(subsetSum(i-1, target, nums, dp))
    return dp[i][target] = 1;

  return dp[i][target] = 0;
}


// Tabulation
// bool subsetSum(vector<int>& nums, int target) {
//   int n = nums.size();
//   vector<vector<bool>> dp(n, vector<bool>(target+1, false));

//   for(int i = 0; i < n; i++) {
//     dp[i][0] = true;
//   }

//   dp[0][nums[0]] = true;

//   for(int i = 1; i < n; i++) {
//     for(int k = 1; k <= target; k++) {
//       bool notTake = dp[i-1][k];
//       bool take = (nums[i] <= k) ? dp[i-1][k-nums[i]] : false;
//       dp[i][k] = notTake | take;
//     }
//   }

//   return dp[n-1][target];
// }

// Tabulation (Space Optimized)
bool subsetSum(vector<int>& nums, int target) {
  int n = nums.size();
  vector<bool> prev(target+1, false);

  prev[0] = true;

  prev[nums[0]] = true;

  for(int i = 1; i < n; i++) {
    vector<bool> cur(target+1, false);
    cur[0] = true;
    for(int k = 1; k <= target; k++) {
      bool notTake = prev[k];
      bool take = (nums[i] <= k) ? prev[k-nums[i]] : false;
      cur[k] = notTake | take;
    }
    prev = cur;
  }

  return prev[target];
}

int main() {
  vector<int> nums = {4, 3, 7};
  int target = 11;
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(target+1, -1));

// Memoization
  // cout << subsetSum(n-1, target, nums, dp) << endl;

// Tabulation
  cout << subsetSum(nums, target) << endl;

  return 0;
}