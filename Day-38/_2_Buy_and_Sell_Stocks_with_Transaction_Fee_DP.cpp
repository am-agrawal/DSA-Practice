// Here this problem is similar to Buy and sell stocks II with a little modification
// We have to subtract TransFee like prices[i] at buying

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxProfit(int i, bool buy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
  if(i == prices.size()) {
    return 0;
  }

  if(dp[i][buy] != -1) return dp[i][buy];

  if(buy) {
    return dp[i][1] = max(maxProfit(i + 1, false, fee, prices, dp) - prices[i] - fee, maxProfit(i + 1, true, fee, prices, dp));
  }
  return dp[i][0] = max(maxProfit(i + 1, true, fee, prices, dp) + prices[i], maxProfit(i + 1, false, fee, prices, dp));
}

// Tabulation
// int maxProfit(vector<int>& prices, int fee) {
//   int n = prices.size();
//   vector<vector<int>> dp(n+1, vector<int>(2, 0));

//   for(int i = n-1; i >= 0; i--) {
//     dp[i][1] = max(dp[i + 1][0] - prices[i] - fee, dp[i + 1][1]);
//     dp[i][0] = max(dp[i + 1][1] + prices[i], dp[i + 1][0]);
//   }

//   return dp[0][1];
// }

// Tabulation
int maxProfit(vector<int>& prices, int fee) {
  int n = prices.size();
  vector<int> after(2, 0), cur(2, 0);

  for(int i = n-1; i >= 0; i--) {
    cur[1] = max(after[0] - prices[i] - fee, after[1]);
    cur[0] = max(after[1] + prices[i], after[0]);

    after = cur;
  }

  return cur[1];
}

int main() {
  vector<int> prices = {1, 3, 2, 8, 4, 9};
  int n = prices.size();
  int transFee = 2;

// Memoization
  // vector<vector<int>> dp(n, vector<int>(2, -1));
  // cout << maxProfit(0, true, transFee, prices, dp) << endl;

// Tabulation
  cout << maxProfit(prices, transFee) << endl;

  return 0;
}