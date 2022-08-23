// Here we have an array of integers that represents denomination of coins
// And we have target value as integer and we have to find out the minimum number of coins
// that we require to form target value

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int minCoins(int i, int tar, vector<int>& coins, vector<vector<int>>& dp) {
  if(tar == 0) return 0;
  if(i == 0) return (tar % coins[0] == 0) ? (tar / coins[0]) : 1e9;

  if(dp[i][tar] != -1) return dp[i][tar];

  int notPick = minCoins(i-1, tar, coins, dp);
  int pick = (coins[i] <= tar) ? minCoins(i-1, tar-coins[i], coins, dp) + 1 : 1e9;

  return dp[i][tar] = min(notPick, pick);
}

// Tabulation
// int minCoins(vector<int>& coins, int tar) {
//   int n = coins.size();
//   vector<vector<int>> dp(n, vector<int>(tar+1, 0));

//   for(int T = 0; T <= tar; T++) {
//     dp[0][T] = (T % coins[0] == 0) ? (T / coins[0]) : 1e9;
//   }

//   for(int i = 1; i < n; i++) {
//     for(int T = 0; T <= tar; T++) {
//       int notPick = dp[i-1][T];
//       int pick = (coins[i] <= T) ? dp[i-1][T-coins[i]] + 1 : 1e9;

//       dp[i][T] = min(notPick, pick);
//     }
//   }
//   return dp[n-1][tar];
// }

// Tabulation (Space Optimized)
int minCoins(vector<int>& coins, int tar) {
  int n = coins.size();
  vector<int> prev(tar+1, 0), cur(tar+1, 0);

  for(int T = 0; T <= tar; T++) {
    prev[T] = (T % coins[0] == 0) ? (T / coins[0]) : 1e9;
  }

  for(int i = 1; i < n; i++) {
    for(int T = 0; T <= tar; T++) {
      int notPick = prev[T];
      int pick = (coins[i] <= T) ? prev[T-coins[i]] + 1 : 1e9;

      cur[T] = min(notPick, pick);
    }
    prev = cur;
  }
  return prev[tar];
}

int main() {
  vector<int> coins = {1, 5, 6, 9};
  int n = coins.size();
  int tar = 11;

// Memoization
  // vector<vector<int>> dp(n, vector<int>(tar+1, -1));
  // cout << minCoins(n-1, tar, coins, dp) << endl;

// Tabulation
  cout << minCoins(coins, tar) << endl;

  return 0;
}