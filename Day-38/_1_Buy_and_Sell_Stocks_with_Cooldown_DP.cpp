// Here we have the same question as Best Time to buy and sell stocks II but with a little change
// Here after a transaction, we can't buy instantly. We can buy after a gap of one day

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxProfit(int i, bool buy, vector<int>& prices, vector<vector<int>>& dp) {
  if(i >= prices.size()) {
    return 0;
  }

  if(dp[i][buy] != -1) return dp[i][buy];

  if(buy) {
    return dp[i][1] = max(maxProfit(i + 1, false, prices, dp) - prices[i], maxProfit(i + 1, true, prices, dp));
  }
  return dp[i][0] = max(maxProfit(i + 2, true, prices, dp) + prices[i], maxProfit(i + 1, false, prices, dp));
}

// Tabulation
// int maxProfit(vector<int>& prices) {
//   int n = prices.size();
//   vector<vector<int>> dp(n+2, vector<int>(2, 0));

//   for(int i = n-1; i >= 0; i--) {
//     dp[i][1] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
//     dp[i][0] = max(dp[i + 2][1] + prices[i], dp[i + 1][0]);
//   }

//   return dp[0][1];
// }

// Tabulation (Space Optimized)
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  vector<int> front2(2, 0), front1(2, 0), cur(2, 0);

  for(int i = n-1; i >= 0; i--) {
    cur[1] = max(front1[0] - prices[i], front1[1]);
    cur[0] = max(front2[1] + prices[i], front1[0]);

    front2 = front1;
    front1 = cur;
  }

  return cur[1];
}

int main() {
  vector<int> prices = {1, 3, 8, 2, 4, 9};
  int n = prices.size();

// Memoization
  vector<vector<int>> dp(n, vector<int>(2, -1));
  cout << maxProfit(0, true, prices, dp) << endl;

  return 0;
}