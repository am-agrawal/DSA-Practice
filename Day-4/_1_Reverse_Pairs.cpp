#include <iostream>
#include <vector>
using namespace std;

// We have to count all the pairs (i, j) where i < j and A[i] > 2 * A[j]
// This problem is somewhat is similar to the Count Inversion problem
int merge(vector<int>& arr, int low, int mid, int high) {
    int cnt = 0;
    int right = mid + 1;
    for(int left = low; left <= mid; left++) {
        while(right <= high && arr[left] > (2LL * (long) arr[right])) {
            right++;
        }
        cnt += (right - (mid+1));
    }


    vector<int> temp;
    int i = low, j = mid+1;
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i++]);
    }
    while(j <= high) {
        temp.push_back(arr[j++]);
    }
    for(int i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }

    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high) {
    if(low >= high) return 0;
    int mid = (low + high) / 2;
    int count = 0;
    count += mergeSort(arr, 0, mid);
    count += mergeSort(arr, mid+1, high);
    count += merge(arr, low, mid, high);
    return count;
}

int reversePairs(vector<int> arr) {
    return mergeSort(arr, 0, arr.size()-1);
}

int main() {
    cout << reversePairs({40, 25, 19, 12, 9, 6, 2});

    return 0;
}