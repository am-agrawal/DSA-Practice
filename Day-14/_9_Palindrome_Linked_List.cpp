#include "../DataStructureClass.hpp"

Node* reverseList(Node* head) {
    Node* pre = NULL;
    Node* next = NULL;

    while (head != NULL) {
        next = head -> next;
        head -> next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

bool isPalindrome(Node* head) {
    if(head == NULL || head-> next == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    while(fast -> next != NULL && fast -> next -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    slow -> next = reverseList(slow -> next);

    slow = slow -> next;

    while(slow != NULL) {
        if(head -> val != slow -> val) {
            return false;
        }
        head = head -> next;
        slow = slow -> next;
    }

    return true;
}

int main() {
    Node* node = new Node(1, new Node(2, new Node(3, new Node(4, new Node(3, new Node(2, new Node(1)))))));
    cout << isPalindrome(node) << endl;

    return 0;
}