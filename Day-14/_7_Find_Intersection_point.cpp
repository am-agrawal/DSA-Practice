#include "../DataStructureClass.hpp"

// Node* intersectionPoint(Node* h1, Node* h2) {
//     int l1 = 0, l2 = 0;
//     Node* n1 = h1;
//     Node* n2 = h2;
    
//     while(n1 != NULL) {
//         n1 = n1 -> next;
//         l1++;
//     }
//     while(n2 != NULL) {
//         n2 = n2 -> next;
//         l2++;
//     }
//     if(l2 > l1) {
//         swap(h1, h2);
//         swap(l1, l2);
//     }
//     int t = l1 - l2;

//     for(int i = 0; i < t; i++) {
//         h1 = h1 -> next;
//     }

//     while(h1 != h2) {
//         h1 = h1 -> next;
//         h2 = h2 -> next;
//     }

//     return h1;
// }

Node* intersectionPoint(Node* h1, Node* h2) {
    if(h1 == NULL || h2 == NULL) return NULL;

    Node* a = h1;
    Node* b = h2;

    while(a != b) {
        a = (a == NULL) ? h2 : a -> next;
        b = (b == NULL) ? h1 : b -> next;
    }

    return a;
}

int main() {
    Node* h1 = new Node(1, new Node(2, new Node(8, new Node(7, new Node(6)))));
    Node* h2 = new Node(2, new Node(8, new Node(1, new Node(3, (h1 -> next -> next)))));

    Node* ans = intersectionPoint(h1, h2);

    cout << ans -> val << endl;

    return 0;
}