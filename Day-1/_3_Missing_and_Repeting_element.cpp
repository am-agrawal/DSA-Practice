#include <iostream>
#include <vector>
using namespace std;

// Time - O(n) & Space - O(n)
// Using Hashing
vector<int> missingAndRepeting(vector<int> arr) {
    int size = arr.size();
    vector<int> freq(size + 1, 0);
    for(int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }
    int miss, repet;
    for(int i = 1; i <= size; i++) {
        if(freq[i] == 0) miss = i;
        if(freq[i] == 2) repet = i;
    }
    
    return {miss, repet};
}

// we can do this by using XOR and 2 buckets also

int main() {
    vector<int> res = missingAndRepeting({1, 3, 6, 1, 4, 2});
    cout << "Missing : " << res[0] << endl << "Repeting : " << res[1] << endl;

    return 0;
}