#include <iostream>
#include <vector>
#include <string>
using namespace std;

string permutationAtK(int n, int k) {
    string ans = "";

    int fact = 1;
    vector<int> numbers;
    for(int i = 1; i < n; i++) {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k--;
    while(true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + (k / fact));
        if(numbers.size() == 0) break;
        k = k % fact;
        fact = fact / numbers.size();
    }

    return ans;
}

int main() {
    cout << permutationAtK(4, 17);

    return 0;
}