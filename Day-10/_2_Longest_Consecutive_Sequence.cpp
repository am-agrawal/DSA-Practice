#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Here we are given an unsorted array and we have to find the length of longest subsequence
// Example => [102, 4, 100, 1, 101, 3, 2]
// There are two sequences => [100, 101, 102] & [1, 2, 3, 4]
// So the maximum length would be 4

// Approach 1
// Sort the array then linearly iterate the array and we'll get the result
// Time => O(nlogn) + O(n) & Space => O(1) [It could be O(n) if we count space used by Merge sort]

// Approach 2
// Use a Set
// First put all the elements of the array into the Set
// Then iterate over the array and check if the nums[i] - 1 is present in the Set
// if yes, then continue
// but if no, then count all the numbers from nums[i] to nums[i]+1, nums[i]+2, .....
// maximum count will be our answer

int maxLength(vector<int>& nums) {
    int len = 0;
    unordered_set<int> set;
    for(auto num : nums) {
        set.insert(num);
    }

    for(auto num : nums) {
        if(set.find(num - 1) == set.end()) {
            int currNum = num;
            int currLen = 1;

            while(set.count(currNum+1)) {
                currNum++;
                currLen++;
            }

            len = max(len, currLen);
        }
    }

    return len;
}

int main() {
    vector<int> nums = {102, 4, 100, 1, 101, 3, 2};
    cout << maxLength(nums);

    return 0;
}