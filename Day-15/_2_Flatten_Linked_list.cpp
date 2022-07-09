#include "../DataStructureClass.hpp"

Node2* mergeTwoLists(Node2* a, Node2* b) {
    Node2* temp = new Node2(-1);
    Node2* res = temp;

    while (a != NULL && b != NULL) {
        if(a -> val < b -> val) {
            temp -> bottom = a;
            temp = temp -> bottom;
            a = a -> bottom;
        } else {
            temp -> bottom = b;
            temp = temp -> bottom;
            b = b -> bottom;
        }
    }

    if(a != NULL) {
        temp -> bottom = a;
    }
    if(a != NULL) {
        temp -> bottom = b;
    }

    return res -> bottom;
}

Node2* flatten(Node2* root) {
    if(root == NULL || root -> next) {
        return root;
    }

    root -> next = flatten(root -> next);

    root = mergeTwoLists(root, root -> next);

    return root;
}