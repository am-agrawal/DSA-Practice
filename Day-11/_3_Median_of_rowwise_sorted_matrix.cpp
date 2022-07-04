#include <iostream>
#include <vector>
using namespace std;

int upperBound(vector<int>& nums, int n) {
    int l = 0, r = nums.size() - 1;
    int mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if(nums[mid] <= n) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l;
}

int medianOfMatrix(vector<vector<int>>& mat) {
    int l = 1, h = 1e9;
    int n = mat.size();
    int m = mat[0].size();
    int mid;

    while(l <= h) {
        mid = (l + h) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += upperBound(mat[i], mid);
        }

        if(cnt <= (n * m) / 2) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return l;
}

int main() {
    vector<vector<int>> mat =  {{1, 3, 6},
                                {2, 6, 9},
                                {3, 6, 9}};

    cout << medianOfMatrix(mat);

    return 0;
}