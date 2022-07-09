#include "../DataStructureClass.hpp"

#define NWR NodeWithRandom

NWR* makeDeepCopy(NWR* head) {
    NWR* temp = head;
    while (temp != NULL) {
        temp -> next = new NWR(temp -> val, temp -> next);
        temp = temp -> next -> next;
    }
    temp = head;
    while (temp != NULL) {
        temp -> next -> random = (temp -> random == NULL) ? NULL : temp -> random -> next;
        temp = temp -> next -> next;
    }
    temp = head -> next;
    while(temp != NULL && temp -> next != NULL) {
        temp -> next = temp -> next -> next;
        temp = temp -> next;
    }

    return head -> next;
}

int main() {
    NWR* node = new NWR(1, new NWR(2, new NWR(3, new NWR(4))));
    node -> random = node -> next -> next -> next;
    node -> next -> random = node;
    node -> next -> next -> random = NULL;
    node -> next -> next -> next -> random = node -> next;

    printListOfRandomPtr(node);
    cout << endl;

    NWR* head = makeDeepCopy(node);
    printListOfRandomPtr(head);

    return 0;
}