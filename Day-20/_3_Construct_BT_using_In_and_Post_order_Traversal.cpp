#include "../DataStructureClass.hpp"
#include <vector>
#include <unordered_map>

TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inMap) {
    if(postStart > postEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);

    int inRoot = inMap[root -> val];
    int numLeft = inRoot - inStart;

    root -> left = buildTree(inorder, inStart, inRoot-1, postorder, postStart, postStart+numLeft-1, inMap);
    root -> right = buildTree(inorder, inRoot+1, inEnd, postorder, postStart+numLeft, postEnd-1, inMap);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;

    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    TreeNode* root = buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);

    return root;
}