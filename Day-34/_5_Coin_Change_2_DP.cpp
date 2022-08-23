// Here we can use coin as many number of time as possible
// We have to find the number of ways, by which we can achieve our target value

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int coinChange(int i, int tar, vector<int>& coins, vector<vector<int>>& dp) {
  if(i == 0) {
    return (tar % coins[0] == 0);
  }

  if(dp[i][tar] != -1) return dp[i][tar];

  int notPick = coinChange(i-1, tar, coins, dp);
  int pick = (coins[i] <= tar) ? coinChange(i, tar-coins[i], coins, dp) : 0;

  return dp[i][tar] = notPick + pick;
}

// Tabulation
// int coinChange(int tar, vector<int>& coins) {
//   int n = coins.size();
//   vector<vector<int>> dp(n, vector<int>(tar+1, 0));

//   for(int T = 0; T <= tar; T++) {
//     dp[0][T] = (T % coins[0] == 0);
//   }

//   for(int i = 1; i < n; i++) {
//     for(int T = 0; T <= tar; T++) {
//       int notPick = dp[i - 1][T];
//       int pick = (coins[i] <= T) ? dp[i][T - coins[i]] : 0;

//       dp[i][T] = notPick + pick;
//     }
//   }

//   return dp[n-1][tar];
// }

// Tabulation (Space Optimized)
int coinChange(int tar, vector<int>& coins) {
  int n = coins.size();
  vector<int> prev(tar+1, 0), cur(tar+1, 0);

  for(int T = 0; T <= tar; T++) {
    prev[T] = (T % coins[0] == 0);
  }

  for(int i = 1; i < n; i++) {
    for(int T = 0; T <= tar; T++) {
      int notPick = prev[T];
      int pick = (coins[i] <= T) ? cur[T - coins[i]] : 0;

      cur[T] = notPick + pick;
    }
    prev = cur;
  }

  return prev[tar];
}

int main() {
  vector<int> coins = {1, 2, 3};
  int tar = 5;
  int n = coins.size();
// Memoization
  // vector<vector<int>> dp(n, vector<int>(tar+1, -1));
  // cout << coinChange(n-1, tar, coins, dp) << endl;

// Tabulation
  cout << coinChange(tar, coins) << endl;

  return 0;
}