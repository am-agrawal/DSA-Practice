#include <iostream>
#include <vector>
using namespace std;

int maxOnes(vector<int>& nums) {
    int mxOnes = 0, cnt = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            mxOnes = max(mxOnes, cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }
    mxOnes = max(mxOnes, cnt);

    return mxOnes;
}

int main() {
    vector<int> nums = {0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1};
    cout << maxOnes(nums) << endl;

    return 0;
}