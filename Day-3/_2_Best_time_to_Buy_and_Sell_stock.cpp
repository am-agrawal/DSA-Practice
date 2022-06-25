#include <iostream>
#include <vector>
using namespace std;

// This prblem can be done in Time - O(n) & Space - O(1)
// using 2-Pointer approach and a simple pass also
int profit(vector<int> prices) {
    int profit = 0;
    int mn = prices[0];
    int size = prices.size();

    for(int i = 0; i < size; i++) {
        mn = min(mn, prices[i]);
        profit = max(profit, prices[i] - mn);
    }

    return profit;
}

int main() {
    cout << profit({7, 1, 5, 3, 6, 4});

    return 0;
}