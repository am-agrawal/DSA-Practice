#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetSums(int idx, int sum, vector<int>& arr, vector<int>& sums) {
    if(idx == arr.size()) {
        sums.push_back(sum);
        return;
    }
    subsetSums(idx+1, sum+arr[idx], arr, sums);
    subsetSums(idx+1, sum, arr, sums);
}


int main() {
    vector<int> ans;
    vector<int> arr = {1, 2, 3};
    subsetSums(0, 0, arr, ans);
    sort(ans.begin(), ans.end());
    for(auto i : ans) {
        cout << i << endl;
    }

    return 0;
}