#include <iostream>
#include <vector>
using namespace std;

// Here, we have an Array of integers, ex => [1, 2, 4, 6]
// And we have to find the maximum sum of non adjacent integers
// [1, 2, 4, 6]
// * [1, 4] => 5
// * [2, 6] => 8
// So our answer will be 8

// vector<int> dp;

// Memoization
// Time => O(n)
// Space => O(n) + O(n)
// int maxNonAdjSum(int n, vector<int>& nums) {
//   if(n == 0) return nums[0];
//   if(dp[n] != -1) return dp[n];

//   int take = nums[n] + (n > 1 ? maxNonAdjSum(n-2, nums) : 0);
//   int notTake = maxNonAdjSum(n-1, nums);

//   return dp[n] = max(take, notTake);
// }

// Tabulation
// Time => O(n)
// Space => O(n)
// int maxNonAdjSum(int n, vector<int>& nums) {
//   vector<int> dp(n+1);
//   dp[0] = nums[0];
//   for(int i = 1; i <= n; i++) {
//     int take = nums[i] + (i > 1 ? dp[i-2] : 0);
//     int notTake = dp[i-1];

//     dp[i] = max(take, notTake);
//   }

//   return dp[n];
// }

// Tabulation (Space Optimized)
// Time => O(n)
// Space => O(1)
int maxNonAdjSum(int n, vector<int>& nums) {
  int prev = nums[0];
  int prev2 = 0;

  for(int i = 1; i <= n; i++) {
    int take = nums[i] + prev2;
    int notTake = prev;

    int mx = max(take, notTake);

    prev2 = prev;
    prev = mx;
  }

  return prev;
}

int main() {
  vector<int> nums = {3, 2, 4, 6};
  int n = nums.size();
  // dp.resize(n, -1);

  cout << maxNonAdjSum(n-1, nums) << endl;

  return 0;
}