// Here we have a grid of n * m and we have to find the minimum path sum
// Our starting cell can be anyone in the first row
// And ending cell can be anyone in the last row

#include <iostream>
#include <vector>
using namespace std;

// Memoization
// Time => O(n * m)
// Space => O(n * m) + O(n * m)
int minPathSum(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
  if(j < 0 || j >= grid[0].size()) return 1e6;

  if(i == 0) return grid[i][j];

  if(dp[i][j] != -1) return dp[i][j];

  int left, up, right;
  left = up = right = INT_MAX;

  left = minPathSum(grid, i-1, j-1, dp) + grid[i][j];
  up = minPathSum(grid, i-1, j, dp) + grid[i][j];
  right = minPathSum(grid, i-1, j+1, dp) + grid[i][j];

  return dp[i][j] = min(left, min(up, right));
}

int minPathSumDriverCode(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<int>> dp(n, vector<int>(m, -1));

  int res = INT_MAX;
  for(int j = 0; j < m; j++) {
    res = min(res, minPathSum(grid, n-1, j, dp));
  }

  return res;
}


// Tabulation
// Time => O(n * m)
// Space => O(n * m)
// int minPathSum(vector<vector<int>>& grid) {
//   int n = grid.size();
//   int m = grid[0].size();

//   vector<vector<int>> dp(n, vector<int>(m, 0));

//   dp[0] = grid[0];

//   for(int i = 1; i < n; i++) {
//     for(int j = 0; j < m; j++) {
//       int left = (j-1 < 0) ? 1e6 : dp[i-1][j-1];
//       int up = dp[i-1][j];
//       int right = (j+1 >= m) ? 1e6 : dp[i-1][j+1];
//       dp[i][j] = min(left , min(up, right)) + grid[i][j];
//     }
//   }

//   int res = INT_MAX;
//   for(int i = 0; i < m; i++) {
//     res = min(res, dp[n-1][i]);
//   }

//   return res;
// }


// Tabulation (Space Optimized)
// Time => O(n * m)
// Space => O(m)
int minPathSum(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();

  vector<int> prev(m);

  prev = grid[0];

  for(int i = 1; i < n; i++) {
    vector<int> cur(m);
    for(int j = 0; j < m; j++) {
      int left = (j-1 < 0) ? 1e6 : prev[j-1];
      int up = prev[j];
      int right = (j+1 >= m) ? 1e6 : prev[j+1];
      cur[j] = min(left , min(up, right)) + grid[i][j];
    }
    prev = cur;
  }

  int res = INT_MAX;
  for(int i = 0; i < m; i++) {
    res = min(res, prev[i]);
  }

  return res;
}


int main() {
  vector<vector<int>> grid = {
                              {2, 4, 6, 2},
                              {4, 1, 2, 8},
                              {10, 20, 2, 10},
                              {21, 2, 4, 8}
  };

// Memoizaton
  // cout << minPathSumDriverCode(grid) << endl;

// Tabulation
  cout << minPathSum(grid) << endl;

  return 0;
}