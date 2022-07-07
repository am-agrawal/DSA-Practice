#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;

    for(int i = (2*n-1); i >= 0; i--) {
        while(!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        if(st.empty()) {
            res[i % n] = -1;
        } else {
            res[i % n] = st.top();
        }
        st.push(nums[i % n]);
    }

    return res;
}

int main() {
    vector<int> nums = {2, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    vector<int> res = nextGreater(nums);

    for(auto i : res) {
        cout << i << " ";
    }


    return 0;
}