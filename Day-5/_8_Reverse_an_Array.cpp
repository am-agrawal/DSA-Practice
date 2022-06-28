#include <iostream>
using namespace std;

// void reverse(string &s, int l, int h) {
//     if(l >= h) return;
//     swap(s[l], s[h]);
//     reverse(s, l+1, h-1);
// }

void reverse(string &s, int i, int N) {
    if(i >= (N/2)) return;
    swap(s[i], s[N-i-1]);
    reverse(s, i+1, N);
}

int main() {
    string s = "AMAN";
    reverse(s, 0, s.size());
    cout << s << endl;
    
    return 0;
}