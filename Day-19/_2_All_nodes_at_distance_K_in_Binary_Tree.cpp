#include "../DataStructureClass.hpp"
#include <unordered_map>
#include <queue>
#include <vector>

void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, TreeNode* target) {
    queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        if(node -> left) { parent_track[node -> left] = node; queue.push(node -> left); }
        if(node -> right) { parent_track[node -> right] = node; queue.push(node -> right); }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track, target);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> queue;
    queue.push(target);
    visited[target] = true;
    int curr_level = -1;

    while(!queue.empty()) {
        int size = queue.size();
        curr_level++;

        if(curr_level == k) break;

        for(int i = 0; i < size; ++i) {
            TreeNode* node = queue.front();
            queue.pop();

            if(node -> left && !visited[node -> left]) {
                queue.push(node -> left);
                visited[node -> left] = true;
            }
            if(node -> right && !visited[node -> right]) {
                queue.push(node -> right);
                visited[node -> right] = true;
            }
            if(parent_track[node] && !visited[parent_track[node]]) {
                queue.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }

    vector<int> res;

    while(!queue.empty()) {
        res.push_back(queue.front() -> val);
        queue.pop();
    }

    return res;
}