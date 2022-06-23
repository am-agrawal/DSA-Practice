#include <iostream>
#include <vector>
using namespace std;

// Time - O(n) & Space - O(1)
// Take 2 passes
void sort1(vector<int>& arr) {
    vector<int> frequency(3, 0);
    int size = arr.size();
    for(int i = 0; i != size; i = i + 1) {
        frequency[arr[i]]++;
    }
    int ptr = 0;
    for(int i = 0; i != size; i = i + 1) {
        while(frequency[ptr] == 0) {
            ptr++;
        }
        arr[i] = ptr;
        frequency[ptr]--;
    }
}


// Time - O(n) & Space - O(1)
// Take 1 passes
// User 3 pointers - low, mid and high
void sort(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {1, 0, 1, 2, 0, 0, 1, 2, 1};
    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl << endl;
    sort(arr);
    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl << endl;

    return 0;
}