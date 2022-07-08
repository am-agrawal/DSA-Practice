#include <iostream>
using namespace std;

// Linked List Data-Structure
class Node {
public:
    int val;
    Node* next;

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
    Node(int _val) {
        val = _val;
        next = NULL;
    }
};

// To print the List
void printList(Node* head) {
    Node* node = head;
    while(node != NULL) {
        cout << node -> val << " -> ";
        node = node -> next;
    }
    cout << "NULL" << endl;
}