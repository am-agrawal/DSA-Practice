#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time => Time - O(n^3) & Space - O(1)
vector<vector<int>> fourSum(vector<int> nums, int target) {
    vector<vector<int>> ans;

    if(nums.empty())
        return ans;

    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int lo = j+1, hi = n-1;
            int target_2 = target - nums[i] - nums[j];
            while(lo < hi) {
                int two_sum = nums[lo] + nums[hi];

                if(two_sum < target_2) {
                    lo++;
                } else if(two_sum > target_2) {
                    hi--;
                } else {
                    vector<int> quad;
                    quad.push_back(nums[i]);
                    quad.push_back(nums[j]);
                    quad.push_back(nums[lo]);
                    quad.push_back(nums[hi]);
                    ans.push_back(quad);
                    
                    while(lo < hi && nums[lo] == quad[2]) lo++;

                    while(lo < hi && nums[hi] == quad[3]) hi--;
                }
            }

            while(j + 1 < n && nums[j + 1] == nums[j]) j++;
        }

        while(i + 1 < n && nums[i + 1] == nums[i]) i++;
    }


    return ans;
}

int main() {
    vector<vector<int>> ans = fourSum({4, 3, 3, 4, 4, 2, 1, 2, 1, 1}, 9);

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}