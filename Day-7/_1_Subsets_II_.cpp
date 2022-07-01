#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsets(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
    ans.push_back(ds);
    for(int i = idx; i < nums.size(); i++) {
        if(i != idx && nums[i] == nums[i - 1]) continue;

        ds.push_back(nums[i]);
        subsets(i+1, nums, ds, ans);
        ds.pop_back();
    }

}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<int> ds;
    vector<vector<int>> ans;

    // Necessary for not involving duplicate subsets into answer
    sort(nums.begin(), nums.end());
    subsets(0, nums, ds, ans);

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}