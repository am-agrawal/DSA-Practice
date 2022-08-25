// Here we have Two strings s and t
// And we can do Three operations - Insert, Delete and Replace
// One operation take one step
// We have to find the minimum number of steps required to convert string s into t by doing operations

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int minSteps(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
  if(i == 0) return j;
  if(j == 0) return i;

  if(dp[i][j] != -1) return dp[i][j];

  if(s[i-1] == t[j-1]) return dp[i][j] = minSteps(i-1, j-1, s, t, dp);
  
  // deletion
  int del = minSteps(i-1, j, s, t, dp);

  // insertion
  int ins = minSteps(i, j-1, s, t, dp);

  // replace
  int rplc = minSteps(i-1, j-1, s, t, dp);

  return dp[i][j] = min(del, min(ins, rplc)) + 1;
}

// Tabulation
// int minSteps(string s, string t) {
//   int n = s.size(), m = t.size();
//   vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//   for(int i = 0; i <= n; i++) dp[i][0] = i;
//   for(int j = 0; j <= m; j++) dp[0][j] = j;

//   for(int i = 1; i <= n; i++) {
//     for(int j = 1; j <= m; j++) {
//       if(s[i-1] == t[j-1]) {
//         dp[i][j] = dp[i-1][j-1];
//       } else {
//         int del = dp[i-1][j];
//         int ins = dp[i][j-1];
//         int rplc = dp[i-1][j-1];

//         dp[i][j] = min(del, min(ins, rplc)) + 1;
//       }
//     }
//   }

//   return dp[n][m];
// }

// Tabulation (Space Optimized)
int minSteps(string s, string t) {
  int n = s.size(), m = t.size();
  vector<int> prev(m+1, 0), cur(m+1, 0);

  for(int j = 0; j <= m; j++) prev[j] = j;

  for(int i = 1; i <= n; i++) {
    prev[0] = i;
    for(int j = 1; j <= m; j++) {
      if(s[i-1] == t[j-1]) {
        cur[j] = prev[j-1];
      } else {
        int del = prev[j];
        int ins = cur[j-1];
        int rplc = prev[j-1];

        cur[j] = min(del, min(ins, rplc)) + 1;
      }
    }
    prev = cur;
  }

  return prev[m];
}

int main() {
  string s = "horse", t = "ros";
  int n = s.size(), m = t.size();

// Memoization
  // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
  // cout << minSteps(n, m, s, t, dp) << endl;

// Tabulation
  cout << minSteps(s, t) << endl;

  return 0;
}