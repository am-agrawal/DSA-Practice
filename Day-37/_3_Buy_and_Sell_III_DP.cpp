// Here we have a limit of buying and selling stocks as 2

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(int i, bool buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
  if(cap == 0 || i == n) return 0;

  if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

  int profit = 0;
  if(buy) {
    int buyIt = maxProfit(i+1, !buy, cap, prices, n, dp) - prices[i];
    int notBuyIt = maxProfit(i+1, buy, cap, prices, n, dp);
    profit = max(buyIt, notBuyIt);
  } else {
    int sellIt = maxProfit(i+1, !buy, cap-1, prices, n, dp) + prices[i];
    int notSellIt = maxProfit(i+1, buy, cap, prices, n, dp);
    profit = max(sellIt, notSellIt);
  }

  return dp[i][buy][cap] = profit;
}

// Tabulation
// int maxProfit(vector<int>& prices) {
//   int n = prices.size();
//   vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

//   for(int i = n-1; i >= 0; i--) {
//     for(int buy = 0; buy <= 1; buy++) {
//       for(int cap = 1; cap <= 2; cap++) {
//         int profit = 0;
//         if (buy == 1) {
//           int buyIt = dp[i + 1][0][cap] - prices[i];
//           int notBuyIt = dp[i + 1][1][cap];
//           profit = max(buyIt, notBuyIt);
//         }
//         else {
//           int sellIt = dp[i + 1][1][cap - 1] + prices[i];
//           int notSellIt = dp[i + 1][0][cap];
//           profit = max(sellIt, notSellIt);
//         }

//         dp[i][buy][cap] = profit;
//       }
//     }
//   }

//   return dp[0][1][2];
// }

// Tabulation (Space Optimized)
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  vector<vector<int>> after(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));

  for(int i = n-1; i >= 0; i--) {
    for(int buy = 0; buy <= 1; buy++) {
      for(int cap = 1; cap <= 2; cap++) {
        int profit = 0;
        if (buy == 1) {
          int buyIt = after[0][cap] - prices[i];
          int notBuyIt = after[1][cap];
          profit = max(buyIt, notBuyIt);
        }
        else {
          int sellIt = after[1][cap - 1] + prices[i];
          int notSellIt = after[0][cap];
          profit = max(sellIt, notSellIt);
        }

        cur[buy][cap] = profit;
      }
    }
    after = cur;
  }

  return after[1][2];
}

int main() {
  vector<int> prices = {7, 1, 3, 4, 5};
  int cap = 2;
  int n = prices.size();

// Memoization
  // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
  // cout << maxProfit(0, true, cap, prices, n, dp) << endl;

// Tabulation
  cout << maxProfit(prices) << endl;

  return 0;
}