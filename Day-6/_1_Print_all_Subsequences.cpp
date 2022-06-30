#include <iostream>
#include <vector>
using namespace std;

void print(int idx, vector<int> &ans, int arr[], int n) {
    if(idx == n) {
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[idx]);
    print(idx+1, ans, arr, n);
    ans.pop_back();
    print(idx+1, ans, arr, n);
}

int main() {
    vector<int> ans;
    int nums[] = {3, 1, 2};
    print(0, ans, nums, 3);

    return 0;
}