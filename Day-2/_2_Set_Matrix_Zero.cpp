#include <iostream>
#include <vector>
using namespace std;

void setMatrixZero(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<bool> rowZero(rows, false);
    vector<bool> colZero(cols, false);

    // finding rows and cols which has to be zero
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 0) {
                rowZero[i] = true;
                colZero[j] = true;
            }
        }
    }

    // setting rows and cols zero
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(rowZero[i] || colZero[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{0, 1, 1, 0},
                                    {1, 1, 1, 1},
                                    {1, 0, 0, 1}};
    setMatrixZero(matrix);
    for(auto it : matrix) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}