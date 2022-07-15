#include "../DataStructureClass.hpp"
#include <unordered_map>
#include <queue>

void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();

        if(node -> left) { parent_track[node -> left] = node; queue.push(node -> left); }
        if(node -> right) { parent_track[node -> right] = node; queue.push(node -> right); }
    }
}

int minTimeToBurn(TreeNode* root, TreeNode* target) {
    unordered_map<TreeNode*, TreeNode*> parent_track;
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> queue;
    int time = 0;

    markParent(root, parent_track);

    queue.push(target);

    while(!queue.empty()) {
        int size = queue.size();
        time++;

        for(int i = 0; i < size; i++) {
            TreeNode* node = queue.front(); queue.pop();

            if(node -> left && !visited[node -> left]) {
                visited[node -> left] = true;
                queue.push(node -> left);
            }
            if(node -> right && !visited[node -> right]) {
                visited[node -> right] = true;
                queue.push(node -> right);
            }
            if(parent_track[node] && !visited[parent_track[node]]) {
                visited[parent_track[node]] = true;
                queue.push(parent_track[node]);
            }
        }
    }

    return time;
}