#include <iostream>
#include <vector>
using namespace std;

void permutation(int idx, vector<int>& nums, vector<vector<int>>& ans) {
    if(idx == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for(int i = idx; i < nums.size(); i++) {
        swap(nums[i], nums[idx]);
        permutation(idx+1, nums, ans);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> ans;
    permutation(0, nums, ans);

    return ans;
}

int main() {
    vector<vector<int>> ans = permute({1, 2, 3});
    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}