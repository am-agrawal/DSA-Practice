#include "../DataStructureClass.hpp"

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;

    if(p -> val < root -> val && q -> val < root -> val) return LCA(root -> left, p, q);
    else if(p -> val > root -> val && q -> val > root -> val) return LCA(root -> right, p, q);

    return root;
}