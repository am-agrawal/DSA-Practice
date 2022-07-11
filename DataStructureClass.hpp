#include <iostream>
using namespace std;

// Linked List Data-Structure
class Node {
public:
    int val;
    Node* next;

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
    Node(int _val) {
        val = _val;
        next = NULL;
    }
};

// To print the List
void printList(Node* head) {
    Node* node = head;
    while(node != NULL) {
        cout << node -> val << " -> ";
        node = node -> next;
    }
    cout << "NULL" << endl;
}

// Linked list with 2-pointers - next & bottom
class Node2 {
public:
    int val;
    Node2* next;
    Node2* bottom;

    Node2(int _val) {
        val = _val;
        next = bottom = NULL;
    }

    Node2(int _val, Node2* _next) {
        val = _val;
        next = _next;
        bottom = NULL;
    }

    Node2(int _val, Node2* _next, Node2* _bottom) {
        val = _val;
        next = _next;
        bottom = _bottom;
    }
};


// For printing Linked List of 2 pointers

void printListNext(Node2* head) {
    while (head != NULL) {
        cout << head -> val << " -> ";
        head = head -> next;
    }
    cout << "NULL";
}

void printListBottom(Node2* head) {
    while (head != NULL) {
        cout << head -> val << " -> ";
        head = head -> bottom;
    }
    cout << "NULL";
}


// Linked List with Next and Random pointers
class NodeWithRandom {
public:
    int val;
    NodeWithRandom* next;
    NodeWithRandom* random;

    NodeWithRandom(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

    NodeWithRandom(int _val, NodeWithRandom* _next) {
        val = _val;
        next = _next;
        random = NULL;
    }

    NodeWithRandom(int _val, NodeWithRandom* _next, NodeWithRandom* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

void printListOfRandomPtr(NodeWithRandom* head) {
    NodeWithRandom* temp = head;
    while(temp != NULL) {
        cout << temp -> val << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" <<  endl;
    temp = head;
    while(temp != NULL) {
        cout << temp -> val << " -> ";
        if(temp -> random == NULL) {
            cout << "NULL" << endl;
        } else {
            cout << temp -> random -> val << endl;
        }
        temp = temp -> next;
    }
}


// Binay Tree
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _val) {
        val = _val;
        left = right = NULL;
    }

    TreeNode(int _val, TreeNode* _left, TreeNode* _right) {
        val = _val;
        left = _left;
        right = _right;
    }

};

