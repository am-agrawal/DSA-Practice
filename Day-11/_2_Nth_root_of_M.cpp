#include <iostream>
#include <vector>
using namespace std;

double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1; i <= n; i++) {
        ans *= number;
    }
    return ans;
}

double nthRoot(int n, int m) {
    double l = 1, h = m;
    double mid;
    double eps = 1e-6;
    while((h - l) > eps) {
        mid = (l + h) / 2.0;

        if(multiply(mid, n) < m) {
            l = mid;
        } else {
            h = mid;
        }
    }

    // cout << l << " " << h << endl;

    return l;
}


int main() {
    int n = 3, m = 27;

    cout << nthRoot(n, m);

    return 0;
}