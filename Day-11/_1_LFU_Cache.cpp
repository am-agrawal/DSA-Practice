#include <iostream>
#include <map>
using namespace std;

struct Node {
    int key, val, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* temp  = head -> next;
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
        temp -> prev = node;
        size++;
    }

    void removeNode(Node* delnode) {
        Node* delprev = delnode -> prev;
        Node* delnext = delnode -> next;
        delnext -> prev = delprev;
        delprev -> next = delnext;
        size--;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    void updateFreqListMap(Node* node) {
        keyNode.erase(node -> key);
        freqListMap[node -> cnt] -> removeNode(node);
        if(node -> cnt == minFreq && freqListMap[node -> cnt] -> size == 0) {
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        if(freqListMap.find(node -> cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node -> cnt + 1];
        }
        node -> cnt += 1;
        nextHigherFreqList -> addFront(node);
        freqListMap[node -> cnt] = nextHigherFreqList;
        keyNode[node -> key] = node;
    }

    int get(int _key) {
        int _val = -1;
        if(keyNode.find(_key) != keyNode.end()) {
            Node* node = keyNode[_key];
            int _val = node -> val;
            updateFreqListMap(node);
        }
        return _val;
    }

    void put(int _key, int _val) {
        if(maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(_key) != keyNode.end()) {
            Node* node = keyNode[_key];
            node -> val = _val;
            updateFreqListMap(node);
        }
        else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list -> tail -> prev -> key);
                freqListMap[minFreq] -> removeNode(list -> tail -> prev);
                curSize--;
            }
            curSize++;

            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(_key, _val);
            listFreq -> addFront(node);
            keyNode[_key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};
