// Here we have an array of integers and we can assign each integer as positive or negative (+ or -)
// and after assigning the symbols we have to sum them
// and if the sum is equal to our target value then we will count this combination of assigning of the symbols
// And as a result we have to find the number of ways by which we get sum as our target value

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int targetSumK(int i, int tar, vector<int>& nums, vector<vector<int>>& dp) {
  if(i == 0) {
    if(nums[0] == 0 && tar == 0) return 2;
    if(nums[0] == tar || tar == nums[0]) return 1;
  }

  if(dp[i][tar] != -1) return dp[i][tar];

  int notPick = targetSumK(i-1, tar, nums, dp);
  int pick = (nums[i] <= tar) ? targetSumK(i-1, tar-nums[i], nums, dp) : 0;

  return dp[i][tar] = notPick + pick;
}

// Tabulation
// int targetSumK(int tar, vector<int>& nums) {
//   int n = nums.size();
//   vector<vector<int>> dp(n, vector<int>(tar+1, 0));

//   if(nums[0] == 0) dp[0][0] = 2;
//   else dp[0][0] = 1;

//   if(nums[0] != 0 && nums[0] <= tar) dp[0][nums[0]] = 1;

//   for(int i = 1; i < n; i++) {
//     for(int T = 0; T <= tar; T++) {
//       int pick = (nums[i] <= T) ? dp[i-1][T-nums[i]] : 0;
//       int notPick = dp[i-1][T];

//       dp[i][T] = pick + notPick;
//     }
//   }

//   return dp[n-1][tar];
// }

// Tabulation (Space Optimized)
int targetSumK(int tar, vector<int>& nums) {
  int n = nums.size();
  vector<int> prev(tar+1, 0), cur(tar+1, 0);

  if(nums[0] == 0) prev[0] = 2;
  else prev[0] = 1;

  if(nums[0] != 0 && nums[0] <= tar) prev[nums[0]] = 1;

  for(int i = 1; i < n; i++) {
    for(int T = 0; T <= tar; T++) {
      int pick = (nums[i] <= T) ? prev[T-nums[i]] : 0;
      int notPick = prev[T];

      cur[T] = pick + notPick;
    }
    prev = cur;
  }

  return prev[tar];
}

int targetSum(vector<int>& nums, int target) {
  int n = nums.size();
  int totsum = 0;
  for(int i = 0; i < n; i++) { totsum += nums[i]; }
  if((totsum - target) < 0 || (totsum - target) % 2) return 0;
  int tar = (totsum - target) / 2;
// Memoization
  // vector<vector<int>> dp(n, vector<int>(tar+1, -1));
  // return targetSumK(n-1, tar, nums, dp);

// Tabulation
  return targetSumK(tar, nums);
}

int main() {
  vector<int> nums = {1, 1, 2, 3};
  int target = 3;

  cout << targetSum(nums, target) << endl;

  return 0;
}