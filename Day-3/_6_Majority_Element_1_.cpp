#include <iostream>
#include <vector>
using namespace std;

// We have to find the majority element of the array that appears n/2 times

// For this problem we can use Hashing and
// Solve it in Time - O(n) & Space - O(n)

// But here we are using Boyer Moore Voting Algorithm
// And this take Time - O(n) and Space - O(1)
int majorityElement(vector<int> arr) {
    int size = arr.size();
    int count = 0;
    int element = 0;

    for(int i = 0; i < size; i++) {
        if(count == 0) {
            element = arr[i];
        }
        if(element == arr[i]) {
            count++;
        } else {
            count--;
        }
    }

    return element;
}

int main() {
    cout << majorityElement({1, 2, 1, 2, 3, 4, 2, 2, 2, 2, 2, 4 , 4});

    return 0;
}