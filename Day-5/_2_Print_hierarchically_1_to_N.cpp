#include <iostream>
using namespace std;

void print(int N, int cnt) {
    cout << cnt <<endl;
    if(cnt == N) return;
    print(N, cnt+1);
}

int main() {
    print(5, 1);

    return 0;
}