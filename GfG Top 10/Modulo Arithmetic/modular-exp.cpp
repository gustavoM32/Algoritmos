/*
    Modular Exponentiation
    Complexity: O(log y)
*/
#include <bits/stdc++.h>
using namespace std;

int modexp(int x, int y, int p) {
    int res = 1;
    x %= p;

    while (y > 0) {
        if (y % 2 == 1) res = (res * x) % p;
        x = (x * x) % p;
        y /= 2;
    }
    return res;
}

int main() {
    int x, y, p;
    cin >> x >> y >> p;
    cout << modexp(x, y, p) << endl;
    return 0;
}
