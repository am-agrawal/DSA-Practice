#include <iostream>
#include <vector>

using namespace std;

// 1. Grid Unique Path -> Find no. of ways to reach [m-1, n-1] from [0, 0] in a (m * n) Grid
// We will use recursion and move to [0, 0] from [m-1, n-1]
// => Here, m & n are m-1, n-1
// int gridUniquePath(int m, int n) {
//   if(m == 0 && n == 0) return 1;

//   if(m < 0 || n < 0) return 0;

//   int up = gridUniquePath(m-1, n);
//   int left = gridUniquePath(m, n-1);

//   return left + up;
// }

// Memoization
// Time => O(m * n)
// Space => O(m * n) + O(m * n)
int gridUniquePath(int m, int n, vector<vector<int>>& dp) {
  if(m == 0 && n == 0) return 1;
  if(m < 0 || n < 0) return 0;

  if(dp[m][n] != -1) return dp[m][n];

  int up = gridUniquePath(m-1, n, dp);
  int left = gridUniquePath(m, n-1, dp);

  return dp[m][n] = up + left;
}

// Tabultaion
// Time => O(m * n)
// Space => O(m * n)
int gridUniquePath(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(i == 0 || j == 0) dp[i][j] = 1;
      else {
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
  }

  return dp[m-1][n-1];
}

// Tabulation (Space Optimized)
// Time => O(m * n)
// Space => O(n)
int gridUniquePathOptimized(int m, int n) {
  vector<int> prev(n, 0);
  for(int i = 0; i < m; i++) {
    vector<int> temp(n, 0);
    for(int j = 0; j < n; j++) {
      if(i == 0 || j == 0) temp[j] = 1;
      else {
        temp[j] = prev[j] + temp[j-1];
      }
    }
    prev = temp;
  }

  return prev[n-1];
}


int main() {
  int m = 3, n = 3;
  // Recursion
  // cout << gridUniquePath(m-1, n-1) << endl;

  // Memoization
  // vector<vector<int>> dp(m, vector<int>(n, -1));
  // cout << gridUniquePath(m-1, n-1, dp) << endl;

  // Tabulation
  cout << gridUniquePath(m, n) << endl;

  return 0;
}