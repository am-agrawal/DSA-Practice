#include "../DataStructureClass.hpp"

/*
* Here in this problem, we have a given binary tree,
* and we have to find its maximum possible diameter
* Example =>               1
*                        /   \
*                       2     3
*                           /   \
*                          4     6
*                         /       \
*                        5         7
*                       /           \
*                      9             8
* 
* Here the maximum possible diameter is 6
* As => 9 -> 5 -> 4 -> 3 -> 6 -> 7 -> 8
*/

int dfs(TreeNode* root, int &ans) {
    if(root == NULL) return 0;

    int left = dfs(root -> left, ans);
    int right = dfs(root -> right, ans);

    ans = max(ans, left + right);

    return max(left, right) + 1;
}

int diameter(TreeNode* root) {
    int ans = 0;
    if(root == NULL) return ans;
    dfs(root, ans);

    return ans;
}