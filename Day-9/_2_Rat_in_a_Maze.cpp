#include <iostream>
#include <vector>
using namespace std;

// Here in this problem, we have find the paths by which rat can reach cell[n-1][m-1]
// We have to return our answer as vector<string>
// 'D' => Down, 'U' => Up, 'L' => Left and 'R' => Right
// Solution should be in lexicographical order => D|L|R|U
// Time => O(4^(n*m)) & Space => O(m*n)
void solve(int i, int j, vector<vector<int>>& maze, int n, vector<string>& ans, string move, vector<vector<bool>>& vis) {
    if(i == n-1 && j == n-1) {
        ans.push_back(move);
        return;
    }

    // Downward
    if(i+1 < n && !vis[i+1][j] && maze[i+1][j] == 1) {
        vis[i+1][j] = true;
        solve(i+1, j, maze, n, ans, move+'D', vis);
        vis[i+1][j] = false;
    }

    // Left
    if(j-1 >= 0 && !vis[i][j-1] && maze[i][j-1] == 1) {
        vis[i][j-1] = true;
        solve(i, j-1, maze, n, ans, move+'L', vis);
        vis[i][j-1] = false;
    }

    // Right
    if(j < n && !vis[i][j+1] && maze[i][j+1] == 1) {
        vis[i][j+1] = true;
        solve(i, j+1, maze, n, ans, move+'R', vis);
        vis[i][j+1] = false;
    }

    // Up
    if(i-1 >= 0 && !vis[i-1][j] && maze[i-1][j] == 1) {
        vis[i-1][j] = true;
        solve(i-1, j, maze, n, ans, move+'U', vis);
        vis[i-1][j] = false;
    }
}

vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    string move = "";
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    solve(0, 0, m, n, ans, move, vis);

    return ans;
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    vector<string> ans = findPath(maze, 4);

    for(auto it : ans) {
        cout << it << endl;
    }

    return 0;
}