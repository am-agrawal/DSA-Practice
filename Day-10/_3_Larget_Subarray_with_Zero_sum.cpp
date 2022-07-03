#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int maxLength(vector<int> nums) {
    int maxLen = 0;
    unordered_map<int, int> map;
    int currSum = 0;

    for(int i = 0; i < nums.size(); i++) {
        currSum += nums[i];

        if(currSum == 0) maxLen = i+1;
        else if(map.find(currSum) != map.end()) {
            maxLen = max(maxLen, (i - map[currSum]));
        } else {
            map[currSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    cout << maxLength(nums) << endl;

    return 0;
}