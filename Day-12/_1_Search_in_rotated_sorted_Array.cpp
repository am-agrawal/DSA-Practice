#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1;
    int mid;
    while(l <= h) {
        mid = (l + h) / 2;
        if(nums[mid] == target) {
            return mid;
        }

        if(nums[l] <= nums[mid]) {
            if(nums[l] <= target && target <= nums[mid]) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if(nums[mid] <= target && target <= nums[h]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << search(nums, target);

    return 0;
}