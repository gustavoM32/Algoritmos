/*
    Matrix Exponentiation
    Complexity: O(log n)
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void multiply(ll a[3][3], ll b[3][3]) {
    ll res[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = res[i][j];
        }
    }
}

void power(ll res[3][3], ll base[3][3], ll e) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }
    while (e > 0) {
        if (e & 1) multiply(res, base);
        multiply(base, base);
        e /= 2;
    }
}

int getNthTerm(int n, int a, int b, int c) {
    ll baseCase[3] = {0, 1, 1};
    if (n < 3) return baseCase[n];
    ll f[3][3] = {{a, b, c}, {1, 0, 0}, {0, 1, 0}};
    ll expMat[3][3];
    power(expMat, f, n - 2);
    return expMat[0][0] * baseCase[2] +
           expMat[0][1] * baseCase[1] +
           expMat[0][2] * baseCase[0];
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << getNthTerm(n, a, b, c) << "\n";
    return 0;
}
