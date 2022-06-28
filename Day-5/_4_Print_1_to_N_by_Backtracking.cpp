#include <iostream>
using namespace std;

void print(int N) {
    if(N != 1) {
        print(N - 1);
    }
    cout << N << endl;
}

int main() {
    print(5);

    return 0;
}