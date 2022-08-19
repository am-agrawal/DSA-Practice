// We have a grid of integers (n * m) that represents the number of cherries in that cell
// And we have Two persons => 1. First person in the cell [0, 0], 2. Second person in the cell [0, m-1]
// they both will begin towards the bottom, ending cell is variable among last row
// they can move from [i, j] to ( [i+1, j-1], [i+1, j], [i+1, j+1] )
// if both persons are in the same cell then that cell's value will be counted once
// We have to find the maximum path sum

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxPathSum(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp) {
  if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) {
    return -1e7;
  }

  if(i == grid.size() - 1) {
    if (j1 == j2) {
      return grid[i][j1];
    }
    else {
      return grid[i][j1] + grid[i][j2];
    }
  }

  if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

  int res = INT_MIN;

  for(int k = -1; k <= 1; k++) {
    for(int l = -1; l <= 1; l++) {

      int curValue = (k+j1 == l+j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
      res = max(res, maxPathSum(i+1, j1+k, j2+l, grid, dp) + curValue);

    }
  }

  return dp[i][j1][j2] = res;
}


// Tabulation
// int maxPathSum(vector<vector<int>>& grid) {
//   int n = grid.size();
//   int m = grid[0].size();
//   vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

//   for(int j1 = 0; j1 < m; j1++) {
//     for(int j2 = 0; j2 < m; j2++) {
//       dp[n-1][j1][j2] = (j1 == j2) ? grid[n-1][j1] : grid[n-1][j1] + grid[n-1][j2];
//     }
//   }

//   for(int i = n-2; i >= 0; i--) {
//     for(int j1 = 0; j1 < m; j1++) {
//       for(int j2 = 0; j2 < m; j2++) {
//         int maxi = -1e6;
//         for(int dj1 = -1; dj1 <= 1; dj1++) {
//           for(int dj2 = -1; dj2 <= 1; dj2++) {
//             int value = 0;
//             if(j1 == j2) value = grid[i][j1];
//             else value = grid[i][j1] + grid[i][j2];

//             if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m) {
//               value += dp[i+1][j1+dj1][j2+dj2];
//             } else {
//               value += -1e6;
//             }

//             maxi = max(maxi, value);
//           }
//         }
//         dp[i][j1][j2] = maxi;
//       }
//     }
//   }

//   return dp[0][0][m-1];
// }


// Tabulation (Space Optimized)
int maxPathSum(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> prev(m, vector<int>(m, 0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      prev[j1][j2] = (j1 == j2) ? grid[n - 1][j1] : grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    vector<vector<int>> cur(m, vector<int>(m, 0));
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {
        int maxi = -1e6;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
          for (int dj2 = -1; dj2 <= 1; dj2++) {
            int value = 0;
            if (j1 == j2)
              value = grid[i][j1];
            else
              value = grid[i][j1] + grid[i][j2];

            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) {
              value += prev[j1 + dj1][j2 + dj2];
            }
            else {
              value += -1e6;
            }

            maxi = max(maxi, value);
          }
        }
        cur[j1][j2] = maxi;
      }
    }
    prev = cur;
  }

  return prev[0][m - 1];
}


int main() {
  vector<vector<int>> grid = {
                              {2, 3, 1, 2},
                              {3, 4, 2, 2},
                              {5, 6, 3, 5}
  };
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

// Memoization
  // cout << maxPathSum(0, 0, m-1, grid, dp) << endl;

// Tabulation
  cout << maxPathSum(grid) << endl;

  return 0;
}