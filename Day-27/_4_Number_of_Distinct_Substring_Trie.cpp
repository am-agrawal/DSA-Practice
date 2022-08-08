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

// return no. of distinct substring in string including empty substring
int countSubstring(string word) {
  TrieNode* root = new TrieNode();
  int cnt = 0;

  for(int i = 0; i < word.length(); i++) {
    TrieNode* node = root;
    for(int j = i; j < word.length(); j++) {
      if(!node -> containsKey(word[j])) {
        cnt++;
        node -> put(word[j], new TrieNode());
      }
      node = node -> get(word[j]);
    }
  }

  return cnt + 1;
}

int main() {
  string word = "abab";

  cout << countSubstring(word) << endl;

  return 0;
}