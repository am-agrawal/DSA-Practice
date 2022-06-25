#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& image) {
    int n = image.size();

    // First Transpose the Matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(image[i][j], image[j][i]);
            // int t = image[i][j];
            // image[i][j] = image[j][i];
            // image[j][i] = t;
        }
    }

    // Then reverse all the rows
    for(int i = 0; i < n; i++) {
        reverse(image[i].begin(), image[i].end());
    } 

}

int main() {
    vector<vector<int>> image = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(image);

    for(auto it : image) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}