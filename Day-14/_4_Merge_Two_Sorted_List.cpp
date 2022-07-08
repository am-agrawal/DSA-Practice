#include "../DataStructureClass.hpp"

// Using Extra Space, not In-place
// Node* mergeLists(Node* head1, Node* head2) {
//     Node* ans = new Node(-1);
//     Node* res = ans;
//     while(head1 != NULL && head2 != NULL) {
//         if(head1 -> val < head2 -> val) {
//             res -> next = new Node(head1 -> val);
//             head1 = head1 -> next;
//         } else {
//             res -> next = new Node(head2 -> val);
//             head2 = head2 -> next;
//         }
//         res = res -> next;
//     }
//     while(head1 != NULL) {
//         res -> next = new Node(head1 -> val);
//         head1 = head1 -> next;
//         res = res -> next;
//     }
//     while(head2 != NULL) {
//         res -> next = new Node(head2 -> val);
//         head2 = head2 -> next;
//         res = res -> next;
//     }

//     return ans -> next;
// }

Node* mergeLists(Node* head1, Node* head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    Node* ans = new Node(-1);
    Node* res = ans;

    while(head1 != NULL && head2 != NULL) {
        if(head1 -> val < head2 -> val) {
            res -> next = head1;
            head1 = head1 -> next;
        } else {
            res -> next = head2;
            head2 = head2 -> next;
        }

        res = res -> next;
    }

    if(head1 != NULL) {
        res -> next = head1;
    } else {
        res -> next = head2;
    }

    return ans -> next;
}

int main() {
    Node* h1 = new Node(1, new Node(3, new Node(5)));
    Node* h2 = new Node(2, new Node(3, new Node(4)));
    Node* h = mergeLists(h1, h2);

    printList(h);

    return 0;
}