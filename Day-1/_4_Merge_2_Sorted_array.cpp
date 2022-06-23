#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// We have to merge 2 arrays with O(1)
// Input - a1[] = {10}
//          a2[] = {2, 3}
// Output - a1[] = {2}
//          a2[] = {3, 10}
void mergeTwoSortedArray(vector<int>& a1, vector<int>& a2) {
    int size = a1.size();
    for(int i = 0; i < size; i++) {
        if(a1[i] > a2[0]) {
            swap(a1[i], a2[0]);
        }
        sort(a2.begin(), a2.end());
    }
}

int main() {
    vector<int> a1 = {10};
    vector<int> a2 = {2, 3};

    mergeTwoSortedArray(a1, a2);
    cout << "a1 : ";
    for(int i : a1) {
        cout << i << " ";
    } cout << endl;
    cout << "a2 : ";
    for(int i : a2) {
        cout << i << " ";
    } cout << endl;

    return 0;
}