#include <iostream>
#include <vector>
using namespace std;

bool print(int idx, int arr[], vector<int>& ans, int n, int sum, int k) {
    if(idx == n) {
        if(sum == k) {
            for(auto i : ans) {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    ans.push_back(arr[idx]);
    if(print(idx+1, arr, ans, n, sum+arr[idx], k)) return true;
    ans.pop_back();
    if(print(idx+1, arr, ans, n, sum, k)) return true;

    return false;
}

int main() {
    vector<int> ans;
    int n = 3;
    int k = 2;
    int arr[] = {1, 2, 1};
    print(0, arr, ans, n, 0, k);

    return 0;
}