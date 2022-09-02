// Here we have to find the longest subset out of an array of integers
// Where each pair as (a, b), a is divisible by b or vice versa
// Example => [1, 7, 3, 9, 4, 8, 5, 16]
// Our answer would be => [1, 4, 8, 16]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time => O(n * n) O(k + n)
// Space => O(2n)
vector<int> LDS(vector<int>& nums) {
  int n = nums.size(), res = 0, resInd = -1;
  vector<int> freq(n, 1), hash(n), ans;
  sort(nums.begin(), nums.end());
  for(int i = 0; i < n; i++) {
    hash[i] = i;
    for(int j = 0; j < i; j++) {
      if(nums[i] % nums[j] == 0 && freq[j] + 1 > freq[i]) {
        freq[i] = freq[j] + 1;
        hash[i] = j;
      }
    }
    if(freq[i] > res) {
      res = freq[i];
      resInd = i;
    }
  }

  while(res--) {
    ans.push_back(nums[resInd]);
    resInd = hash[resInd];
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main() {
  vector<int> nums = {1, 7, 3, 9, 4, 8, 5, 16};
  vector<int> ans = LDS(nums);

  for(auto i : ans) { cout << i << " "; }

  return 0;
}