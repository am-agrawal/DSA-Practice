// Here we an array of strings as words
// And we have to find the length of Longest String Chain
// In a string chain, words a & b, b will have an extra character than a
// Other characters should match within a

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(string& a, string& b) {
  return a.size() < b.size();
}

bool check(string& a, string& b) {
  int n = a.size(), m = b.size();
  if(n + 1 != m) return false;
  int i = 0, j = 0, diff = 0;
  while(i < n && j < m) {
    if(a[i] == b[j]) { i++; j++; }
    else { diff++; j++; }
  }
  if(i < n) diff += (n - i);
  if(j < m) diff += (m - j);
  return diff == 1;
}

// Time => O(n * n * k) [k is length of longest word in words]
// Space => O(3n) ~ O(n)
int LSC(vector<string>& words) {
  int n = words.size();
  sort(words.begin(), words.end(), comp);
  int res = 0, resInd = -1;
  vector<int> freq(n, 1), hash(n);
  vector<string> ans;
  for(int i = 0; i < n; i++) {
    hash[i] = i;
    for(int j = 0; j < i; j++) {
      if(check(words[j], words[i]) && freq[j] + 1 > freq[i]) {
        freq[i] = freq[j] + 1;
        hash[i] = j;
      }
    }
    if(freq[i] > res) {
      res = freq[i];
      resInd = i;
    }
  }

  int k = res;
  while(k--) {
    ans.push_back(words[resInd]);
    resInd = hash[resInd];
  }

  reverse(ans.begin(), ans.end());
  cout << "Longest String Chain : ";
  for(auto i : ans) cout << i << " ";
  cout << endl;

  return res;
}

int main() {
  vector<string> words = {"a", "bcd", "ba", "xa", "bcda", "bb", "bca"};

  cout << LSC(words) << endl;

  return 0;
}