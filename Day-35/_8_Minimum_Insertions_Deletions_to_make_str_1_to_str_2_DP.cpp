// Here we have Two Strings and we can delete or insert a character in string1 to convert it to string2
// And we have to find the minimum number of steps to do this

#include <iostream>
#include <vector>
using namespace std;

int LCS(string str1, string str2) {
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

int minSteps(string str1, string str2) {
  int cmnSub = LCS(str1, str2);
  return ((str1.length() - cmnSub) + (str2.length() - cmnSub));
}

int main() {
  string str1 = "hello", str2 = "neller";

  cout << minSteps(str1, str2) << endl;

  return 0;
}