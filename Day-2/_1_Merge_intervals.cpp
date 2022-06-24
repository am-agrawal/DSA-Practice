#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {
    vector<vector<int>> mergedIntervals;
    int size = intervals.size();
    if(size < 2) return intervals;

    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];

    for(auto it : intervals) {
        if(it[0] <= temp[1]) {
            temp[1] = max(it[1], temp[1]);
        } else {
            mergedIntervals.push_back(temp);
            temp = it;
        }
    }
    mergedIntervals.push_back(temp);
    return mergedIntervals;
}

int main() {
    vector<vector<int>> resultedIntervals = mergeIntervals({{1, 3}, {1, 6}, {8, 10}, {9, 9}, {15, 18}});
    for(vector<int> t : resultedIntervals) {
        cout << " [ ";
        for(int i : t) {
            cout << i << " ";
        }
        cout << "] ";
    }

    return 0;
}