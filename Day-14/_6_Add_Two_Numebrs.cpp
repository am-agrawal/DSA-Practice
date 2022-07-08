#include "../DataStructureClass.hpp"

// Node* addNumbers(Node* num1, Node* num2) {
//     Node* ans = new Node(-1);
//     Node* res = ans;
//     int carry = 0;

//     while(num1 != NULL && num2 != NULL) {
//         int sum = num1 -> val + num2 -> val + carry;
//         res -> next = new Node(sum % 10);
//         res = res -> next;
//         num1 = num1 -> next;
//         num2 = num2 -> next;
//         carry = sum / 10;
//     }
//     while(num1 != NULL) {
//         int sum = num1 -> val + carry;
//         res -> next = new Node(sum % 10);
//         res = res -> next;
//         num1 = num1 -> next;
//         carry = sum / 10;
//     }
//     while(num2 != NULL) {
//         int sum = num2 -> val + carry;
//         res -> next = new Node(sum % 10);
//         res = res -> next;
//         num2 = num2 -> next;
//         carry = sum / 10;
//     }
//     if(carry > 0) {
//         res -> next = new Node(carry);
//     }

//     return ans -> next;
// }

Node* addNumbers(Node* num1, Node* num2) {
    Node* ans = new Node(-1);
    Node* res = ans;
    int carry = 0;

    while(num1 != NULL || num2 != NULL || carry != 0) {
        int sum = 0;

        if(num1 != NULL) {
            sum += num1 -> val;
            num1 = num1 -> next;
        }

        if(num2 != NULL) {
            sum += num2 -> val;
            num2 = num2 -> next;
        }

        if(carry != 0) {
            sum += carry;
        }

        res -> next = new Node(sum % 10);
        carry = sum / 10;
        res = res -> next;
    }

    return ans -> next;
}

int main() {
    Node* num1 = new Node(2, new Node(4, new Node(3)));
    Node* num2 = new Node(5, new Node(6, new Node(4)));

    Node* sum = addNumbers(num1, num2);

    printList(sum);

    return 0;
}