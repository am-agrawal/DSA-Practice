#include <iostream>
#include <vector>
using namespace std;

// Here we are given an array, which is sorted and contains duplicates
// Example => [1, 1, 2, 2, 2, 3, 3]
// Output => [1, 2, 3, x, x, x, x]
// x => It doesn't matter to us if it is duplicate of any previous value
// Only [1, 2, 3] matters to answer

// Approach 1 => Using Set of integers to store all the numbers, now set will not contain any duplicate so now we can assign the numbers from Set to Array
// Time => O(2n) & Space => O(n)

// Approach 2 => 2-Pointer method
// Time => O(n) & Space => O(1)

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 1;
    while(j < n) {
        if(nums[i] != nums[j]) {
            nums[++i] = nums[j++];
        } else {
            j++;
        }
    }
    return i+1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 3, 3};
    int cnt = removeDuplicates(nums);

    for(int i = 0; i < cnt; i++) {
        cout << nums[i] << "  ";
    }

    return 0;
}