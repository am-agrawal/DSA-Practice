// Here it is the follow up problem of 0|1 knapsack
// Here we can take an item infinite number of times

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxProfit(int i, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
  if(W == 0) return 0;
  if(i == 0) return val[0] * (W / wt[0]);

  if(dp[i][W] != -1) return dp[i][W];

  int pick = (W >= wt[i]) ? maxProfit(i, W-wt[i], val, wt, dp) + val[i] : 0;
  int notPick = maxProfit(i-1, W, val, wt, dp);

  return dp[i][W] = max(pick, notPick);
}

// Tabulation
// int maxProfit(int W, vector<int>& val, vector<int>& wt) {
//   int n = val.size();
//   vector<vector<int>> dp(n, vector<int>(W+1, 0));

//   for(int w = 0; w <= W; w++) {
//     dp[0][w] = val[0] * (w / wt[0]);
//   }

//   for(int i = 1; i < n; i++) {
//     for(int w = 0; w <= W; w++) {
//       int notPick = dp[i-1][w];
//       int pick = (w >= wt[i]) ? dp[i][w-wt[i]] + val[i] : 0;

//       dp[i][w] = max(pick, notPick);
//     }
//   }

//   return dp[n-1][W];
// }

// Tabulation (Space Optimized)
int maxProfit(int W, vector<int>& val, vector<int>& wt) {
  int n = val.size();
  vector<int> prev(W+1, 0);

  for(int w = 0; w <= W; w++) {
    prev[w] = val[0] * (w / wt[0]);
  }

  for(int i = 1; i < n; i++) {
    for(int w = 0; w <= W; w++) {
      int notPick = prev[w];
      int pick = (w >= wt[i]) ? prev[w-wt[i]] + val[i] : 0;

      prev[w] = max(pick, notPick);
    }
  }

  return prev[W];
}

int main() {
  vector<int> values = {5, 11, 13};
  vector<int> weights = {2, 4, 6};
  int n = values.size();
  int W = 10;

// Memoization
  // vector<vector<int>> dp(n, vector<int>(W+1, -1));
  // cout << maxProfit(n-1, W, values, weights, dp) << endl;

// Tabulation
  cout << maxProfit(W, values, weights) << endl;

  return 0;
}