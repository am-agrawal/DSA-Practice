// Here we are given a grid of n * m where it stores the numbers
// And we have to reach [n-1, m-1] from [0, 0] with taking a path that sums up to be minimum
// We can move either "right" or "down"

#include <iostream>
#include <vector>
using namespace std;

// Memoization
// Time => O(n * m)
// Space => O(n * m) + O(n * m)
int minPathSum(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
  if(n == 0 && m == 0) return grid[0][0];
  if(n < 0 || m < 0) return 100000;

  if(dp[n][m] != -1) return dp[n][m];

  int up = minPathSum(n-1, m, grid, dp) + grid[n][m];
  int down = minPathSum(n, m-1, grid, dp) + grid[n][m];

  return dp[n][m] = min(up, down);
}


// Tabulation
// Time => O(n * m)
// Space => O(n * m)
// int minPathSum(vector<vector<int>>& grid) {
//   int n = grid.size(), m = grid[0].size();
//   vector<vector<int>> dp(n, vector<int>(m, 0));

//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < m; j++) {
//       if(i == 0 && j == 0) {
//         dp[i][j] = grid[i][j];
//       } else {
//         int up = INT_MAX, left = INT_MAX;
//         if(i > 0) up = grid[i][j] + dp[i-1][j];
//         if(j > 0) left = grid[i][j] + dp[i][j-1];

//         dp[i][j] = min(up, left);
//       }
//     }
//   }

//   return dp[n-1][m-1];
// }


// Tabulation (Space Optimized)
// Time => O(n * m)
// Space => O(m)
int minPathSum(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();
  vector<int> prev(m, 0);

  for(int i = 0; i < n; i++) {
    vector<int> cur(m, 0);
    for(int j = 0; j < m; j++) {
      if(i == 0 && j == 0) {
        cur[j] = grid[i][j];
      } else {
        int up = INT_MAX, left = INT_MAX;
        if(i > 0) up = grid[i][j] + prev[j];
        if(j > 0) left = grid[i][j] + cur[j-1];

        cur[j] = min(up, left);
      }
    }
    prev = cur;
  }

  return prev[m-1];
}


int main() {
  vector<vector<int>> grid = {
                              {5, 9, 6},
                              {11, 5, 2}
  };
//   int n = grid.size();
//   int m = grid[0].size();
//   vector<vector<int>> dp(n, vector<int>(m, -1));

// // Memoization
//   cout << minPathSum(n-1, m-1, grid, dp) << endl;

// Tabulation
  // cout << minPathSum(grid) << endl;

  cout << minPathSum(grid) << endl;

  return 0;
}