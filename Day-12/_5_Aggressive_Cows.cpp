#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& stalls, int dist, int nCows) {
    int cnt = 1;
    int coord = stalls[0];
    int size = stalls.size();

    for(int i = 1; i < size; i++) {
        if(stalls[i] - coord >= dist) {
            coord = stalls[i];
            cnt++;
        }
    }

    return (cnt >= nCows) ? true : false;
}

int aggresiveCow(vector<int>& stalls, int nCows) {
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();
    int l = 1, h = stalls[n - 1] - stalls[0];

    while(l <= h) {
        int mid = (l + h) >> 1;
        if(isValid(stalls, mid, nCows)) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return h;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int nCows = 3;

    cout << aggresiveCow(stalls, nCows);

    return 0;
}