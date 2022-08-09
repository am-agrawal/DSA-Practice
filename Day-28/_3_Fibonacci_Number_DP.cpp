#include <iostream>
#include <vector>

using namespace std;

// Memoization
// Time => O(n)
// Space => O(n) + O(n) => [Recursion, dp]
int fib(int n, vector<int>& dp) {
  if(n <= 1) return n;

  if(dp[n] != -1) return dp[n];

  return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

// Tabulation
// Time => O(n)
// Space => O(n)
int fib(int n) {
  vector<int> dp(n);
  dp[0] = 0;
  dp[1] = 1;

  for(int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

// Tabulation
// Time => O(n)
// Space => O(1)
int fib(int n) {
  int prev1 = 0;
  int prev2 = 1;

  for(int i = 2; i <= n; i++) {
    int cur = prev1 + prev2;
    prev1 = prev2;
    prev2 = cur;
  }

  return cur;
}

// int main() {
//   int N = 7;

//   vector<int> dp(N+1, -1);

//   cout << fib(N, dp) << endl;

//   return 0;
// }

// 0 1 1 2 3 5 8 13