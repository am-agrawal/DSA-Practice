#include <iostream>
#include <vector>
using namespace std;

void combinations(int idx, int arr[], vector<int>& ds, int k, int n, vector<vector<int>>& ans) {
    if(idx == n) {
        if(k == 0) {
            ans.push_back(ds);
        }
        return;
    }
    

    if(arr[idx] <= k) {
        ds.push_back(arr[idx]);
        combinations(idx, arr, ds, k - arr[idx], n, ans);
        ds.pop_back();
    }
    combinations(idx + 1, arr, ds, k, n, ans);
}

int main() {
    vector<int> ds;
    vector<vector<int>> ans;
    int arr[] = {2, 3, 6, 7};
    int k = 7;
    combinations(0, arr, ds, k, 4, ans);
    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}