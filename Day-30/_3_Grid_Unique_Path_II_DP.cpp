#include <iostream>
#include <vector>
using namespace std;

// A Integer Grid of m x n is given and we have to find out the no. of ways to reach [m-1, n-1] from [0, 0]
// if Grid[i][j] is 0, then we can visit this cell and then go ahead
// if Grid[i][j] is -1, then it's a Dead Cell and we can't go ahead of it

// Memoization
// Time => O(m * n)
// Space => O(m * n) + O(m * n)
// int uniquePath(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
//   if(m == 0 && n == 0) return 1;
//   if(m < 0 || n < 0) return 0;

//   if(grid[m][n] == -1) return 0;

//   if(dp[m][n] != -1) return dp[m][n];

//   int up = uniquePath(m-1, n, grid, dp);
//   int left = uniquePath(m, n-1, grid, dp);

//   return dp[m][n] = up + left;
// }


// Tabulation
// Time => O(m * n)
// Space => O(m * n)
// int uniquePath(vector<vector<int>>& grid) {
//   int m = grid.size(), n = grid[0].size();

//   vector<vector<int>> dp(m, vector<int>(n));

//   for(int i = 0; i < m; i++) {
//     for(int j = 0; j < n; j++) {
//       if(grid[i][j] == -1) dp[i][j] = 0;
//       else if(i == 0 && j == 0) dp[i][j] = 1;
//       else {
//         int up = 0, left = 0;
//         if(i > 0) up = dp[i-1][j];
//         if(j > 0) left = dp[i][j-1];
//         dp[i][j] = up + left;
//       }
//     }
//   }

//   return dp[m-1][n-1];
// }


// Tabulation (Space Optimized)
// Time => O(m * n)
// Space => O(n)
int uniquePath(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();

  vector<int> prev(n, 0);

  for(int i = 0; i < m; i++) {
    vector<int> temp(n);
    for(int j = 0; j < n; j++) {
      if(grid[i][j] == -1) temp[j] = 0;
      else if(i == 0 && j == 0) temp[j] = 1;
      else {
        int up = 0, left = 0;
        if(i > 0) up = prev[j];
        if(j > 0) left = temp[j-1];
        temp[j] = up + left;
      }
    }
    prev = temp;
  }

  return prev[n-1];
}


int main() {
  vector<vector<int>> grid = {
                              {0, 0, 0},
                              {0, -1, 0},
                              {0, 0, 0}
  };

// Memoization
  // int m = grid.size();
  // int n = grid[0].size();

  // vector<vector<int>> dp(m, vector<int>(n, -1));

  // cout << uniquePath(m-1, n-1, grid, dp) << endl;

// Tabulation
  cout << uniquePath(grid) << endl;

  return 0;
}