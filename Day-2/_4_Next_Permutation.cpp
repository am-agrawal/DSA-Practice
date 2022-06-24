#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextPermutations(vector<int> arr) {
    int i, j, size = arr.size();
    
    // Edge case : If size is 1 then there is no need for finding next permutation because there is only one permutation
    if(size == 1) return arr;

    // For finding the downfall point
    // For example - [1, 3, 5, 4, 2]
    //          5
    //      3       4
    //   1              2
    // Here 3 is the downfall point : A[i] = 3
    for(i = size - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1]) {
            break;
        }
    }

    // Edge case : If given is the last permutation then we have to return first permutation
    // That will be the reverse of given permutation
    if(i == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // Find the greater number from A[i] then mark it as A[j]
    for(j = size - 1; j >= 0; j--) {
        if(arr[j] > arr[i]) {
            break;
        }
    }

    // Swap A[i] and A[j], it will give a greater permutation than given permutation
    swap(arr[i], arr[j]);

    // Reverse numbers from A[i + 1] to A[size - 1];
    // It is the key step because it will give the exact next permutation of given permutation
    reverse(arr.begin() + i + 1, arr.end());

    return arr;
}

int main() {
    vector<int> r = nextPermutations({1, 3, 5, 4, 2});
    for(auto i : r) {
        cout << i << " ";
    }

    return 0;
}