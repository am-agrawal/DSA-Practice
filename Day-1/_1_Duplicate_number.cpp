#include <iostream>
#include <vector>
using namespace std;

// Time - O(n) & Space - O(1)
// this function can only be used when this is sure that vector contains duplicate elements
int duplicateNumber(vector<int> nums) {
    int size = nums.size();
    int slow = nums[nums[0]], fast = nums[nums[nums[0]]];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = nums[0];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return fast;
}

// Time - O(n) & Space - O(n)
// this function could handle when there is no duplicate elements
int duplicateNumber2(vector<int> nums) {
    int size = nums.size();
    vector<int> frequency(size + 1, 0);
    for(int i = 0; i < size; i++) {
        frequency[nums[i]]++;
        if(frequency[nums[i]] == 2) return nums[i];
    }

    // If there is no duplicate number
    return -1;
}

int main() {
    cout << duplicateNumber({2, 5, 9, 6, 9, 3, 8, 9, 7, 1}) << endl;

    return 0;
}