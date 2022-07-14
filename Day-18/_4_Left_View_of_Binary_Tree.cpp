#include "../DataStructureClass.hpp"
#include <vector>

void traverse(TreeNode* root, int level, vector<int>& ans) {
    if(root == NULL) return;

    if(level == ans.size()) {
        ans.push_back(root -> val);
    }

    traverse(root -> left, level + 1, ans);
    traverse(root -> right, level + 1, ans);
}

vector<int> leftView(TreeNode* root) {
    vector<int> ans;
    traverse(root, 0, ans);

    return ans;
}