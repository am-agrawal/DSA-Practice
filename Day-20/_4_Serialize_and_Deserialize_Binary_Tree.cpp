#include "../DataStructureClass.hpp"
#include <string>
#include <sstream>
#include <queue>

string serialize(TreeNode* root) {
    string ans = "";
    if(!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curNode = q.front();
        q.pop();
        if(curNode == NULL) ans.append("#,");
        else ans.append(to_string(curNode -> val)+',');
        if(!curNode) {
            q.push(curNode -> left);
            q.push(curNode -> right);
        }
    }

    return ans;
}

TreeNode* deserialize(string data) {
    if(data.size() == 0) return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');

    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#") {
            node -> left = NULL;
        }
        else {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node -> left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str == "#") {
            node -> right = NULL;
        }
        else {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node -> right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}