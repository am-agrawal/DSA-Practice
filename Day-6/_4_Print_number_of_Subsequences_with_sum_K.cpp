#include <iostream>
#include <vector>
using namespace std;

int print(int idx, int arr[], int n, int sum, int k) {
    if(sum > k) return 0;
    if(idx == n) {
        if(sum == k) return 1;
        else return 0;
    }

    int l = print(idx+1, arr, n, sum+arr[idx], k);
    int h = print(idx+1, arr, n, sum, k);

    return l + h;
}

int main() {
    int n = 3;
    int k = 2;
    int arr[] = {1, 2, 1};
    int r = print(0, arr, n, 0, k);
    cout << r << endl;
    return 0;
}