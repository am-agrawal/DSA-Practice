#include "../DataStructureClass.hpp"

TreeNode* LCA(TreeNode* root, TreeNode* A, TreeNode* B) {
    if (root == NULL || root == A || root == B) return root;

    TreeNode* left = LCA(root -> left, A, B);
    TreeNode* right = LCA(root -> right, A, B);

    if(left == NULL) { return right; }
    else if(right == NULL) { return left; }
    else { return root; }

    return NULL;
}