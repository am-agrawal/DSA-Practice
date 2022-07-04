#include <iostream>
#include <vector>
using namespace std;

// Here We are given an array of integers, where every number appears twice except one number, and we have to find thet number
// We can use Binary search for this problem because
// Example => [1, 1, 2, 3, 3, 4, 4]
//            [0, 1, 2, 3, 4, 5, 6]
// We'll take, low = 0 & high = 5
// high = arr.size() - 2;
// Now we use a while loop (low <= high)
// if mid is even && if arr[mid] == arr[mid + 1] => low = mid + 1
// else high = mid - 1
// if mid is odd && if arr[mid] == arr[mid - 1] => low = mid + 1
// else high = mid - 1
// return high

int singleNumber(vector<int>& arr) {
    int l = 0, h = arr.size() - 2;
    int mid;
    while(l < h) {
        mid = (l + h) / 2;

        if(mid % 2 == 0) {
            if(arr[mid] == arr[mid + 1]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        } else {
            if(arr[mid] == arr[mid - 1]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
    }

    return h;
}

int main() {
    vector<int> arr = {1, 1, 3, 3, 4, 4, 5};

    cout << singleNumber(arr);

    return 0;
}