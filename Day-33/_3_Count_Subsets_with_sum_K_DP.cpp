// Here we have an array of integers
// We need to count the subsets whose sum is equal to target

#include <iostream>
#include <vector>
using namespace std;

// It will work fine when the numbers starts from 1
// But when the numbers starts from 0 then a little change will be required

// if(i == 0) {
//   if(sum == 0 && nums[0] == 0) return 2;
//   if(sum == 0 || sum == arr[0]) return 1;
//   else return 0;
// }

// And now with this code, it will work fine

// Memoization
int countSubsets(int i, int k, vector<int> &nums, vector<vector<int>>& dp) {
  if(k == 0) return 1;
  if(i == 0) return k == nums[0];

  if(dp[i][k] != -1) return dp[i][k];

  int res = 0;

  // pick
  res += (nums[i] <= k) ? countSubsets(i-1, k-nums[i], nums, dp) : 0;

  // not pick
  res += countSubsets(i-1, k, nums, dp);

  return dp[i][k] = res;
}


// Tabulation
// int countSubsets(vector<int>& nums, int k) {
//   int n = nums.size();
//   vector<vector<int>> dp(n, vector<int>(k+1, 0));

//   for(int i = 0; i < n; i++) {
//     dp[i][0] = 1;
//   }

//   if(nums[0] <= k) dp[0][nums[0]] = 1;

//   for(int i = 1; i < n; i++) {
//     for(int target = 1; target <= k; target++) {
//       int notTake = dp[i-1][target];
//       int take = (nums[i] <= target) ? dp[i-1][target-nums[i]] : 0;

//       dp[i][target] = take + notTake;
//     }
//   }

//   return dp[n-1][k];
// }


// Tabulation (Space Optimized)
int countSubsets(vector<int>& nums, int k) {
  int n = nums.size();
  vector<int> prev(k+1, 0);

  prev[0] = 1;

  if(nums[0] <= k) prev[nums[0]] = 1;

  for(int i = 1; i < n; i++) {
    vector<int> cur(k + 1, 0);
    cur[0] = 1;
    for(int target = 1; target <= k; target++) {
      int notTake = prev[target];
      int take = (nums[i] <= target) ? prev[target-nums[i]] : 0;

      cur[target] = take + notTake;
    }
    prev = cur;
  }

  return prev[k];
}


int main() {
  vector<int> nums = {1, 2, 2, 3};
  int target = 3;
  int n = nums.size();

// Memoization
  // vector<vector<int>> dp(n, vector<int>(target+1, -1));
  // cout << countSubsets(n-1, target, nums, dp) << endl;

// Tabulation
  cout << countSubsets(nums, target) << endl;

  return 0;
}