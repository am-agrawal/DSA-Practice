#include "../DataStructureClass.hpp"

/*
* Here in this problem, we have a given binary tree,
* and we have to find its maximum possible diameter
* Example =>              -10
*                        /   \
*                       9    20
*                           /   \
*                         15     7
* 
* Here the maximum path sum is 42
* As => 15 -> 20 -> 7
*/

int dfs(TreeNode* root, int ans) {
    if(root == NULL) return 0;

    int left = max(0, dfs(root -> left, ans));
    int right = max(0, dfs(root -> right, ans));

    ans = max(ans, (left + right + root -> val));

    return max(left, right) + root -> val;
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    dfs(root, ans);
    return ans;
}