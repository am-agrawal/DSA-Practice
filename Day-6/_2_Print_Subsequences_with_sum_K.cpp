#include <iostream>
#include <vector>
using namespace std;

void print(int idx, int arr[], vector<int>& ans, int n, int sum, int k) {
    if(idx == n) {
        if(sum == k) {
            for(auto i : ans) {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }

    ans.push_back(arr[idx]);
    print(idx+1, arr, ans, n, sum+arr[idx], k);
    ans.pop_back();
    print(idx+1, arr, ans, n, sum, k);
}

int main() {
    vector<int> ans;
    int n = 3;
    int k = 2;
    int arr[] = {1, 2, 1};
    print(0, arr, ans, n, 0, k);

    return 0;
}