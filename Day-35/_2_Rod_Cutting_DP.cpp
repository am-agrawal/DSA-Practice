// Here we have a Rod length as N and an array of integers which represents price[i] of i+1 length
// We have to find the maximum price, we can obtain from the N by dividing it into pieces

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxPrice(int i, int N, vector<int>& prices, vector<vector<int>>& dp) {
  if(N == 0) return 0;
  if(i == 0) {
    return N * prices[0];
  }

  if(dp[i][N] != -1) return dp[i][N];

  int rodlength = i+1;
  int notPick = maxPrice(i-1, N, prices, dp);
  int pick = (rodlength <= N) ? maxPrice(i, N-rodlength, prices, dp) + prices[i] : 0;

  return dp[i][N] = max(pick, notPick);
}

// Tabulation
// int maxPrice(int N, vector<int>& prices) {
//   int n = prices.size();
//   vector<vector<int>> dp(n, vector<int>(N+1, 0));

//   for(int T = 0; T <= N; T++) {
//     dp[0][T] = T * prices[0];
//   }

//   for(int i = 1; i < n; i++) {
//     for(int T = 0; T <= N; T++) {
//       int rodlength = i+1;
//       int notPick = dp[i-1][T];
//       int pick = (rodlength <= T) ? dp[i][T-rodlength] + prices[i] : 0;

//       dp[i][T] = max(pick, notPick);
//     }
//   }

//   return dp[n-1][N];
// }

// Tabulation (Space Optimized)
int maxPrice(int N, vector<int>& prices) {
  int n = prices.size();
  vector<int> prev(N+1, 0);

  for(int T = 0; T <= N; T++) {
    prev[T] = T * prices[0];
  }

  for(int i = 1; i < n; i++) {
    for(int T = 0; T <= N; T++) {
      int rodlength = i+1;
      int notPick = prev[T];
      int pick = (rodlength <= T) ? prev[T-rodlength] + prices[i] : 0;

      prev[T] = max(pick, notPick);
    }
  }

  return prev[N];
}

int main() {
  vector<int> prices = {2, 5, 7, 8, 10};
  int len = 5;
  int n = prices.size();

// Memoization
  // vector<vector<int>> dp(n, vector<int>(len+1, -1));
  // cout << maxPrice(n-1, len, prices, dp) << endl;

// Tabulation
  cout << maxPrice(len, prices) << endl;

  return 0;
}