// Here we have to find the length of Longest Bitonic Subsequence
// Bitonic Subsequence means => first strictly increasing then it could be strictly decreasing
// Example => [1, 4, 2, 5, 11, 10, 4, 3, 1, 9]
// Answer => [1, 2, 5, 11, 10, 4, 3, 1] => Len = 8

#include <iostream>
#include <vector>
using namespace std;

// Time => O(2 * n ^ 2)
// Space => O(2n)
int LBS(vector<int>& nums) {
  int n = nums.size(), res = 0;
  vector<int> dp1(n, 1), dp2(n, 1);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(nums[j] < nums[i] && dp1[j] + 1 > dp1[i]) {
        dp1[i] = dp1[j] + 1;
      }
    }
  }

  for(int i = n-1; i >= 0; i--) {
    for(int j = n-1; j > i; j--) {
      if(nums[j] < nums[i] && dp2[j] + 1 > dp2[i]) {
        dp2[i] = dp2[j] + 1;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    res = max(res, dp1[i] + dp2[i] - 1);
  }

  return res;
}

int main() {
  vector<int> nums = {1, 4, 2, 5, 11, 10, 4, 3, 1, 9};

  cout << LBS(nums) << endl;

  return 0;
}