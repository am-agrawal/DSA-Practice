// Here we have an array of integers of size N which represents the sizes of N-1 matrices
// Example => [10, 20, 30], this represents 2 matrices as A -> [10 x 20] & B -> [20, 30]
// We need to find the minimum number of steps to multiply all tha matrices
// when multiplying 2 matrices takes (A -> [10, 20] & B -> [20, 30]) 10 x 20 x 30 steps

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int MCM(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
  if(i == j) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  int mini = INT_MAX;
  for(int k = i; k < j; k++) {
    int steps = arr[i-1] * arr[k] * arr[j] + MCM(i, k, arr, dp) + MCM(k+1, j, arr, dp);
    mini = min(mini, steps);
  }
  return dp[i][j] = mini;
}

// Tabulation
int MCM(vector<int>& arr) {
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for(int i = n-1; i >= 1; i--) {
    for(int j = i+1; j < n; j++) {
      int mini = INT_MAX;
      for(int k = i; k < j; k++) {
        int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
        mini = min(mini, steps);
      }
      dp[i][j] = mini;
    }
  }
  return dp[1][n-1];
}

int main() {
  vector<int> arr = {10, 20, 30, 50};
  int n = arr.size();

// Memoization
  // vector<vector<int>> dp(n, vector<int>(n, -1));
  // cout << MCM(1, n-1, arr, dp) << endl;

// Tabulation
  cout << MCM(arr) << endl;

  return 0;
}