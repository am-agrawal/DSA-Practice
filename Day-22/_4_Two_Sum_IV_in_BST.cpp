#include "../DataStructureClass.hpp"
#include <stack>

// =======================================================================

TreeNode* search(TreeNode* root, int target) {
    while(root -> val != target && root != NULL) {
        root = (root -> val < target) ? root -> right : root -> left;
    }
    return root;
}

int twoSum(TreeNode* root, int k) {
    if(root == NULL) return 0;

    int cnt = 0;
    TreeNode* searchedNode = search(root, k - root->val);
    if(searchedNode != root) cnt++;

    cnt += twoSum(root -> left, k);
    cnt += twoSum(root -> right, k);

    return cnt;
}

// ========================================================================

class BSTIterator {
    stack<TreeNode*> myStack;
    // reverse = true => before
    // reverse = false => after
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode -> right);
        else pushAll(tmpNode -> left);

        return tmpNode -> val;
    }

private:
    void pushAll(TreeNode* node) {
        for(; node != NULL;) {
            myStack.push(node);
            if(reverse) {
                node = node -> right;
            } else {
                node = node -> left;
            }
        }
    }
};

bool findTarget(TreeNode* root, int k) {
    if(!root) return false;

    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();

    while(i < j) {
        if(i + j == k) return true;
        else if(i + j < k) i = l.next();
        else j = r.next();
    }

    return false;
}