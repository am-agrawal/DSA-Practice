// Here we have Two strings s1 and s2
// And we have to find the number of subsequences of s2 in s1

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int distinctSubsequence(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
  if(j == 0) return 1;
  if(i == 0) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  if(s1[i-1] == s2[j-1]) {
    return dp[i][j] = distinctSubsequence(i-1, j-1, s1, s2, dp) + distinctSubsequence(i-1, j, s1, s2, dp);
  }
  return dp[i][j] = distinctSubsequence(i-1, j, s1, s2, dp);
}

// Tabulation
// int distinctSubsequence(string s1, string s2) {
//   int n = s1.length();
//   int m = s2.length();
//   vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//   for(int i = 0; i <= n; i++) dp[i][0] = 1;

//   for(int i = 1; i <= n; i++) {
//     for(int j = 1; j <= m; j++) {
//       if(s1[i-1] == s2[j-1]) {
//         dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
//       } else {
//         dp[i][j] = dp[i-1][j];
//       }
//     }
//   }

//   return dp[n][m];
// }

// Tabulation (Space Optimized)
int distinctSubsequence(string s1, string s2) {
  int n = s1.length();
  int m = s2.length();
  vector<int> prev(m+1, 0);

  prev[0] = 1;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(s1[i-1] == s2[j-1]) {
        prev[j] = prev[j-1] + prev[j];
      } else {
        prev[j] = prev[j];
      }
    }
  }

  return prev[m];
}

int main() {
  string s1 = "babgbag", s2 = "bag";
  int n = s1.size(), m = s2.size();

// Memoization
  // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
  // cout << distinctSubsequence(n, m, s1, s2, dp) << endl;

// Tabulation
  cout << distinctSubsequence(s1, s2) << endl;

  return 0;
}