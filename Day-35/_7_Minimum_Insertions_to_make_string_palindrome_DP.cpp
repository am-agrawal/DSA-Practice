// Here we have a string
// and we have to find the minimum number of insertions to make the string palindrome

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxLength(string str1, string str2) {
  int n = str1.size(), m = str2.size();
  vector<int> prev(m+1, 0), cur(m+1, 0);

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(str1[i-1] == str2[j-1]) {
        cur[j] = 1 + prev[j-1];
      } else {
        cur[j] = max(prev[j], cur[j-1]);
      }
    }
    prev = cur;
  }

  return prev[m];
}

int LPS(string str1) {
  string str2 = str1;
  reverse(str2.begin(), str2.end());
  return maxLength(str1, str2);
}

int minInsertions(string s) {
    return s.size() - LPS(s);
}

int main() {
  string str = "zaabzaa";

  cout << minInsertions(str) << endl;

  return 0;
}