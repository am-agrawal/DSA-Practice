#include "../DataStructureClass.hpp"

Node* rotate(Node* head, int k) {
    if(!head || !head -> next || k == 0) return head;

    int len = 1;
    Node* curr = head;
    while (curr -> next != NULL && ++len) {
        curr = curr -> next;
    }

    curr -> next = head;
    k = k % len;
    k = len - k;
    while(k--) curr = curr -> next;

    head = curr -> next;
    curr -> next = NULL;
    
    return head;
}

int main() {
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    printList(head);
    head = rotate(head, 6);
    printList(head);

    return 0;
}