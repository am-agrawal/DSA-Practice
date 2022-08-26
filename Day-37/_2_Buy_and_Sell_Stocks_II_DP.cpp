// Here we have an array of integers
// And we can buy or sell them any amount of time
// But if we buy then we have to sell before second buy

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxProfit(int i, bool buy, vector<int>& prices, vector<vector<int>>& dp, int &n) {
  if(i == n) {
    return 0;
  }

  if(dp[i][buy] != -1) return dp[i][buy];

  int profit = 0;

  if(buy) {
    int buyIt = maxProfit(i+1, !buy, prices, dp, n) - prices[i];
    int notBuyIt = maxProfit(i+1, buy, prices, dp, n);
    profit = max(buyIt, notBuyIt);
  } else {
    int sellIt = maxProfit(i+1, !buy, prices, dp, n) + prices[i];
    int notSellIt = maxProfit(i+1, buy, prices, dp, n);
    profit = max(sellIt, notSellIt);
  }

  return dp[i][buy] = profit;
}

// Tabulation
// int maxProfit(vector<int>& prices) {
//   int n = prices.size();
//   vector<vector<int>> dp(n+1, vector<int>(2, 0));

//   for(int i = n-1; i >= 0; i--) {
//     for(int buy = 0; buy <= 1; buy++) {
//       int profit = 0;
//       if (buy) {
//         int buyIt = dp[i + 1][!buy] - prices[i];
//         int notBuyIt = dp[i + 1][buy];
//         profit = max(buyIt, notBuyIt);
//       }
//       else {
//         int sellIt = dp[i + 1][!buy] + prices[i];
//         int notSellIt = dp[i + 1][buy];
//         profit = max(sellIt, notSellIt);
//       }

//       dp[i][buy] = profit;
//     }
//   }

//   return dp[0][1];
// }

// Tabulation (Space Optimized)
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  // vector<int> prev(2, 0), cur(2, 0);
  int prevNotBuy = 0, prevBuy = 0;
  int curNotBuy, curBuy;

  for(int i = n-1; i >= 0; i--) {
    curNotBuy = max(prevBuy + prices[i], prevNotBuy);
    curBuy = max(prevNotBuy - prices[i], prevBuy);

    prevBuy = curBuy;
    prevNotBuy = curNotBuy;
  }

  return prevBuy;
}

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  int n = prices.size();

// Memoization
  // vector<vector<int>> dp(n, vector<int>(2, -1));
  // cout << maxProfit(0, true, prices, dp, n) << endl;

// Tabulation
  cout << maxProfit(prices) << endl;

  return 0;
}