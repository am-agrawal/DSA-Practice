// Here we have an array of integers
// and we have to partition that into two subsets
// that their difference is as minimum as possible

#include <iostream>
#include <vector>
using namespace std;

int subsetSumMod(vector<int>& nums, int target) {
  int n = nums.size();
  vector<bool> prev(target+1, false);

  prev[0] = true;

  prev[nums[0]] = true;

  for(int i = 1; i < n; i++) {
    vector<bool> cur(target+1, false);
    cur[0] = true;
    for(int k = 1; k <= target; k++) {
      bool notTake = prev[k];
      bool take = (nums[i] <= k) ? prev[k-nums[i]] : false;
      cur[k] = (notTake | take);
    }
    prev = cur;
  }

  int searchRange = target / 2;
  int res = INT_MAX;
  for(int i = 0; i <= searchRange; i++) {
    if(prev[i]) {
      int s2 = target - i;

      res = min(res, abs(i - s2));
    }
  }

  return res;
}

int minDiffSubsets(vector<int>& nums) {
  int totsum = 0;
  int n = nums.size();

  for(int i = 0; i < n; i++) {
    totsum += nums[i];
  }

  return subsetSumMod(nums, totsum);
}

int main() {
  vector<int> nums = {2, 4};

  cout << minDiffSubsets(nums) << endl;

  return 0;
}