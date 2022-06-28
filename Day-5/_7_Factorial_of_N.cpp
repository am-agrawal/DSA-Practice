#include <iostream>
using namespace std;

int factorial(int N) {
    if(N == 1) return 1;
    return N * factorial(N - 1);
}

int main() {
    cout << factorial(5) << endl;

    return 0;
}