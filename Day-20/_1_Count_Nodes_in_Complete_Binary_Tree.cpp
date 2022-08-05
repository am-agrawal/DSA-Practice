#include "../DataStructureClass.hpp"

int leftHeight(TreeNode* root) {
    int height = 1;
    while(root) {
        height++;
        root = root -> left;
    }
    return height;
}
int rightHeight(TreeNode* root) {
    int height = 1;
    while(root) {
        height++;
        root = root -> right;
    }
    return height;
}

int countNodes(TreeNode *node) {
    if(!node) return 0;

    int lh = leftHeight(node -> left);
    int rh = rightHeight(node -> right);

    if(lh == rh) return (1<<lh) - 1;

    return (1 + countNodes(node -> left) + countNodes(node -> right));
}