// Here we have a string and we have to partition it into substrings which are palindrome
// We need to find the minimum number of partition

#include <iostream>
#include <vector>
using namespace std;

// To check a substring, if it is palindrome or not
bool isPalindrome(int l, int h, string str) {
  while(l < h) {
    if(str[l++] != str[h--]) return false;
  }
  return true;
}

// Memoization
int minPartition(int i, string s, vector<int>& dp) {
  if(i == s.length()) {
    return 0;
  }

  if(dp[i] != -1) return dp[i];

  int minCount = INT_MAX;
  for(int j = i; j < s.length(); j++) {
    if(isPalindrome(i, j, s)) {
      int count = 1 + minPartition(j + 1, s, dp);
      minCount = min(count, minCount);
    }
  }
  return dp[i] = minCount;
}

// Tabulation
int minPartition(string s) {
  int n = s.length();
  vector<int> dp(n+1, 0);
  for(int i = n-1; i >= 0; i--) {
    int minCount = INT_MAX;
    for(int j = i; j < n; j++) {
      if(isPalindrome(i, j, s)) {
        int count = 1 + dp[j + 1];
        minCount = min(minCount, count);
      }
    }
    dp[i] = minCount;
  }
  return dp[0] - 1;
}

int main() {
  string s = "aabb";
  int n = s.size();

// Memoization
  // vector<int> dp(n, -1);
  // cout << minPartition(0, s, dp) - 1 << endl;

// Tabulation
  cout << minPartition(s) << endl;

  return 0;
}