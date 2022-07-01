#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& freq) {
    if(ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(!freq[i]) {
            freq[i] = true;
            ds.push_back(nums[i]);
            permutation(nums, ds, ans, freq);
            ds.pop_back();
            freq[i] = false;
        }
    }

}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<int> ds;
    vector<vector<int>> ans;
    vector<bool> freq(nums.size(), false);
    permutation(nums, ds, ans, freq);

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}