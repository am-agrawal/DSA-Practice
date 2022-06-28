#include <iostream>
using namespace std;

void print(int N, int cnt) {
    if(cnt != N) {
        print(N, cnt+1);
    }
    cout << cnt << endl;
}

int main() {
    print(5, 1);

    return 0;
}