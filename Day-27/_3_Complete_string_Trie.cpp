#include <iostream>
#include <vector>
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

  // A complete string is a string where its all character has True flag
  // => String = "Aman"
  // In Trie, ["A", "Am", "Ama", "Aman"] all are present
  string completeString(vector<string>& strs) {

    for(auto str : strs) {
      this -> insert(str);
    }

    string res = "None";

    for(auto str : strs) {
      TrieNode* node = root;

      for(auto ch : str) {
        if(!node -> containsKey(ch)) break;

        node = node -> get(ch);
        if(!node -> isEnd()) break;
      }

      if((res.length() < str.length()) || (res.length() == str.length() && res < str)) {
        res = str;
      }

    }

    return res;
  }

};

int main() {
  Trie trie;

  vector<string> strs = {"n", "ninja", "ninj", "nin", "ni", "ninga"};

  cout << trie.completeString(strs) << endl;


  return 0;
}