#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
  TrieNode *links[26] = {NULL};
  int ew = 0, cp = 0;

	bool containsKey(char ch)	{
		return (this -> links[ch - 'a'] != NULL);
	}

	void put(char ch, TrieNode *node) {
		this -> links[ch - 'a'] = node;
	}

	TrieNode* get(char ch) {
		return (this -> links[ch - 'a']);
	}

	void increasePrefix() {
		this -> cp++;
	}

	bool isEnd() {
		return (this -> ew != 0);
	}

	void setEnd() {
		this -> ew++;
	}

	int endCount() {
		return (this -> ew);
	}

	int prefixCount() {
		return (this -> cp);
	}

	void reducePrefix() {
		this -> cp--;
	}

	void deleteEnd() {
		this -> ew--;
	}

};

class Trie {
public:
	TrieNode *root;

	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode *node = root;

		for(auto ch : word) {
			if(!node -> containsKey(ch)) {
				node -> put(ch, new TrieNode());
			}

			node = node -> get(ch);

			node -> increasePrefix();
		}

		node -> setEnd();
	}

	int countWordsEqualTo(string word) {
		TrieNode *node = root;

		for(auto ch : word) {
			if(!node -> containsKey(ch)) {
				return 0;
			}

			node = node -> get(ch);
		}

		return (node -> endCount());
	}

	int countWordsWithPrefix(string prefix) {
		TrieNode *node = root;

		for(auto ch : prefix) {
			if(!node -> containsKey(ch)) {
				return 0;
			}

			node = node -> get(ch);
		}

		return (node -> prefixCount());
	}

	void erase(string word) {
		TrieNode *node = root;

		for(auto ch : word) {
			if(node -> containsKey(ch)) {
				node = node -> get(ch);
				node -> reducePrefix();
			} else {
				return;
			}
		}

		node -> deleteEnd();
	}

};

int main() {
	Trie trie;

	trie.insert("Aman");
	trie.insert("Aman");
	trie.insert("Aman");
	trie.insert("Am");

	cout << trie.countWordsEqualTo("Aman") << endl;
	cout << trie.countWordsWithPrefix("Aman") << endl;
	cout << trie.countWordsWithPrefix("Am") << endl;

	return 0;
}