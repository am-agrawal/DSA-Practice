#include "../DataStructureClass.hpp"
using namespace std;

Node* reverseKGroup(Node* head, int k) {
    if(head == NULL || k == 1) return head;

    Node *dummy = new Node(-1, head);
    
    Node *curr = dummy, *nex = dummy, *pre = dummy;
    int count = 0;

    while(curr -> next != NULL) {
        curr = curr -> next;
        count++;
    }

    while(count >= k) {
        curr = pre -> next;
        nex = curr -> next;
        for(int i = 1; i < k; i++) {
            curr -> next = nex -> next;
            nex -> next = pre -> next;
            pre -> next = nex;
            nex = curr -> next;
        }
        pre = curr;
        count -= k;
    }

    return dummy -> next;
}


int main() {
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6, new Node(7, new Node(8))))))));
    printList(head);

    head = reverseKGroup(head, 3);
    printList(head);

    return 0;
}