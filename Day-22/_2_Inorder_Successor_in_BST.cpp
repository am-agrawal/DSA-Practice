#include "../DataStructureClass.hpp"

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = NULL;

    TreeNode* cur = root;
    while (cur) {
        if(cur -> val > p -> val) {
            successor = cur;
            cur = cur -> left;
        } else {
            cur = cur -> right;
        }
    }

    return successor;
}