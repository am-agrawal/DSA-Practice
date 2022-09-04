// Here we have an array of integers Cost
// cost[i] is the cut point and the cost will be the current length of rope
// We need to find the minimum total cost to cut the rope at all points mentioned in cost array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Memoization
int minCost(int i, int j, vector<int>& cost, vector<vector<int>>& dp) {
  if(i > j) return 0;

  if(dp[i][j] != -1) return dp[i][j];;

  int mini = INT_MAX;
  for(int k = i; k <= j; k++) {
    int c = cost[j+1] - cost[i-1] + minCost(i, k-1, cost, dp) + minCost(k+1, j, cost, dp);
    mini = min(mini, c);
  }
  return dp[i][j] = mini;
}

// Tabulation
int minCost(vector<int>& cost, int n) {
  vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

  for(int i = n; i >= 1; i--) {
    for(int j = i; j <= n; j++) {
      int mini = INT_MAX;
      for (int k = i; k <= j; k++) {
        int c = cost[j + 1] - cost[i - 1] + dp[i][k - 1] + dp[k + 1][j];
        mini = min(mini, c);
      }
      dp[i][j] = mini;
    }
  }
  return dp[1][n];
}

int main() {
  vector<int> cost = {1, 2, 3, 5, 7, 8};
  int len = 12;
  int n = cost.size();

  sort(cost.begin(), cost.end());
  cost.push_back(len);
  cost.insert(cost.begin(), 0);

// Memoization
  // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
  // cout << minCost(1, n, cost, dp) << endl;

// Tabulation
  cout << minCost(cost, n) << endl;

  return 0;
}