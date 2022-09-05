// Here we have an array of integers of size N that represents points of each balloons
// If we burst the ith balloons then we will get (A[i-1] * A[i] * A[i+1]) points
// If A[i-1] or A[i+1] is not present then we take their value as 1
// We need to find the maximum number of points we can get by bursting the balloons

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxPoints(int i, int j, vector<int>& points, vector<vector<int>>& dp) {
  if(i > j) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  int maxi = INT_MIN;

  for(int k = i; k <= j; k++) {
    int res = points[i-1] * points[k] * points[j+1] + maxPoints(i, k-1, points, dp) + maxPoints(k+1, j, points, dp);
    maxi = max(maxi, res);
  }
  return dp[i][j] = maxi;
}

// Tabulation
int maxPoints(vector<int>& points) {
  int n = points.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));
  n -= 2;
  for(int i = n; i >= 1; i--) {
    for(int j = i; j <= n; j++) {
      int maxi = INT_MIN;
      for (int k = i; k <= j; k++) {
        int res = points[i - 1] * points[k] * points[j + 1] + dp[i][k-1] + dp[k+1][j];
        maxi = max(maxi, res);
      }
      dp[i][j] = maxi;
    }
  }
  return dp[1][n];
}

int main() {
  vector<int> points = {3, 1, 5, 8};
  int n = points.size();
  points.push_back(1);
  points.insert(points.begin(), 1);

// Memoization
  // vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
  // cout << maxPoints(1, n, points, dp);

// Tabulation
  cout << maxPoints(points) << endl;

  return 0;
}