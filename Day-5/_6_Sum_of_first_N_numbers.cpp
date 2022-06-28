#include <iostream>
using namespace std;

int sumOfN(int N) {
    if(N == 1) return 1;
    return N + sumOfN(N-1);
}

int main() {
    cout << sumOfN(3) << endl;

    return 0;
}