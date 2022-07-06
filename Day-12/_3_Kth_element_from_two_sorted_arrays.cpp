#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr1, vector<int>& arr2, int k) {
    if(arr1.size() > arr2.size()) return search(arr2, arr1, k);

    int n1 = arr1.size();
    int n2 = arr2.size();
    int l = max(0, k - n2), h = min(k, n1);

    while(l <= h) {
        int cut1 = (l + h) >> 1;
        int cut2 = k - cut1;

        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if(left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if(left1 > right2) {
            h = cut1 - 1;
        } else {
            l = cut1 + 1;
        }
    }

    return 0;
}

int main() {
    vector<int> arr1 = {1, 4, 6};
    vector<int> arr2 = {2, 5};

    cout << search(arr1, arr2, 3);

    return 0;
}