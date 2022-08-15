// Here in this problem, a frog is placed on starting stair and it want to reach last stair
// So, height of stairs is represented by array of integers of size n => [0, n-1]
// Frog can jump 1 step or 2 steps
// Energy spent by frog at each step would be abs([height of next step] - [height of current step])
// So we have to find minimum energy used by frog to reach nth [n-1] stair from starting stair

#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

// Memoization
// Time => O(n)
// Space => O(n) + O(n)
// int frogJump(int n, vector<int>& heights) {
//   if(n == 0) return 0;
//   if(dp[n] != -1) return dp[n];

//   int oneStep = frogJump(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
//   int twoStep = INT_MAX;
//   if(n > 1) twoStep = frogJump(n-2, heights, dp) + abs(heights[n] - heights[n-2]);

//   return dp[n] = min(oneStep, twoStep);
// }

// Tabulation
// Time => O(n)
// Space => O(n)
// int frogJump(int n, vector<int>& heights) {
//   dp[0] = 0;
//   for(int i = 1; i <= n; i++) {
//     dp[i] = min((dp[i-1] + abs(heights[i] - heights[i-1])), (i > 1 ? (dp[i-2] + abs(heights[i] - heights[i-2])) : INT_MAX));
//   }
//   return dp[n];
// }

// Tabulation (space optimization)
// Time => O(n)
// Space => O(1)
int frogJump(int n, vector<int>& heights) {
  int prev = 0, prev2 = 0;
  for(int i = 1; i <= n; i++) {
    int cur = min((prev + abs(heights[i] - heights[i-1])), (i > 1 ? (prev2 + abs(heights[i] - heights[i-2])) : INT_MAX));
    prev2 = prev;
    prev = cur;
  }
  return prev;
}

int main() {
  vector<int> heights = {10, 20, 30, 10};
  int n = heights.size();
  dp.resize(n+1, -1);

  cout << frogJump(n-1, heights) << endl;

  return 0;
}