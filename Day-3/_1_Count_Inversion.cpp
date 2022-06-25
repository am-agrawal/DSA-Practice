#include <iostream>
#include <vector>
using namespace std;

// We can do this problem in Time - O(nlogn) & Space - O(n)
// by using Merge sort and just optimizing merging operation
// while merging : if a number in right side array is smaller than a number in left side array, then we have to count the numbers in left array from that number
// and after doing it continuously we will get the result
// Example - Merging : [2, 3, 5] & [1, 4] , count;
// 1 is smaller than 2 then it means 2, 3, 5 are greater than 1, we'll increase count, count += 3
// after some steps our pointers are on 5 & 4 and 4 is smaller than 5 we'll increse count by 1, count += 1

int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i, j, k;
    int count = 0;
    i = left;
    j = mid;
    k = left;
    while((i <= mid - 1) && (j <= right)) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            // [3, 4] & [1]
            //  0  1     2
            //  l        mid
            //  i        j
            // count += (2 - 0);
            count += (mid - i);
        }
    }

    while(i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    while(j <= right) {
        temp[k++] = arr[j++];
    }
    for(int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

int mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    int mid, count = 0;
    if(right > left) {
        mid = (left + right) / 2;

        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);

        count += merge(arr, temp, left, mid + 1, right);
    }

    return count;
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    int size = arr.size();
    vector<int> temp(size);
    int res = mergeSort(arr, temp, 0, size - 1);

    cout << res << endl;

    return 0;
}

// => [5, 4, 3, 2, 1]
// (5, 4), (5, 3), (5, 2), (5, 1),
// (4, 3), (4, 2), (4, 1),
// (3, 2), (3, 1),
// (2, 1)