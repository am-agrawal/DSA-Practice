#include <iostream>
#include <vector>
using namespace std;


// Here we can take a number from array only once to form a combination whose sum is K
void print(int idx, vector<int> arr, vector<int>& ds, int k, vector<vector<int>>& ans) {
    if(k == 0) {
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < arr.size(); i++) {
        if(i > idx && arr[i] == arr[i - 1]) continue;

        if(arr[i] > k) break;
        ds.push_back(arr[i]);
        print(i+1, arr, ds, k - arr[i], ans);
        ds.pop_back();
    }
}

int main() {
    vector<int> ds;
    vector<vector<int>> ans;
    int k = 2;
    vector<int> arr = {1, 2, 1};
    print(0, arr, ds, k, ans);

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}