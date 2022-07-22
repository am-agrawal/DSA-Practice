#include "../DataStructureClass.hpp"

class NodeValue {
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this -> maxNode = maxNode;
        this -> minNode = minNode;
        this -> maxSize = maxSize;
    }

};

NodeValue largestBSTSubtreeHelper(TreeNode* root) {
    if(root == NULL) return NodeValue(INT_MAX, INT_MIN, 0);

    auto left = largestBSTSubtreeHelper(root -> left);
    auto right = largestBSTSubtreeHelper(root -> right);

    if(left.maxNode < root -> val && root -> val < right.minNode) {
        return NodeValue(min(root -> val, left.minNode), max(root -> val, right.maxNode), left.maxSize + right.maxSize);
    }

    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBSTSubtree(TreeNode* root) {
    return largestBSTSubtreeHelper(root).maxSize;
}