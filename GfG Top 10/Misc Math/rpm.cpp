/*
    Russian Peasant Multiplication
    Complexity: O(log b)
*/
#include <bits/stdc++.h>
using namespace std;

int mult(int a, int b) {
    int res = 0;
    while (b > 0) {
        if (b & 1) res += a;
        a = a << 1;
        b = b >> 1;
    }
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << mult(a, b) << endl;
    return 0;
}
