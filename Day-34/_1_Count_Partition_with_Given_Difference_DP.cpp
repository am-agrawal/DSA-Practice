#include <iostream>
#include <vector>
using namespace std;

// Here, we have to return the count of subsets whose difference is K
// s1 = totsum - s2
// totsum - s2 - s2 = K
// totsum - K = 2 * s2
// (totsum - K) / 2 = s2

// so we have to count the number of subsets whose sum is ((totsum - K) / 2)
// if we get (totsum - K) as either odd or less than 0
// then our answer will be 0

// Memoization
int targetSum(vector<int>& nums, int target, int idx, vector<vector<int>>& dp) {
  if(idx == 0) {
    if(nums[0] == 0 && target == 0) return 2;
    if(nums[0] == target || target == 0) return 1;
    else return 0;
  }

  if(dp[idx][target] != -1) return dp[idx][target];

  int pick = (nums[idx] <= target) ? targetSum(nums, target-nums[idx], idx-1, dp) : 0;
  int notPick = targetSum(nums, target, idx-1, dp);

  return dp[idx][target] = pick + notPick;
}

// Tabulation
// int targetSum(vector<int>& nums, int target) {
//   int n = nums.size();
//   vector<vector<int>> dp(n, vector<int>(target+1, 0));

//   if(nums[0] == 0) dp[0][0] = 2;
//   else dp[0][0] = 1;

//   if(nums[0] != 0 && nums[0] <= target) dp[0][nums[0]] = 1;

//   for(int i = 1; i < n; i++) {
//     for (int k = 0; k <= target; k++) {
//       int notTake = dp[i-1][k];
//       int take = (nums[i] <= k) ? dp[i-1][k-nums[i]] : 0;

//       dp[i][k] = take + notTake;
//     }
//   }

//   return dp[n-1][target];
// }

// Tabulation (Space Optimized)
int targetSum(vector<int>& nums, int target) {
  int n = nums.size();
  vector<int> prev(target+1, 0);

  if(nums[0] == 0) prev[0] = 2;
  else prev[0] = 1;

  if(nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1;

  for(int i = 1; i < n; i++) {
    vector<int> cur(target+1, 0);
    for (int k = 0; k <= target; k++) {
      int notTake = prev[k];
      int take = (nums[i] <= k) ? prev[k-nums[i]] : 0;

      cur[k] = take + notTake;
    }
    prev = cur;
  }

  return prev[target];
}


int subsetDiffK(vector<int>& nums, int k) {
  int totsum = 0;
  int n = nums.size();

  for(int i = 0; i < n; i++) {
    totsum += nums[i];
  }

  if((totsum - k < 0) || (totsum - k) % 2) return 0;

// Memoization
  // vector<vector<int>> dp(n, vector<int>((totsum - k) / 2 + 1, -1));
  // return targetSum(nums, (totsum - k) / 2, n-1, dp);

// Tabulation
  return targetSum(nums, (totsum - k) / 2);
}


int main() {
  vector<int> nums = {0, 0, 3, 7, 2};
  int diff = 6;

  cout << subsetDiffK(nums, diff) << endl;

  return 0;
}