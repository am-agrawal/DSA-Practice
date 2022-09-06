// Here we have a matrix of 0s and 1s
// And we need to find the area of a submatrix of all 1s

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxArea(vector<int>& heights) {
    int n = heights.size();
    int res = 0;
    stack<int> st;

    for(int i = 0; i <= n; i++) {
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;

            res = max(res, width * height);
        }
        st.push(i);
    }

    return res;
}

int maxArea1s(vector<vector<int>>& mat) {
  int n = mat.size(), m = mat[0].size();
  int maxi = INT_MIN;
  vector<int> height(n, 0);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(mat[i][j] == 1) height[j]++;
      else height[j] = 0;
    }
    int area = maxArea(height);
    maxi = max(maxi, area);
  }

  return maxi;
}

int main() {
  vector<vector<int>> mat = {
                              {1, 0, 0, 0},
                              {0, 1, 1, 1},
                              {1, 1, 1, 1},
                              {1, 0, 1, 0}
  };

  cout << maxArea1s(mat) << endl;

  return 0;
}