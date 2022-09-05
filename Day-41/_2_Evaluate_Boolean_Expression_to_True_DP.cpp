// Here we have a string that represents a boolean expression
// And we have to find out number of ways in which, it results into True

#include <iostream>
#include <vector>
using namespace std;

// Memoization
int trueWays(int i, int j, string s, bool isTrue, vector<vector<vector<int>>>& dp) {
  if(i > j) return 0;
  if(i == j) {
    if(isTrue) {
      return s[i] == 'T' ? 1 : 0;
    } else {
      return s[i] == 'F' ? 1 : 0;
    }
  }

  if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

  int ways = 0;
  for(int k = i+1; k <= j-1; k+=2) {
    int lt = trueWays(i, k-1, s, true, dp);
    int lf = trueWays(i, k-1, s, false, dp);
    int rt = trueWays(k+1, j, s, true, dp);
    int rf = trueWays(k+1, j, s, false, dp);

    if(s[k] == '&') {
      if(isTrue) {
        ways += (rt * lt);
      } else {
        ways += (lf * rt) + (lt * rf) + (lf * rf);
      }
    } else if(s[k] == '|') {
      if(isTrue) {
        ways += (lf * rt) + (lt * rf) + (lt * rt);
      } else {
        ways += (lf * rf);
      }
    } else {
      if(isTrue) {
        ways += (lt * rf) + (lf * rt);
      } else {
        ways += (lt * rt) + (lf * rf);
      }
    }
  }
  return dp[i][j][isTrue] = ways;
}

// Some issue with Code 
// Tabulation
// int trueWays(string s) {
//   int n = s.length();
//   vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
//   for(int i = 0; i < n; i++) {
//     for(int j = i; j < n; j++) {
//       for(int isTrue = 0; isTrue <= 1; isTrue++) {
//         int ways = 0;
//         for (int k = i + 1; k <= j - 1; k += 2) {
//           int lt = dp[i][k - 1][1];
//           int lf = dp[i][k - 1][0];
//           int rt = dp[k + 1][j][1];
//           int rf = dp[k + 1][j][0];

//           if (s[k] == '&') {
//             if (isTrue) {
//               ways += (rt * lt);
//             } else {
//               ways += (lf * rt) + (lt * rf) + (lf * rf);
//             }
//           } else if (s[k] == '|') {
//             if (isTrue) {
//               ways += (lf * rt) + (lt * rf) + (lt * rt);
//             } else {
//               ways += (lf * rf);
//             }
//           } else {
//             if (isTrue) {
//               ways += (lt * rf) + (lf * rt);
//             } else {
//               ways += (lt * rt) + (lf * rf);
//             }
//           }
//         }
//         dp[i][j][isTrue] = ways;
//       }
//     }
//   }
//   return dp[0][n-1][1];
// }

int main() {
  string s = "T|F&T";
  int n = s.size();

// Memoization
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 2)));
  cout << trueWays(0, n-1, s, true, dp) << endl;

// Tabulation
  // cout << trueWays(s) << endl;

  return 0;
}