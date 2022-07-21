#include "../DataStructureClass.hpp"
#include <stack>

// Initial - TreeNode* prev = NULL;
// Recursive Approach
// Time - O(n) & Space - O(n)
void flattenBT(TreeNode* root, TreeNode* prev) {
    if(!root) return;

    flattenBT(root -> right, prev);
    flattenBT(root -> left, prev);

    root -> right = prev;
    root -> left = NULL;
    prev = root;
}

// Iterative Approach
// Time - O(n) & Space - O(n)
void flatten(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* cur;

    st.push(root);

    while(!st.empty()) {
        cur = st.top(); st.pop();

        if(cur -> right) st.push(cur -> right);

        if(cur -> left) st.push(cur -> left);

        if(!st.empty()) cur -> right = st.top();

        cur -> left = NULL;
    }
}

// Using Morris Traversal technique
// Time - O(n) & Space - O(1)
void flat(TreeNode* root) {
    TreeNode* cur = root;

    while(cur != NULL) {
        if(cur -> left != NULL) {
            TreeNode* prev = cur -> left;

            while(prev -> right != NULL) prev = prev -> right;

            prev -> right = cur -> left;
            cur -> right = cur -> left;
        }
        cur = cur -> right;
    }
}