#include <iostream>
#include <vector>
using namespace std;

// Memoization
int knapsack(int i, int wt, vector<int>& value, vector<int>&weight, vector<vector<int>>& dp) {
  if(i == 0) return (weight[0] <= wt) ? value[0] : 0;

  if(dp[i][wt] != -1)  return dp[i][wt];

  int notPick = knapsack(i-1, wt, value, weight, dp);
  int pick = (weight[i] <= wt) ? knapsack(i-1, wt-weight[i], value, weight, dp) + value[i] : 0;

  return dp[i][wt] = max(pick, notPick);
}

// Tabulation
// int knapsack(int wt, vector<int>& value, vector<int>& weight) {
//   int n = value.size();
//   vector<vector<int>> dp(n, vector<int>(wt+1, 0));

//   for(int W = weight[0]; W <= wt; W++) {
//     dp[0][W] = value[0];
//   }

//   for(int i = 1; i < n; i++) {
//     for(int W = 0; W <= wt; W++) {
//       int notPick = dp[i - 1][W];
//       int pick = (weight[i] <= W) ? dp[i - 1][W - weight[i]] + value[i] : 0;

//       dp[i][W] = max(pick, notPick);
//     }
//   }

//   return dp[n-1][wt];
// }

// Tabulation (Space Optimized)
int knapsack(int wt, vector<int>& value, vector<int>& weight) {
  int n = value.size();
  vector<int> prev(wt+1, 0);

  for(int W = weight[0]; W <= wt; W++) {
    prev[W] = value[0];
  }

  for(int i = 1; i < n; i++) {
    for(int W = wt; W >= 0; W--) {
      int notPick = prev[W];
      int pick = (weight[i] <= W) ? prev[W - weight[i]] + value[i] : 0;

      prev[W] = max(pick, notPick);
    }
  }

  return prev[wt];
}


int main() {
  vector<int> value = {30, 40, 60};
  vector<int> weight = {2, 3, 4};
  int maxWeight = 5;

  int n = value.size();

// Memoization
  // vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
  // cout << knapsack(n-1, maxWeight, value, weight, dp) << endl;

// Tabulation
  cout << knapsack(maxWeight, value, weight) << endl;

  return 0;
}