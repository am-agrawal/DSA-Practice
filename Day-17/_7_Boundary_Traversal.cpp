#include "../DataStructureClass.hpp"
#include <vector>

bool isLeaf(TreeNode* node) {
    return (node -> left == NULL && node -> right == NULL) ? true : false;
}

void addLeftBoundary(TreeNode* root, vector<int>& ans) {
    while(root != NULL) {
        ans.push_back(root -> val);
        if(root -> left != NULL) {
            root = root -> left;
        } else {
            root = root -> right;
        }
    }
}

void addRightBoundary(TreeNode* root, vector<int>& ans) {
    while(root != NULL) {
        ans.push_back(root -> val);
        if(root -> right != NULL) {
            root = root -> right;
        } else {
            root = root -> left;
        }
    }
}

void addLeaves(TreeNode* root, vector<int>& ans) {
    if(isLeaf(root)) {
        ans.push_back(root -> val);
        return;
    }

    addLeaves(root -> left, ans);
    addLeaves(root -> right, ans);
}

vector<int> printBoundary(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    if(!isLeaf(root)) ans.push_back(root -> val);

    addLeftBoundary(root -> left, ans);

    addLeaves(root, ans);
    
    vector<int> t;
    addRightBoundary(root -> right, t);
    reverse(t.begin(), t.end());
    ans.insert(ans.end(), t.begin(), t.end());

    return ans;
}