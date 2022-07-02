#include <iostream>
#include <vector>
using namespace std;

// Sudoku is a 9x9 matrix which is further divided into 9 3x3 matices
// Three row in Sudoku solving
// 1. Any column of 9x9 contains each number 1-9
// 2. Any row of 9x9 contians each number 1-9
// 3. Any 3x3 contains each number 1-9
// Input is a 9x9 matrix which is partially filled


// This function is to check if the given character can be filled or not without violating the rules
bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    // // Column check
    // for(int i = 0; i < row; i++) {
    //     if(board[i][col] == c) return false;
    // }

    // // Row check
    // for(int i = 0; i < col; i++) {
    //     if(board[row][i] == c) return false;
    // }

    // // check in the 3x3 matrix
    // row = ((row / 3 * 3) + 3);
    // col = ((col / 3 * 3) + 3);
    // for(int i = row - 3; i < row; i++) {
    //     for(int j = col - 3; j < col; j++) {
    //         if(board[i][j] == c) return false;
    //     }
    // }

    // Same working
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == c) return false;

        if(board[i][col] == c) return false;

        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }

    return true;
}

// This is the recursive function that will check if the place is empty
// then fill it and check for other empty places
// If it got to reach the end of sudoku then it will return true
// but if we reach a point where we can't fill it with 1-9 then we'll return false and check for another recursion
bool solve(vector<vector<char>>& board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {

            if(board[i][j] == '.') {

                for(char c = '1'; c <= '9'; c++) {
                    if(isValid(board, i, j, c)) {
                        board[i][j] = c;

                        if(solve(board) == true)
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}


int main() {
    vector<vector<char>> board =   {{'5', '3', '.', '6', '7', '8', '9', '.', '2'},
                                    {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                                    {'.', '9', '8', '3', '4', '2', '5', '6', '7'},
                                    {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                                    {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                                    {'7', '1', '3', '9', '.', '4', '8', '5', '6'},
                                    {'9', '6', '.', '5', '3', '7', '2', '8', '4'},
                                    {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                                    {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    solveSudoku(board);
    for(auto it : board) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}