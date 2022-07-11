#include "../DataStructureClass.hpp"
#include <vector>
#include <queue>
#include <stack>

// Inorder => Left - Root - Roght
void inorderRecursive(TreeNode* root, vector<int>& ans) {
    if(root == NULL) return;
    inorderRecursive(root -> left, ans);
    ans.push_back(root -> val);
    inorderRecursive(root -> right, ans);
}

vector<int> inorderIterative(TreeNode* root) {
    vector<int> ans;

    stack<TreeNode*> st;
    TreeNode* node = root;

    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node -> left;
        } else {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            ans.push_back(node -> val);
            node = node -> right;
        }
    }

    return ans;
}


// Preorder => Left - Right - Root
void preorderRecursive(TreeNode* root, vector<int>& ans) {
    if(root == NULL) return;
    preorderRecursive(root -> left, ans);
    preorderRecursive(root -> right, ans);
    ans.push_back(root -> val);
}

vector<int> preorderIterative(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        ans.push_back(curr -> val);

        if(curr -> right != NULL) st.push(curr -> right);
        if(curr -> left != NULL) st.push(curr -> left);
    }

    return ans;
}


// Postorder => Root - Left - Right
void postorderRecursive(TreeNode* root, vector<int>& ans) {
    if(root == NULL) return;
    ans.push_back(root -> val);
    postorderRecursive(root -> left, ans);
    postorderRecursive(root -> right, ans);
}

vector<int> postorderIterative(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> st1, st2;
    st1.push(root);

    while(!st1.empty()) {
        TreeNode* curr = st1.top();
        st1.pop();
        st2.push(curr);
        if(curr -> left != NULL) st1.push(curr -> left);
        if(curr -> right != NULL) st1.push(curr -> right);
    }

    while(!st2.empty()) {
        ans.push_back(st2.top() -> val);
        st2.pop();
    }

    return ans;
}

vector<int> postOrder(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr != NULL || !st.empty()) {
        if(curr != NULL) {
            st.push(curr);
            curr = curr -> left;
        } else {
            TreeNode* temp = st.top() -> right;

            if(temp == NULL) {
                temp = st.top();
                st.pop();
                ans.push_back(temp -> val);
                while(!st.empty() && temp == st.top() -> right) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp -> val);
                }
            } else {
                curr = temp;
            }
        }
    }

    return ans;
}

// It works in a combined fashion
void prePostIn(TreeNode* root, vector<int>& pre, vector<int>& post, vector<int>& in) {
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            pre.push_back(it.first -> val);
            it.second++;
            st.push(it);

            if(it.first -> left != NULL) {
                st.push({it.first -> left, 1});
            }
        }
        else if(it.second == 2) {
            post.push_back(it.first -> val);
            it.second++;
            st.push(it);

            if(it.first -> right != NULL) {
                st.push({it.first -> right, 1});
            }
        }
        else {
            post.push_back(it.first -> val);
        }
    }
}


// Level order Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == NULL) return;
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int k = q.size();
        vector<int> t;

        while(k--) {
            t.push_back(q.front() -> val);
            q.pop();
            if(q.front() -> left != NULL) q.push(root -> left);
            if(q.front() -> right != NULL) q.push(root -> right);
        }
        ans.push_back(t);
    }

    return ans;
}