#include <iostream>
#include <vector>
using namespace std;

// We can solve this problem using recursion
// int uniquePath(int i, int j, int n, int m) {
//     if(i == (n - 1) && j == (m - 1)) return 1;
//     if(i >= n || j >= m) return 0;
//     else return uniquePath(i+1, j, n, m) + uniquePath(i, j+1, n, m);
// }

// int uniquePath(int n, int m) {
//     vector<vector<int>> grid(n, vector<int>(m, 1));
//     for(int i = 1; i < n; i++) {
//         for(int j = 1; j < m; j++) {
//             grid[i][j] = grid[i-1][j] + grid[i][j-1];
//         }
//     }
//     return grid[n-1][m-1];
// }

// Using Dynamic Programming
// int uniquePath(int i, int j, int n, int m, vector<vector<int>>& dp) {
//     if(i == (n-1) && j == (m-1)) return 1;
//     if(i >= n || j >= m) return 0;

//     if(dp[i][j] != -1) return dp[i][j];

//     else return dp[i][j] = uniquePath(i+1, j, n, m, dp) + uniquePath(i, j+1, n, m, dp);
// }

// We can solve this problem by finding combinations
// N
//  C
//   R
// => N = (n + m - 2);
// => R = m - 1;
// then NCR will be our answer
int uniquePath(int n, int m) {
    int N = n + m - 2;
    int R = m - 1;
    double res = 1;

    // For fing NCR
    for(int i = 1; i <= R; i++) {
        res = res * (N - R + i) / i;
    }

    return (int)res;
}

int main() {
    // vector<vector<int>> dp(2, vector<int>(4, -1));
    cout << uniquePath(2, 4) << endl;

    return 0;
}