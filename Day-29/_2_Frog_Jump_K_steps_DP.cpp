// It's a follow up problem of Frog Jump problem, there frog can jump one or two steps, but here steps can be K

#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

// Memoization
// Time => O(n) * O(k)
// Space => O(n) + O(n)
// int KfrogJump(int n, vector<int>& heights, int k) {
//   if(n == 0) return 0;
//   if(dp[n] != -1) return dp[n];

//   int res = INT_MAX;

//   for(int i = 1; i <= k; i++) {
//     if(n-i < 0) break;

//     res = min(res, KfrogJump(n-i, heights, k) + abs(heights[n] - heights[n-i]));
//   }

//   return res;
// }

// Tabulation
// Time => O(n) * O(k)
// Space => O(n)
int KfrogJump(int n, vector<int>& heights, int k) {
  dp[0] = 0;

  for(int i = 1; i <= n; i++) {
    int res = INT_MAX;
    for(int j = 1; j <= k; j++) {
      if(i-j < 0) break;

      res = min(res, (dp[i-j] + abs(heights[i] - heights[i-j])));
    }
    dp[i] = res;
  }

  return dp[n];
}

int main() {
  vector<int> heights = {10, 20, 30, 10};
  int n = heights.size();
  dp.resize(n+1, -1);
  int k = 2;
  cout << KfrogJump(n-1, heights, k) << endl;

  return 0;
}