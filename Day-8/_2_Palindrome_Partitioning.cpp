#include <iostream>
#include <vector>
using namespace std;

// In this problem, we are given a palindrome string
// We have to partition the string into substring which are also palindrome

bool isValid(string s) {
    int l = 0;
    int h = s.length() - 1;
    while (l < h) {
        if(s[l++] != s[h--]) return false;
    }
    return true;
}

void partition(string s, int idx, vector<string>& ds, vector<vector<string>>& ans) {
    if(idx == s.size()) {
        if(ds.size() == 1) return;
        ans.push_back(ds);
        return;
    }
    for(int i = idx+1; i <= s.size(); i++) {
        string t = s.substr(idx, i - idx);
        if(isValid(t)) {
            ds.push_back(t);
            partition(s, i, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> palindromePartition(string s) {
    vector<vector<string>> ans;
    vector<string> ds;
    partition(s, 0, ds, ans);

    return ans;
}

int main() {
    vector<vector<string>> ans = palindromePartition("aabbaa");
    
    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}