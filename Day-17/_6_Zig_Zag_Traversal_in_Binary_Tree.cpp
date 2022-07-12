#include "../DataStructureClass.hpp"
#include <vector>
#include <queue>
#include <algorithm>

// This problem can easily solved using Level order traversal
// but we have to keep a flag (bool) and change it on every level
// and according to this flag we will rotate a level then insert it into the answer

vector<vector<int>> zigZag(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool rtl = false;
    vector<vector<int>> ans;

    while(!q.empty()) {
        int k = q.size();
        vector<int> t;
        while(k--) {
            t.push_back(q.front() -> val);
            if(q.front() -> left != NULL) q.push(q.front() -> left);
            if(q.front() -> right != NULL) q.push(q.front() -> right);
            q.pop();
        }
        if(rtl) {
            reverse(t.begin(), t.end());
        }
        rtl = !rtl;
        ans.push_back(t);
    }

    return ans;
}