// Here we have a Binary Matrix (contains only 1 o 0)
// We need to find number of Squares of 1s

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int squaresOf1s(vector<vector<int>>& mat) {
  int numSquares = 0, n = mat.size(), m = mat[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++) {
    dp[i][0] = mat[i][0];
  }
  for(int j = 0; j < m; j++) {
    dp[0][j] = mat[0][j];
  }

  for(int i = 1; i < n; i++) {
    for(int j = 1; j < m; j++) {
      if(mat[i][j] == 1) {
        dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      numSquares += dp[i][j];
    }
  }

  return numSquares;
}

int main() {
  vector<vector<int>> mat = {
                              {1, 1, 1, 0},
                              {0, 1, 1, 1},
                              {1, 1, 1, 1},
                              {1, 1, 1, 0}
  };

  cout << squaresOf1s(mat) << endl;

  return 0;
}