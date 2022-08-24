// Here we have Two strings
// and we have to find the length of longest common substring among both strings

#include <iostream>
#include <vector>
using namespace std;

int maxLength(string str1, string str2) {
  int n = str1.size(), m = str2.size();
  vector<int> prev(m+1, 0), cur(m+1, 0);
  int ans = INT_MIN;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(str1[i-1] == str2[j-1]) {
        cur[j] = 1 + prev[j-1];
        ans = max(ans, cur[j]);
      } else {
        cur[j] = 0;
      }
    }
    prev = cur;
  }

  return ans;
}

int main() {
  string str1 = "abcjklp", str2 = "acjkp";

  cout << maxLength(str1, str2) << endl;

  return 0;
}