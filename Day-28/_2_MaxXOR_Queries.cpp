#include <iostream>
#include <vector>
#include <algorithm>

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
public:
  TrieNode* root;

  Trie() {
    root = new TrieNode();
  }

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

bool comp(vector<int> a, vector<int> b) {
  return a[1] < b[1];
}

// Queries => [X, A]
// For each query, We have to XOR X with every value lesser than or equal to A
// We will add i to every query
vector<int> maxXOR(vector<int>& arr, vector<vector<int>>& queries) {
  Trie trie;

  int N = queries.size();
  vector<int> res(N);

  for(int i = 0; i < N; i++) {
    queries[i].push_back(i);
  }

  sort(arr.begin(), arr.end());
  sort(queries.begin(), queries.end(), comp);

  int i = 0;
  for(auto query : queries) {
    while(i < N && arr[i] <= query[1]) {
      trie.insert(arr[i++]);
    }

    res[query[2]] = trie.getMax(query[0]);
  }

  return res;
}

int main() {
  vector<int> arr = {1, 3, 2, 5, 4};

  vector<vector<int>> queries = {
                                  {3, 4},
                                  {5, 2},
                                  {2, 5},
                                  {3, 1}
  };

  vector<int> res = maxXOR(arr, queries);

  for(auto x : res) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}