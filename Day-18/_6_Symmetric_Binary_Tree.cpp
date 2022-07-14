#include "../DataStructureClass.hpp"


bool traverse(TreeNode* l, TreeNode* r) {
    if(l == NULL || r == NULL) {
        return (l == r);
    }
    if(l -> val != r -> val) return false;

    bool ans = true;
    ans &= traverse(l -> left, r -> right);
    ans &= traverse(l -> right, r -> left);

    return ans;
}

bool isSymmetric(TreeNode* root) {
    return (root == NULL) ? true : traverse(root -> left, root -> right);
}