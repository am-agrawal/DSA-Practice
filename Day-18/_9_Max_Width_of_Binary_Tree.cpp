#include "../DataStructureClass.hpp"
#include <queue>

int maxWidth(TreeNode* root) {
    int ans = 0;
    if(root == NULL) return ans;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        int size = q.size();
        int mmin = q.front().second;
        int first, last;
        
        for (int i = 0; i < size; i++) {
            int curr_id = q.front().second - mmin;
            auto node = q.front().first;
            q.pop();

            if(i == 0) first = curr_id;
            if(i == size - 1) last = curr_id;

            if(node -> left) {
                q.push({node -> left, curr_id * 2 + 1});
            }
            if(node -> right) {
                q.push({node -> right, curr_id * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }

    return ans;
}