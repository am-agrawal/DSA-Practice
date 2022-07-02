#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumPlatform(vector<int> arrival, vector<int> departure) {
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int n = arrival.size();
    int i = 1, j = 0;
    int platform = 1, curr = 1;

    while(i < n && j < n) {
        if(arrival[i] <= departure[j]) {
            i++;
            curr++;
        } else {
            curr--;
            j++;
        }

        if(curr > platform) {
            platform = curr;
        }
    }

    return platform;
}

int main() {
    cout << minimumPlatform({120, 50, 550, 200, 700, 850}, {600, 550, 700, 500, 900, 1000});

    return 0;
}