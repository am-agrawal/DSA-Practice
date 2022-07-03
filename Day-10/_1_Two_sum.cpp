#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.find(target - nums[i]) != mp.end()) {
            res.push_back(mp[target - nums[i]]);
            res.push_back(i);
            return res;
        }
        mp[nums[i]] = i;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 7};
    vector<int> ans = twoSum(nums, 6);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}