#include "../DataStructureClass.hpp"
#include <vector>

bool recursion(TreeNode* root, int x, vector<int>& ans) {
    if(root == NULL) return false;

    ans.push_back(root -> val);

    if(root -> val == x) return true;

    if (recursion(root -> left, x, ans)) {
        return true;
    }
    
    if (recursion(root -> right, x, ans)) {
        return true;
    }

    ans.pop_back();

    return false;
}

vector<int> rootToNode(TreeNode* root, int x) {
    vector<int> ans;
    if (root != NULL) { recursion(root, x, ans); }

    return ans;
}