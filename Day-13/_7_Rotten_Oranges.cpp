#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int timeToRotten(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size(), days = 0, total = 0, cnt = 0;
    queue<pair<int, int>> rotten;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] != 0) total++;
            if(grid[i][j] == 2) rotten.push({i, j});
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!rotten.empty()) {
        int k = rotten.size();
        cnt += k;
        while(k--) {
            int x = rotten.front().first, y = rotten.front().second;
            rotten.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;

                grid[nx][ny] = 2;

                rotten.push({nx, ny});
            }
        }
        if(!rotten.empty()) days++;
    }

    return (cnt == total) ? days : -1;
}

int main() {
    vector<vector<int>> grid = {{2, 0, 0, 2},
                                {1, 0, 0, 1},
                                {1, 1, 0, 1},
                                {0, 0, 0, 1}};
    cout << timeToRotten(grid) << endl;

    return 0;
}