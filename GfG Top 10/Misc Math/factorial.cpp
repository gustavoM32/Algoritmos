/*
    Factorial of large number
    Complexity: O(log(ceil(n! / 1e10)) * n) 
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010
#define ll long long
#define LLP 10000000000 // 10 0's

void fat(int n) {
    ll res[MAXN];
    for (int i = 0; i < MAXN; i++) {
        res[i] = 0;
    }
    res[0] = 1;
    int size = 1;
    ll carry;
    for (int i = 2; i <= n; i++) {
        carry = 0;
        for (int j = 0; j < size; j++) {
            res[j] *= i;
            res[j] += carry;
            carry = res[j] / LLP;
            res[j] %= LLP;
        }
        if (carry > 0) {
            res[size] = carry;
            size++;
        }
    }
    cout << res[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        printf("%010lld", res[i]);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    fat(n);
    return 0;
}
