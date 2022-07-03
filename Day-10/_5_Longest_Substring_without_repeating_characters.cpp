#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// Time => O(2n) + O(logn) & Space => O(n)

// int longestSubstring(string s) {
//     set<char> hashSet;
//     int n = s.length();
//     int l = 0, r = 0;

//     int maxLen = 1;
//     int currLen = 0;

//     while (r < n) {
//         r++;
//         currLen++;
//         while(hashSet.count(s[r])) {
//             hashSet.erase(s[l]);
//             l++;
//             currLen--;
//         }
//         hashSet.insert(s[r]);

//         maxLen = max(maxLen, currLen);
//     }

//     return maxLen;
// }

int longestSubstring(string s) {
    unordered_map<int, int> mp;

    int l = 0, r = 0;
    int n = s.size();
    int len = 0;

    while(r < n) {
        if(mp.find(s[r]) != mp.end()) {
            l = max(mp[s[r]] + 1, l);
        }

        mp[s[r]] = r;
        
        len = max(len, (r - l + 1));
        r++;
    }

    return len;
}

int main() {
    string s = "abcaabcdba";
    cout << longestSubstring(s) << endl;

    return 0;
}