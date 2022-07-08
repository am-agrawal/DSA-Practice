#include "../DataStructureClass.hpp"

Node* cycleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    do {
        slow = slow -> next;
        fast = fast -> next -> next;
    } while (slow != fast);

    fast = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}

bool hasCycle(Node* head) {
    if(head == NULL || head -> next == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while(fast -> next != NULL && fast -> next -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;

        if(fast == slow) {
            return true;
        }
    }

    return false;
}

int main() {
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4))));
    head -> next -> next -> next = head -> next -> next;

    // Node* cycleAt = cycleNode(head);

    // cout << cycleAt -> val << endl;

    cout << hasCycle(head) << endl;

    return 0;
}