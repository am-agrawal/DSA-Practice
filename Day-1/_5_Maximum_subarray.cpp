#include <iostream>
#include <vector>
using namespace std;

// We can easily do this using Time - O(n^2) or O(n^3)
// But we have to do this using Time - O(n)
// For that we are using Kadane algorithm
int maximumSum(vector<int> arr) {
    int currMax = 0, globalMax = arr[0];
    for(int i = 0; i < arr.size(); i++) {
        currMax = max(currMax + arr[i], arr[i]);
        globalMax = max(currMax, globalMax);
    }
    return globalMax;
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maximumSum(arr) << endl;

    return 0;
}