#include "../DataStructureClass.hpp"

// Node to be deleted will not be the last node of List
void deleteNode(Node* node) {
    swap(node -> val, node -> next -> val);
    Node* del = node -> next;
    node -> next = del -> next;
    delete del;
}

int main() {
    Node* node = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    Node* delNode = node -> next -> next;
    printList(node);
    deleteNode(delNode);

    printList(node);

    return 0;
}