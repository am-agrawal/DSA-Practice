#include <iostream>
using namespace std;

double pow(int x, int n) {
    double ans = 1.0;
    long nn = n;
    if(nn < 0) nn *= -1;
    while(nn > 0) {
        if((nn % 2) == 0) {
            x *= x;
            nn /= 2;
        } else {
            ans *= x;
            nn--;
        }
    }
    if(n < 0) {
        ans = (double)(1.0) / (double)(ans);
    }

    return ans;
}

int main() {
    double res = pow(2, -2);
    cout << "Pow(2, -2) : " << res << endl;

    return 0;
}