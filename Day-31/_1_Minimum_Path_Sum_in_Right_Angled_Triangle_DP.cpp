// We are given a Triangle (a right angled one) in terms of 2D array

// 1
// 2 3
// 3 6 8
// 5 1 2 10

// And we start from [0, 0] and we have to reach the last row at any column
// We can make moves either towards right diagonally or towards downward
// and we have to give the minimum value by which we can reach the last row

#include <iostream>
#include <vector>
using namespace std;

// Memoization
// Time => O(n * n)
// Space => O(n * n) + O(n * n)
int minPathSumTriangle(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i=0, int j=0) {
  if(i == triangle.size()-1) {
    return triangle[i][j];
  }

  if(dp[i][j] != -1) return dp[i][j];

  int dRight = minPathSumTriangle(triangle, dp, i+1, j+1) + triangle[i][j];
  int down = minPathSumTriangle(triangle, dp, i+1, j) + triangle[i][j];

  return dp[i][j] = min(dRight, down);
}


// Tabulation
// Time => O(n * n)
// Space => O(n * n)
// int minPathSumTriangle(vector<vector<int>>& triangle) {
//   int n = triangle.size();
//   vector<vector<int>> dp(n, vector<int>(n, 0));
//   dp[n-1] = triangle[n-1];

//   for(int i = n-2; i >= 0; i--) {
//     for(int j = 0; j <= i; j++) {
//       dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
//     }
//   }

//   return dp[0][0];
// }


// Tabulation (Space Optimized)
// Time => O(n * n)
// Space => O(n)
int minPathSumTriangle(vector<vector<int>>& triangle) {
  int n = triangle.size();
  vector<int> prev = triangle[n-1];

  for(int i = n-2; i >= 0; i--) {
    vector<int> cur(n, 0);
    for(int j = 0; j <= i; j++) {
      cur[j] = min(prev[j], prev[j+1]) + triangle[i][j];
    }
    prev = cur;
  }

  return prev[0];
}

int main() {
  vector<vector<int>> triangle = {
                                  {1},
                                  {2, 3},
                                  {3, 6, 8},
                                  {5, 1, 2, 10}
  };
  int n = triangle.size();

// Memoization
  // vector<vector<int>> dp(n, vector<int>(n, -1));
  // cout << minPathSumTriangle(triangle, dp) << endl;

// Tabulation
  cout << minPathSumTriangle(triangle) << endl;

  return 0;
}