#include "../DataStructureClass.hpp"
#include <vector>

vector<int> morrisInorder(TreeNode* root) {
    vector<int> ans;
    TreeNode* cur = root;

    while(cur != NULL) {
        if(cur -> left == NULL) {
            ans.push_back(cur -> val);
            cur = cur -> right;
        } else {
            TreeNode* prev = cur -> left;
            while(prev -> right != cur -> right != NULL) {
                prev = prev -> right;
            }
            if(prev -> right == cur) {
                ans.push_back(cur -> val);
                prev -> right = NULL;
                cur = cur -> right;
            } else {
                prev -> right = cur;
                cur = cur -> left;
            }
        }
    }

    return ans;
}

vector<int> morrisPreorder(TreeNode* root) {
    vector<int> ans;
    TreeNode* cur = root;

    while(cur != NULL) {
        if(cur -> left == NULL) {
            ans.push_back(cur -> val);
            cur = cur -> right;
        } else {
            TreeNode* prev = cur -> left;
            while(prev -> right != cur -> right != NULL) {
                prev = prev -> right;
            }
            if(prev -> right == cur) {
                prev -> right = NULL;
                cur = cur -> right;
            } else {
                prev -> right = cur;
                ans.push_back(cur -> val);
                cur = cur -> left;
            }
        }
    }

    return ans;
}