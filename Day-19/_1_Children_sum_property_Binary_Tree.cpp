#include "../DataStructureClass.hpp"

// Here children sum property means
// Each node should hold value which is sum of left and right children
// we are given a binary tree and we have to increase values in such order that it results in children sum property

void childrenSum(TreeNode* root) {
    if(root == NULL) return;
    int child = 0;
    if(root -> left) child += root -> left -> val;
    if(root -> right) child += root -> right -> val;

    if(child >= root -> val) root -> val = child;

    else {
        if(root -> left) root -> left -> val = root -> val;
        else if(root -> right) root -> right -> val = root -> val;
    }

    childrenSum(root -> left);
    childrenSum(root -> right);

    int total = 0;
    if(root -> left) total += root -> left -> val;
    if(root -> right) total += root -> right -> val;
    if(root -> left || root -> right) root -> val = total;
}