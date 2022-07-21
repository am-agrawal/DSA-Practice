#include "../DataStructureClass.hpp"

TreeNode* insert(TreeNode* root, int _val) {
    if(!root) return new TreeNode(_val);
    
    TreeNode* node = root;
    TreeNode* prev;

    while(!node) {
        prev = node;

        if(node -> val < _val) node = node -> right;
        else node = node -> left;
    }
    if(prev -> val < _val) {
        prev -> right = new TreeNode(_val);
    } else {
        prev -> left = new TreeNode(_val);
    }

    return root;
}