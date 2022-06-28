#include <iostream>
using namespace std;

void print(int N) {
    cout << N << endl;
    if(N == 1) return;
    print(N-1);
}

int main() {
    print(5);

    return 0;
}