#include "../DataStructureClass.hpp"

bool search(TreeNode* root, int target) {
    while(root) {
        if(root -> val == target) return true;

        if(root -> val < target) root = root -> right;
        else root = root -> left;
    }
    return false;
}

TreeNode* search2(TreeNode* root, int target) {
    while(root -> val != target && root != NULL) {
        root = (root -> val < target) ? root -> right : root -> left;
    }
    return root;
}