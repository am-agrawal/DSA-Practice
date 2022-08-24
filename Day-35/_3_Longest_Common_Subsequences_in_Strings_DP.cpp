// Here we have Two Strings
// and we have to find the length of longest common subsequence among both strings

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int maxLength(int idx1, int idx2, string str1, string str2, vector<vector<int>>& dp) {
  if(idx1 == 0 || idx2 == 0) return 0;

  if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

  if(str1[idx1-1] == str2[idx2-1]) {
    return dp[idx1][idx2] = 1 + maxLength(idx1 - 1, idx2 - 1, str1, str2, dp);
  }

  return dp[idx1][idx2] = max(maxLength(idx1 - 1, idx2, str1, str2, dp), maxLength(idx1, idx2 - 1, str1, str2, dp));
}

// Tabulation
// int maxLength(string str1, string str2) {
//   int n = str1.size(), m = str2.size();
//   vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

//   for(int i = 0; i <= n; i++) { dp[i][0] = 0; }
//   for(int j = 0; j <= m; j++) { dp[0][j] = 0; }

//   for(int i = 1; i <= n; i++) {
//     for(int j = 1; j <= m; j++) {
//       if(str1[i-1] == str2[j-1]) {
//         dp[i][j] = 1 + dp[i-1][j-1];
//       } else {
//         dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//       }
//     }
//   }

//   return dp[n][m];
// }

// Tabulation (Space Optimized)
int maxLength(string str1, string str2) {
  int n = str1.size(), m = str2.size();
  vector<int> prev(m+1, 0), cur(m+1, 0);

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(str1[i-1] == str2[j-1]) {
        cur[j] = 1 + prev[j-1];
      } else {
        cur[j] = max(prev[j], cur[j-1]);
      }
    }
    prev = cur;
  }

  return prev[m];
}

int main() {
  string str1 = "abc", str2 = "bec";
  int idx1 = str1.size(), idx2 = str2.size();

// Memoization
  // vector<vector<int>> dp(idx1+1, vector<int>(idx2+1, -1));
  // cout << maxLength(idx1, idx2, str1, str2, dp) << endl;

// Tabulation
  cout << maxLength(str1, str2) << endl;

  return 0;
}
