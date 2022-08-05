#include "../DataStructureClass.hpp"
#include <string>
#include <sstream>
#include <queue>


string serialize(TreeNode* root) {
    if(root==NULL) return "";
    
    string s = "";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* atNode = q.front();
        q.pop();
        if(atNode==NULL) s.append("#,");
        else s.append(to_string(atNode->val)+',');
        if(atNode!=NULL){
            q.push(atNode->left);
            q.push(atNode->right);
        }
    }
    return s;
}


TreeNode* deserialize(string data) {
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        
        getline(s,str,',');
        if(str=="#") node->left = NULL;
        else{
            TreeNode* treeLeft = new TreeNode(stoi(str));
            node->left = treeLeft;
            q.push(treeLeft);
        }
        
        getline(s,str,',');
        if(str=="#") node->right = NULL;
        else{
            TreeNode* treeRight = new TreeNode(stoi(str));
            node->right = treeRight;
            q.push(treeRight);
        }
    }
    return root;
}