// In this problem, money in each house is represented by an array of integers
// A Robber wants to steal as much money as possible from Houses
// * There are security systems in the Houses, that if Robber steal from two adjacent houses then Police will get to know about theft and Robber will be caught
// * first and last house are Adjacent
// We have to find maximum value that can be steal from houses without letting Police to know about this.

#include <iostream>
#include <vector>
using namespace std;

int maxNonAdjSum(vector<int>& nums) {
  int n = nums.size();
  int prev = nums[0];
  int prev2 = 0;

  for(int i = 1; i < n; i++) {
    int take = nums[i] + prev2;
    int notTake = prev;

    int mx = max(take, notTake);

    prev2 = prev;
    prev = mx;
  }

  return prev;
}

int houseRobber(vector<int>& houses) {
  vector<int> temp1, temp2;
  int n = houses.size();
  for(int i = 0; i < n; i++) {
    if(i != 0) temp1.push_back(houses[i]);
    if(i != n-1) temp2.push_back(houses[i]);
  }

  return max(maxNonAdjSum(temp1), maxNonAdjSum(temp2));
}

int main() {
  vector<int> houses = {1, 2, 3, 1};

  cout << houseRobber(houses) << endl;

  return 0;
}