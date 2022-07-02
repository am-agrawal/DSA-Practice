#include <iostream>
#include <vector>
using namespace std;

// int storedWater(vector<int> nums) {
//     int unit = 0;
//     int n = nums.size();
//     vector<int> left(n), right(n);
//     left[0] = nums[0];
//     right[n-1] = nums[n-1];

//     for(int i = 1, j = n-2; i < n && j >= 0; i++, j--) {
//         left[i] = max(left[i-1], nums[i]);
//         right[j] = max(right[j+1], nums[j]);
//     }

//     for(int i = 0; i < n; i++) {
//         unit += (min(left[i], right[i]) - nums[i]);
//     }

//     return unit;
// }

// 2-Pointer Approach
int storedWater(vector<int> height) {
    int unit = 0;
    int l = 0, r = height.size() - 1, leftmax = 0, rightmax = 0;

    while(l < r) {
        if(height[l] <= height[r]) {

            if(height[l] >= leftmax) {
                leftmax = height[l];
            } else {
                unit += (leftmax - height[l]);
            }

            l++;
        } else {

            if(height[r] >= rightmax) {
                rightmax = height[r];
            } else {
                unit += (rightmax - height[r]);
            }

            r--;
        }
    }

    return unit;
}


int main() {
    cout << storedWater({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << endl;

    return 0;
}