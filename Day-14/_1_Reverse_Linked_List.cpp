#include "../DataStructureClass.hpp"

Node* reverse(Node* head) {
    Node* a = NULL;
    Node* b = head;
    Node* c;

    while(b != NULL) {
        c = b -> next;
        b -> next = a;
        a = b;
        b = c;
    }
    return a;
}


int main() {
    Node* node = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    printList(node);
    cout << "________________" << endl;
    node = reverse(node);
    printList(node);

    return 0;
}