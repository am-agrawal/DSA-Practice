// We have an array of integers and we need to find the length of the longest increasing subsequence
// Example -> [10, 9, 2, 5, 3, 7, 101, 18] => output -> 4 as [2, 5, 7, 101] is the LIS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Memoization
// Time => O(n * n)
// Space => O(n * n) + O(n)
int LIS(int i, vector<int>& nums, int prev, vector<vector<int>>& dp) {
  if(i == nums.size()) return 0;

  if(dp[i][prev+1] != -1) return dp[i][prev+1];

  int notTake = LIS(i+1, nums, prev, dp);
  int take = (prev == -1 || nums[i] > nums[prev]) ? LIS(i+1, nums, i, dp) + 1 : 0;

  return dp[i][prev + 1] = max(take, notTake);
}

// Tabulation
// Time => O(n * n)
// Space => O(n * n)
// int LIS(vector<int>& nums) {
//   int n = nums.size();
//   vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

//   for(int i = n-1; i >= 0; i--) {
//     for(int prev = i-1; prev >= -1; prev--) {
//       int notTake = dp[i+1][prev+1];
//       int take = (prev == -1 || nums[i] > nums[prev]) ? dp[i+1][i+1] + 1 : 0;
//       dp[i][prev+1] = max(take, notTake);
//     }
//   }

//   return dp[0][0];
// }

// Tabulation (Space Optimized)
// Time => O(n * n)
// Space => O(n)
// int LIS(vector<int>& nums) {
//   int n = nums.size();
//   vector<int> after(n+1, 0), cur(n+1, 0);

//   for(int i = n-1; i >= 0; i--) {
//     for(int prev = i-1; prev >= -1; prev--) {
//       int notTake = after[prev+1];
//       int take = (prev == -1 || nums[i] > nums[prev]) ? after[i+1] + 1 : 0;
//       cur[prev+1] = max(take, notTake);
//     }
//     after = cur;
//   }

//   return after[0];
// }

// It will print the LIS
// Time => O(n * n) O(k + n)
// Space => O(2n)
// int LIS(vector<int>& nums) {
//   int n = nums.size(), res = 0, resInd = -1;
//   vector<int> freq(n, 1), hash(n), ans;
//   for(int i = 0; i < n; i++) {
//     hash[i] = i;
//     for(int j = 0; j < i; j++) {
//       if(nums[j] < nums[i] && freq[j] + 1 > freq[i]) {
//         freq[i] = freq[j] + 1;
//         hash[i] = j;
//       }
//     }
//     if(freq[i] > res) {
//       res = freq[i];
//       resInd = i;
//     }
//   }

//   int k = res;
//   while(k--) {
//     ans.push_back(nums[resInd]);
//     resInd = hash[resInd];
//   }
//   reverse(ans.begin(), ans.end());
//   for(auto x : ans) { cout << x << " "; }
//   cout << endl;

//   return res;
// }


// Time => O(n * logn)
// Space => O(n)
int LIS(vector<int>& nums) {
  int n = nums.size(), res = 1;
  vector<int> temp;
  temp.push_back(nums[0]);
  for(int i = 1; i < n; i++) {
    if(nums[i] > temp.back()) {
      temp.push_back(nums[i]);
      res++;
    } else {
      vector<int>::iterator it = lower_bound(temp.begin(), temp.end(), nums[i]);
      temp[it - temp.begin()] = nums[i];
    }
  }
  return res;
}

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  int n = nums.size();

// Memoization
  // vector<vector<int>> dp(n, vector<int>(n+1, -1));
  // cout << LIS(0, nums, -1, dp);

// Tabulation
  cout << LIS(nums) << endl;

  return 0;
}