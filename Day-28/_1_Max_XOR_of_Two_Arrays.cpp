#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
  TrieNode* links[2];
  bool end = false;

  bool containsKey(int bit) {
    return (this -> links[bit] != NULL);
  }

  TrieNode* get(int bit) {
    return (this -> links[bit]);
  }

  void put(int bit, TrieNode* node) {
    this -> links[bit] = node;
  }

  bool isEnd() {
    return (this -> end);
  }

  void setEnd() {
    this -> end = true;
  }
};

class Trie {

  TrieNode* root;

  Trie() {
    root = new TrieNode();
  }

public:

  void insert(int num) {
    TrieNode* node = root;

    for(int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;

      if(!node -> containsKey(bit)) {
        node -> put(bit, new TrieNode());
      }

      node = node -> get(bit);
    }
  }

  int getMax(int num) {
    TrieNode *node = root;
    int maxNum = 0;
    for(int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;

      if(node -> containsKey(1 - bit)) {
        maxNum |= (1 << i);
        node = node -> get(1 - bit);
      } else {
        node = node -> get(bit);
      }

    }

    return maxNum;
  }

};

int maxXOR(vector<int>& arr1, vector<int>& arr2) {
  Trie trie;

  for(auto num : arr1) {
    trie.insert(num);
  }

  int maxRes = 0;

  for(auto num : arr2) {
    maxRes = max(maxRes, trie.getMax(num));
  }

  return maxRes;
}

int main() {
  vector<int> arr1 = {};
  vector<int> arr2 = {};

  cout << maxXOR(arr1, arr2) << endl;

  return 0;
}