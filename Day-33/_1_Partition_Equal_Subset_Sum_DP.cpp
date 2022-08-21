// Here we have an array of integers and we have to find that 
// can we partition this array into 2 subsequences such that they have equal sum
// if yes => true
// else => false

#include <iostream>
#include <vector>
using namespace std;

bool subsetSumK(vector<int>& nums, int target) {
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

  return prev[target];
}

bool equalSubsetSum(vector<int>& nums) {
  int totsum = 0;
  for(auto num : nums) {
    totsum += num;
  }

  if(totsum % 2 == 1) {
    return false;
  }

  return subsetSumK(nums, totsum / 2);
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  cout << equalSubsetSum(nums) << endl;

  return 0;
}