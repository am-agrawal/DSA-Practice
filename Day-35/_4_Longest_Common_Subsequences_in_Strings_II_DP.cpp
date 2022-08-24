// This problem is the follow up problem of previous one
// Here we have to find the longest common subsequence instead of just length

#include <iostream>
#include <vector>
using namespace std;

// Tabulation
int maxLength(string str1, string str2, vector<vector<int>>& dp) {
  int n = str1.size(), m = str2.size();

  for(int i = 0; i <= n; i++) { dp[i][0] = 0; }
  for(int j = 0; j <= m; j++) { dp[0][j] = 0; }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(str1[i-1] == str2[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  return dp[n][m];
}

string LCS(string str1, string str2) {
  int n = str1.size(), m = str2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  maxLength(str1, str2, dp);

  string ans = "";

  while(n > 0 && m > 0) {
    if(str1[n-1] == str2[m-1]) {
      ans = str1[n-1] + ans;
      n--;
      m--;
    } else {
      if(dp[n-1][m] > dp[n][m-1]) {
        n--;
      } else {
        m--;
      }
    }
  }

  return ans;
}

int main() {
  string str1 = "abc", str2 = "bec";

  cout << LCS(str1, str2) << endl;

  return 0;
}
