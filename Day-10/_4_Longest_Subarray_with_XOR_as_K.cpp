#include <iostream>
#include <vector>
#include <map>
using namespace std;

int noOfSubarrays(vector<int>& nums, int k) {
    int cnt = 0;
    int xorr = 0;
    map<int, int> mp;

    for(auto it : nums) {
        xorr = xorr ^ it;

        if(xorr == k) {
            cnt++;
        }
        if(mp.find(xorr ^ k) != mp.end()) {
            cnt += mp[xorr ^ k];
        }

        mp[xorr] += 1;
    }

    return cnt;
}

int main() {
    vector<int> nums = {4, 2, 2, 6, 4};
    cout << noOfSubarrays(nums, 6) << endl;

    return 0;
}