#include "../DataStructureClass.hpp"

// Time => Time - O(2n) & Space => O(1)
// Node* removeNth(Node* head, int n) {
//     int cnt = 0;
//     Node* node = head;
//     while (node != NULL) {
//         cnt++;
//         node = node -> next;
//     }
//     n = cnt - n;
//     if(n == 0) {
//         Node* node = head -> next;
//         delete head;
//         return node;
//     }
//     cnt = 1;
//     node = head;
//     while (node != NULL && cnt != n) {
//         node = node -> next;
//         cnt++;
//     }
//     Node* del = node -> next;
//     node -> next = node -> next -> next;
//     delete del;

//     return head;
// }

Node* removeNth(Node* head, int n) {
    Node* start = new Node(0, head);

    Node* slow = start;
    Node* fast = start;

    for(int i = 0; i < n; i++) { fast = fast -> next; }

    while(fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next;
    }
    Node* del = slow -> next;
    slow -> next = slow -> next -> next;
    delete del;

    return start -> next;
}

int main() {
    Node* node = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    printList(node);
    cout << "---------" << endl;
    node = removeNth(node, 2);
    printList(node);

    return 0;
}