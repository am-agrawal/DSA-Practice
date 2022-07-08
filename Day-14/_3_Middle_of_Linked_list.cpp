#include "../DataStructureClass.hpp"

Node* middleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

int main() {
    Node* node = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6))))));
    Node* middle = middleNode(node);
    cout << middle -> val << endl;

    return 0;
}