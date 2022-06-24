#include <iostream>
#include <vector>
using namespace std;

vector<int> pascalTriangle(int numRows) {
    vector<vector<int>> result(numRows);
    for(int i = 0; i < numRows; i++) {
        result[i].resize(i+1, 1);
        int t = i - 1;
        while(t > 0) {
            result[i][t] = result[i - 1][t - 1] + result[i - 1][t];
            t--;
        }
    }
    return result[numRows - 1];
}

int main() {
    vector<int> result = pascalTriangle(5);
    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}