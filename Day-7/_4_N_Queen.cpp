#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    // To check if the position is valid for a Queen of not

    // => \ NW
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') return false;
    }
    // => | N
    for(int i = row; i >= 0; i--) {
        if(board[i][col] == 'Q') return false;
    }
    // => / NE
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') return false;
    }
    // => - E
    for(int i = col; i < n; i++) {
        if(board[row][i] == 'Q') return false;
    }
    // => \ SE
    for(int i = row, j = col; i < n && j < n; i++, j++) {
        if(board[i][j] == 'Q') return false;
    }
    // => | S
    for(int i = row; i < n; i++) {
        if(board[i][col] == 'Q') return false;
    }
    // => / SW
    for(int i = row, j = col; i < n && j >= 0; i++, j--) {
        if(board[i][j] == 'Q') return false;
    }
    // => - W
    for(int i = col; i >= 0; i--) {
        if(board[row][i] == 'Q') return false;
    }

    return true;
}

// Recursively check and fill the board
// When all the columns are filled
// Insert the -[board]- into -[answer]-
void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if(col == n) {
        ans.push_back(board);
        return;
    }

    // Here we check for each row
    // and do recursion with that choice
    // backtrack when a choice ends
    // clear the previously chosen position
    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }

    solve(0, board, ans, n);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << endl;
        }
        cout << endl;
    }

    return 0;
}