#include <iostream>
#include <vector>
using namespace std;

// There are 2 types of this problem :-
// Type 1 -
//      Every row is sorted
//      Next row's first element will be greater than previous row's last element

// This prblem can be solved using binary search
// Example - _________
//          |0 1 2 3 4|
//          |4 5 6 7 8|
//          ___________
// Binary search applied from 0 -----> (n * m - 1)
// 0 to 8       => mid = (l + (h / 2))      => 4
// We can easily convert this number to row and column address and
// and check if the number at that address is equal to the target or greater or lesser to the target
// Row number =   4 / (no. of columns) =>      4 / 5 = 1
// Column number =  4 % (no. of columns) =>    4 % 5 = 0
vector<int> search1(vector<vector<int>> matrix, int target) {
    int r = matrix.size();
    int c = matrix[0].size();
    int l = 0, h = (r * c - 1);
    int mid;

    while(l <= h) {
        mid = (l + h) / 2;
        int rn = mid / c;
        int cn = mid % c;
        if(matrix[rn][cn] == target) {
            return {rn, cn};
        }
        if(matrix[rn][cn] < target) l = mid + 1;
        else h = mid - 1;
    }

    return {-1, -1};
}

// Type 2 -
//      Every row is sorted
//      Every column is sorted
vector<int> search2(vector<vector<int>> matrix, int target) {
    int r = matrix.size();
    int c = matrix[0].size();
    int i = 0, j = c - 1;
    while(i < r && j >= 0) {
        if(matrix[i][j] == target) {
            return {i, j};
        } else if(matrix[i][j] < target) i++;
        else j--;
    }
    return {-1, -1};
}

int main() {
    vector<int> idx = search1({{1, 3, 5, 7}, {8, 10, 12, 15}, {17, 21, 25, 30}}, 21);
    cout << "Matrix["<< idx[0] << "][" << idx[1] << "] = 21" << endl;

    idx = search1({{1, 3, 5, 7}, {8, 10, 12, 15}, {17, 21, 25, 30}}, 21);
    cout << "Matrix["<< idx[0] << "][" << idx[1] << "] = 21";

    return 0;
}