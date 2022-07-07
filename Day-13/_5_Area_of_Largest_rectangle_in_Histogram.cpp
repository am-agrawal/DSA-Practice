#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// int maxArea(vector<int>& height) {
//     stack<int> st;
//     int n = height.size();
//     vector<int> left(n), right(n);
//     int res = 0;

//     for(int i = 0; i < n; i++) {
//         while(!st.empty() && height[st.top()] >= height[i]) {
//             st.pop();
//         }

//         left[i] = (st.empty()) ? 0 : st.top() + 1;

//         st.push(i);
//     }

//     while(!st.empty()) { st.pop(); }

//     for(int i = n-1; i >= 0; i--) {
//         while(!st.empty() && height[st.top()] >= height[i]) {
//             st.pop();
//         }
        
//         right[i] = (st.empty()) ? n-1 : st.top() - 1;

//         st.push(i);
//     }

//     for(int i = 0; i < n; i++) {
//         res = max(res, height[i] * (right[i] - left[i] + 1));
//     }

//     return res;
// }

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


int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
    cout << maxArea(heights) << endl;

    return 0;
}