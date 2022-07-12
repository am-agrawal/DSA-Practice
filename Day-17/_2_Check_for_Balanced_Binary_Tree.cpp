#include "../DataStructureClass.hpp"

int dfs(TreeNode* root) {
    if(root == NULL) return 0;

    int left = dfs(root -> left);
    if(left == -1) return -1;

    int right = dfs(root -> right);
    if(right == -1) return -1;

    if(abs(left - right) > 1) return -1;

    return max(left, right) + 1;
}

bool isHeightBalanced(TreeNode* root) {
    return (dfs(root -> left) != -1) ? true : false;
}