// Here the capacity of stocks transactions will variable as K

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxProfit(int i, bool buy, int k, int n, vector<int>& prices, vector<vector<vector<int>>>& dp) {
  if(i == n || k == 0) return 0;

  if(dp[i][buy][k] != -1) return dp[i][buy][k];

  int profit;
  if(buy) {
    profit = max(maxProfit(i+1, false, k, n, prices, dp) - prices[i], maxProfit(i+1, true, k, n, prices, dp));
  } else {
    profit = max(maxProfit(i+1, true, k-1, n, prices, dp) + prices[i], maxProfit(i+1, false, k, n, prices, dp));
  }

  return dp[i][buy][k] = profit;
}

// Tabulation
// int maxProfit(vector<int>& prices, int k) {
//   int n = prices.size();
//   vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

//   for(int i = n-1; i >= 0; i--) {
//     for(int buy = 0; buy <= 1; buy++) {
//       for(int cap = 1; cap <= k; cap++) {
//         int profit;
//         if (buy == 1) {
//           profit = max(dp[i + 1][0][cap] - prices[i], dp[i + 1][1][cap]);
//         }
//         else {
//           profit = max(dp[i + 1][1][cap - 1] + prices[i], dp[i + 1][0][cap]);
//         }

//         dp[i][buy][cap] = profit;
//       }
//     }
//   }

//   return dp[0][1][k];
// }

// Tabulation (Space Optimized)
int maxProfit(vector<int>& prices, int k) {
  int n = prices.size();
  vector<vector<int>> after(2, vector<int>(k + 1, 0)), cur(2, vector<int>(k + 1, 0));

  for(int i = n-1; i >= 0; i--) {
    for(int buy = 0; buy <= 1; buy++) {
      for(int cap = 1; cap <= k; cap++) {
        int profit;
        if (buy == 1) {
          profit = max(after[0][cap] - prices[i], after[1][cap]);
        }
        else {
          profit = max(after[1][cap - 1] + prices[i], after[0][cap]);
        }

        cur[buy][cap] = profit;
      }
    }
    after = cur;
  }

  return after[1][k];
}


int main() {
  vector<int> prices = {7, 1, 3, 4, 5};
  int n = prices.size();
  int k = 2;

// Memoization
  // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
  // cout << maxProfit(0, true, k, n, prices, dp) << endl;

// Tabulation
  cout << maxProfit(prices, k) << endl;

  return 0;
}