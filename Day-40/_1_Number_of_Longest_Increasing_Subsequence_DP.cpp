// Here we have an array of integers and we need to find the number of longest increasing subsequences

#include <iostream>
#include <vector>
using namespace std;

// Time => O(n ^ 2)
// Space => O(2n) ~ O(n)
int NLIS(vector<int>& nums) {
  int n = nums.size();
  vector<int> freq(n, 1), count(n, 1);
  int resLen = 0, resCnt = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(nums[j] < nums[i]) {
        if(freq[j] + 1 > freq[i]) {
          freq[i] = freq[j] + 1;
          count[i] = count[j];
        } else if(freq[j] + 1 == freq[i]) {
          count[i] += count[j];
        }
      }
    }
    if(resLen < freq[i]) {
      resLen = freq[i];
      resCnt = count[i];
    }
  }

  return resCnt;
}

int main() {
  vector<int> nums = {1, 7, 5, 2, 6, 10, 12};

  cout << NLIS(nums) << endl;

  return 0;
}