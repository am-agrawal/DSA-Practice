// Here we have Two strings - pattern and word
// pattern string will contain lowescase letters and two symbols -> ? and *
// ? can match any letter and * can match any [0, 1, 2,...] letters
// So we have to find that word follows pattern or not?

#include <iostream>
#include <vector>
using namespace std;

// Memoization
bool match(int i, int j, string &p, string &w, vector<vector<int>>& dp) {
  if(i == 0 && j == 0) return true;
  if(i == 0 && j > 0) return false;

  if(j == 0 && i > 0) {
    for(int ii = 1; ii <= i; ii++) {
      if(p[ii-1] != '*') return false;
    }
    return true;
  }

  if(dp[i][j] != -1) return dp[i][j];

  if(p[i-1] == w[j-1] || p[i-1] == '?') return dp[i][j] = match(i-1, j-1, p, w, dp);

  if(p[i-1] == '*') return dp[i][j] = (match(i-1, j-1, p, w, dp) || match(i, j-1, p, w, dp));

  return false;
}

// Tabulation
// bool match(string p, string w) {
//   int n = p.size(), m = w.size();
//   vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
//   dp[0][0] = true;

//   for(int i = 1; i <= n; i++) {
//     bool flag = true;
//     for(int ii = 1; ii <= i; ii++) {
//       if(p[ii-1] != '*') {
//         flag = false;
//         break;
//       }
//     }
//     dp[i][0] = flag;
//   }

//   for(int i = 1; i <= n; i++) {
//     for(int j = 1; j <= m; j++) {
//       if(p[i-1] == w[j-1] || p[i-1] == '?') {
//         dp[i][j] = dp[i-1][j-1];
//       } else if(p[i-1] == '*') {
//         dp[i][j] = (dp[i-1][j-1] || dp[i][j-1]);
//       }
//     }
//   }

//   return dp[n][m];
// }

// Tabulation (Space Optimized)
bool match(string p, string w) {
  int n = p.size(), m = w.size();
  vector<bool> prev(m+1, false), cur(m+1, false);
  prev[0] = true;

  for(int i = 1; i <= n; i++) {

    bool flag = true;
    for(int ii = 1; ii <= i; ii++) {
      if(p[ii-1] != '*') {
        flag = false;
        break;
      }
    }
    cur[0] = flag;

    for(int j = 1; j <= m; j++) {
      if(p[i-1] == w[j-1] || p[i-1] == '?') {
        cur[j] = prev[j-1];
      } else if(p[i-1] == '*') {
        cur[j] = (prev[j-1] || cur[j-1]);
      }
    }
    prev = cur;
  }

  return prev[m];
}

int main() {
  string pattern = "**abcd", word = "abcd";
  int n = pattern.length(), m = word.length();

// Memoization
  // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
  // (match(n, m, pattern, word, dp)) ? cout << "True" : cout << "False";

// Tabulation
  (match(pattern, word)) ? cout << "True" : cout << "False";

  return 0;
}