#include <iostream>
#include <string>

using namespace std;

// Node for Trie Data Structure
class TrieNode {
public:
    TrieNode* links[26] = {NULL};
    bool end = false;

    bool containsKey(char ch) {
        return (this -> links[ch - 'a'] != NULL);
    }

    void put(char ch, TrieNode* node) {
        this -> links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return (this -> links[ch - 'a']);
    }

    bool isEnd() {
        return (this -> end);
    }

    void setEnd() {
        this -> end = true;
    }
};

class Trie {
public:
  TrieNode* root;

  Trie() {
    root = new TrieNode();
  }

  void insert(string word) {
    TrieNode* node = root;

    for(auto ch : word) {
      if(!node -> containsKey(ch)) {
        node -> put(ch, new TrieNode());
      }

      node = node -> get(ch);
    }

    node -> setEnd();
  }

  bool search(string word) {
    TrieNode* node = root;

    for(auto ch : word) {
      if(!node -> containsKey(ch)) return false;

      node = node -> get(ch);
    }

    return (node -> isEnd());
  }

  bool startsWith(string prefix) {
    TrieNode* node = root;

    for(auto ch : prefix) {
      if(!node -> containsKey(ch)) return false;

      node = node -> get(ch);
    }

    return true;
  }

};

int main() {
  Trie trie;

  trie.insert("Aman");

  cout << trie.search("Aman") << endl;
  cout << trie.search("Am") << endl;
  cout << trie.startsWith("Am") << endl;


  return 0;
}