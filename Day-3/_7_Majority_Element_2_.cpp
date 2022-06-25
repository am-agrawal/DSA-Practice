#include <iostream>
#include <vector>
using namespace std;

// We have to find those elements which appears n/3 times in array
// Here also we are using Boyer Moore's algorithm
vector<int> majorityElement(vector<int> arr) {
    int size = arr.size();
    int num1 = 0, count1 = 0;
    int num2 = 0, count2 = 0;

    for(auto el : arr) {
        if(el == num1) count1++;
        else if(el == num2) count2++;
        else if(count1 == 0) {
            num1 = el;
            count1 = 1;
        }
        else if(count2 == 0) {
            num2 = el;
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    vector<int> ans;
    count1 = count2 = 0;
    for(auto el : arr) {
        if(el == num1) count1++;
        if(el == num2) count2++;
    }
    if(count1 > size/3) ans.push_back(num1);
    if(count2 > size/3) ans.push_back(num2);

    return ans;
}

int main() {
    vector<int> r = majorityElement({1, 1, 1, 3, 3, 2, 2, 2});
    cout << "Num 1 : " << r[0] << endl;
    cout << "Num 2 : " << r[1] << endl;

    return 0;
}