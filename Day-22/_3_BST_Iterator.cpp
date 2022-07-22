#include "../DataStructureClass.hpp"
#include <stack>

class BSTIterator {
    stack<TreeNode*> st;
public:
    void putAllLeft(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node -> left;
        }
        // for(; node != NULL; st.push(node), node = node -> left);
    }

    BSTIterator(TreeNode* root) {
        putAllLeft(root);
    }

    bool hasNext() {
        return (!st.empty());
    }

    int next() {
        TreeNode* node = st.top(); st.pop();

        if(node -> right) {
            putAllLeft(node -> right);
        }

        return node -> val;
    }
};