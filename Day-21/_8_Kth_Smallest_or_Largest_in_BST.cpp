#include "../DataStructureClass.hpp"
#include <vector>

int morrisInorder(TreeNode* root, int k) {
    TreeNode* cur = root;
    int cnt = 0;

    while(cur != NULL) {
        if(cur -> left == NULL) {
            cnt++;
            if(cnt == k) return cur -> val;
            cur = cur -> right;
        } else {
            TreeNode* prev = cur -> left;
            while(prev -> right != cur -> right != NULL) {
                prev = prev -> right;
            }
            if(prev -> right == cur) {
                cnt++;
                if(cnt == k) return cur -> val;
                prev -> right = NULL;
                cur = cur -> right;
            } else {
                prev -> right = cur;
                cur = cur -> left;
            }
        }
    }

    return -1;
}