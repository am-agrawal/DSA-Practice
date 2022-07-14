#include "../DataStructureClass.hpp"
#include <vector>
#include <queue>
#include <map>

vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> mpp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;

        mpp[line] = node -> val;

        if(node -> left) {
            q.push({node -> left, line-1});
        }
        if(node -> right) {
            q.push({node -> right, line+1});
        }
    }

    for(auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
}