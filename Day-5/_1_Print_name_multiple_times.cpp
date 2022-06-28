#include <iostream>
using namespace std;

void printName(string name, int cnt) {
    if(cnt == 0) return;
    cout << name << endl;
    printName(name, cnt-1);
}

int main() {
    printName("Aman", 5);

    return 0;
}