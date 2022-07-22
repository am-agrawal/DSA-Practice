#include "../DataStructureClass.hpp"
#include <vector>

TreeNode* bstFromPreorder(vector<int>& A, int& i, int bound) {
    if(i == A.size() || A[i] > bound) return NULL;

    TreeNode* root = new TreeNode(A[i++]);
    root -> left = bstFromPreorder(A, i, root -> val);
    root -> right = bstFromPreorder(A, i, bound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& A) {
    int i = 0;
    return bstFromPreorder(A, i, INT_MAX);
}