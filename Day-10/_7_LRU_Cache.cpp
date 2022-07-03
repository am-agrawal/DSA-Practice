#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int size;
    unordered_map<int, node*> map;

    LRUCache(int _size) {
        size = _size;
        head -> next = tail;
        tail -> prev = head;
    }

    void addnode(node* newnode) {
        node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletenode(node* delnode) {
        node* delprev = delnode -> prev;
        node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
        // delete delnode;
    }

    int get(int _key) {
        if(map.find(_key) != map.end()) {
            node* resnode = map[_key];
            int res = resnode -> val;
            map.erase(_key);
            deletenode(resnode);
            addnode(resnode);
            map[_key] = head -> next;

            return res;
        }

        return -1;
    }

    void put(int _key, int _val) {
        if(map.find(_key) != map.end()) {
            node* existingnode = map[_key];
            map.erase(_key);
        }
        if(map.size() == size) {
            map.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }

        addnode(new node(_key, _val));
        map[_key] = head -> next;
    }

};

int main() {
    LRUCache che(2);

    che.put(1, 1);
    che.put(2, 2);
    cout << che.get(1) << endl;
    che.put(3, 3);
    cout << che.get(2) << endl;
    che.put(4, 4);
    cout << che.get(1) << endl;
    cout << che.get(3) << endl;
    cout << che.get(4) << endl;


    return 0;
}